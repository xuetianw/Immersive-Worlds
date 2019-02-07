///////////////////////////////////////////////////////////////////////////////////////////////////
// Authors: Asim, Nirag, Vincent
// Created On: January 26, 2019
//
// The file implements ClientManager which is responsible for managing clients connected to the
// server and users registered with the application.
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
    auto userIter = _connectedUserMap.find(message.connection.id);
    string response;

    if (userIter != _connectedUserMap.end()) {
        User &user = userIter->second;
        Message responseMessage = user.handleInput(message);
        if (user.isSubmittingRegistration()) {
            _userData.insert(std::make_pair(user.getUsername(), user.getPassword()));
            response = "Account Created!";
            //Reset state;
            user = User{};
        } else if (user.isRegistering() && userExists(user)){
            response = "Username already exists";
            user.promptRegistration();
            user.handleInput(message);
        } else if (user.isSubmittingLoginInfo()){
            if(isLoginCredentialsCorrect(user)) {
                user.set_state(new LoggedInState);
                response = "Successfully logged in!";
            } else {
                response = "Login Unsuccessful\nPlease enter your username again:";
                user.promptLogin();
            }
        } else if (!user.isLoggedIn()) {
            return responseMessage;
        }
    }
    return Message{message.connection, response};
}

///////////////////////////////////////////////////////////////////////////////////////////////////
bool ClientManager::isLoginCredentialsCorrect(User &user) {
    auto userIter = _userData.find(user.getUsername());
    return userIter != _userData.end() && userIter->second == user.getPassword();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
bool ClientManager::isLoggedIn(const Connection &connection) {
    auto userIter = _connectedUserMap.find(connection.id);
    return (userIter != _connectedUserMap.end() && userIter->second.isLoggedIn());
}

///////////////////////////////////////////////////////////////////////////////////////////////////
Message ClientManager::promptLogin(Message &message) {
    auto userIter = _connectedUserMap.find(message.connection.id);
    User &user = userIter->second;
    user.promptLogin();
    return user.handleInput(message);
}

Message ClientManager::promptRegister(Message &message) {
    auto userIter = _connectedUserMap.find(message.connection.id);
    User &user = userIter->second;
    user.promptRegistration();
    return user.handleInput(message);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
Message ClientManager::logoutClient(const Connection &connection) {
    string response;
    if (isLoggedIn(connection)) {
        auto userIter = _connectedUserMap.find(connection.id);
        User &user = userIter->second;
        user = User{};
        return Message{connection.id, "User successfully logged out!\n"};
    }
    return Message{connection.id, "User not logged in!\n"};

}

///////////////////////////////////////////////////////////////////////////////////////////////////
bool ClientManager::connectClient(const Connection &connection) {
    if (_connectedUserMap.find(connection.id) == _connectedUserMap.end()) {
        User user;
        _connectedUserMap.insert(std::make_pair(connection.id, user));
        return true;
    }
    std::cout << "This connection is not unique: " << connection.id << endl;
    return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void ClientManager::disconnectClient(const Connection &connection) {
    _connectedUserMap.erase(connection.id);
}

////////////////////////////////////////////////////////////////////////////////////////////////
Message ClientManager::escapeLogin(const Message &message) {
    User &user = _connectedUserMap.find(message.connection.id)->second;
    stringstream response;
    if (user.isLoggingIn() || user.isRegistering()){
        if (user.isRegistering()) {
            response << "You have exited out of the registration process\n" << message.connection.id;
        } else {
            response << "You have exited out of the login process\n" << message.connection.id;
        }
        user = User{};
    } else {
        response << "You are not submitting any Account information currently";
    }
    return Message{message.connection.id, response.str()};
}



