///////////////////////////////////////////////////////////////////////////////////////////////////
// Authors: Asim, Nirag, Vincent
// Created On: January 26, 2019
//
// The file implements ClientManager which is responsible for managing clients
// connected to the server and users registered with the application.
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include <sstream>
#include <unistd.h>

#include "ClientManager.h"
#include "User.h"

using namespace std;

//////////////////////////////////////////////PUBLIC///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
Message ClientManager::handleInput(Message &message) {
  auto userIter = _connectedUserMap.find(message.connection);
  string response;

  if (userIter == _connectedUserMap.end()) {
    return Message{message.connection, response};
  }

  User &user = userIter->second;
  Message responseMessage = user.handleInput(message);
  if (user.isSubmittingRegistration()) {
    _userData.insert(std::make_pair(user.getUsername(), user.getPassword()));
    responseMessage.text = "Account Created!";
    // Reset state;
    user.promptLogin();
  } else if (user.isRegistering() && userExists(user)) {
    responseMessage.text = "Username already exists";
    user.promptRegistration();
    user.handleInput(message);
  } else if (user.isSubmittingLoginInfo()) {
    if (isLoginCredentialsCorrect(user)) {
      user.setState(new LoggedInState);
      responseMessage.text = "Successfully logged in!";
    } else {
      responseMessage.text =
          "Login Unsuccessful\nPlease enter your username again:";
      user.promptLogin();
    }
  }
  return responseMessage; //
}

///////////////////////////////////////////////////////////////////////////////////////////////////
bool ClientManager::isLoginCredentialsCorrect(User &user) {
  auto userIter = _userData.find(user.getUsername());
  return userIter != _userData.end() && userIter->second == user.getPassword();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
bool ClientManager::isLoggedIn(const Connection &connection) {
  auto userIter = _connectedUserMap.find(connection);
  return (userIter != _connectedUserMap.end() && userIter->second.isLoggedIn());
}

///////////////////////////////////////////////////////////////////////////////////////////////////
Message ClientManager::promptLogin(Message &message) {
  auto userIter = _connectedUserMap.find(message.connection);
  User &user = userIter->second;
  user.promptLogin();
  return user.handleInput(message);
}

Message ClientManager::promptRegister(Message &message) {
  auto userIter = _connectedUserMap.find(message.connection);
  User &user = userIter->second;
  user.promptRegistration();
  return user.handleInput(message);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
Message ClientManager::logoutClient(const Connection &connection) {
  string response;
  if (isLoggedIn(connection)) {
    auto userIter = _connectedUserMap.find(connection);
    User &user = userIter->second;
    user = User{};
    return Message{connection.id, "User successfully logged out!\n"};
  }
  return Message{connection.id, "User not logged in!\n"};
}

///////////////////////////////////////////////////////////////////////////////////////////////////
bool ClientManager::connectClient(const Connection &connection) {
  if (_connectedUserMap.find(connection) == _connectedUserMap.end()) {
    User user;
    _connectedUserMap.insert(std::make_pair(connection, user));
    return true;
  }
  std::cout << "This connection is not unique: " << connection.id << endl;
  return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void ClientManager::disconnectClient(const Connection &connection) {
  _connectedUserMap.erase(connection);
}

////////////////////////////////////////////////////////////////////////////////////////////////
Message ClientManager::escapeLogin(const Message &message) {
  User &user = _connectedUserMap.find(message.connection)->second;
  stringstream response;
  if (user.isLoggingIn() || user.isRegistering()) {
    if (user.isRegistering()) {
      response << "You have exited out of the registration process\n"
               << message.connection.id;
    } else {
      response << "You have exited out of the login process\n"
               << message.connection.id;
    }
    user = User{};
  } else {
    response << "You are not submitting any Account information currently";
  }
  return Message{message.connection.id, response.str()};
}
