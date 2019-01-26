//
// Created by vinshit on 24/01/19.
//

#include <iostream>
#include <ClientManager.h>

#include "ClientManager.h"


bool findUserAccount(User user){
        return true;}


Message ClientManager::promptLogin(uintptr_t connection_id, string message){
  auto found_connection = connected_users.find(connection_id);
  User &foundUser = found_connection->second;

  if(foundUser.state == State::CONNECTED){
    foundUser.username = message;
    foundUser.state = State::LOGGING_IN_;
    return Message{connection_id, "Please enter your Password:"};
  }
  if(foundUser.state == State::LOGGING_IN_) {
    foundUser.password = connection_id;
    //TODO: Implement findUserAccountusers to login
    if (findUserAccount(foundUser)) {
      foundUser.state = State::LOGGED_IN;
      return Message{connection_id, "Sucessfully logged in!:"};
    }
    else {
      foundUser.state = State::CONNECTED;
      return Message{connection_id, "Login Unsucessfull"};
    }
  }

  return Message{connection_id, "Sucessfully Logged In."};
}

bool ClientManager::addConnection(uintptr_t connection_id){
  auto found_connection = connected_users.find(connection_id);
  if(found_connection == connected_users.end()){
    User newUser{State::CONNECTED};
    connected_users.insert(std::pair(connection_id, newUser));
    return true;
  } else {
    std::cout << "This connection is not unique: " << connection_id << "\n";
    return false;
  }
}

void ClientManager::removeConnection(uintptr_t connection_id){
  connected_users.erase(connection_id);
}

bool ClientManager::isLoggedIn(uintptr_t connection_id){
  auto found_connection = connected_users.find(connection_id);
  if(found_connection == connected_users.end()){
    return false;
  } else {
    User foundUser = found_connection->second;
    return !(foundUser.state != State::LOGGED_IN);
  }
}

ClientManager::ClientManager() {}

