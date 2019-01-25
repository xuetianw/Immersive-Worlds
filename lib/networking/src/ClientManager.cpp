//
// Created by vinshit on 24/01/19.
//

#include <iostream>
#include "ClientManager.h"
enum class State{
  LOGGED_IN,
  CONNECTED,
  LOGGING_IN_
};

struct User{
  string username;
  string password;
  string serialId;
  State state;

  User( State state) : username(""), password(""),state(state) {}
};

bool findUserAccount(User user){
        return true;}

class ClientManagerImpl: public ClientManager{
private:
  std::unordered_map<uintptr_t, User > connected_users;

public:
  Message promptLogin(uintptr_t connection_id, string message){
    auto found_connection = connected_users.find(connection_id);
    User foundUser = found_connection->second;

    if(foundUser.state == State::CONNECTED){
      foundUser.username = message;
      foundUser.state = State::LOGGING_IN_;
      return Message{connection_id, "Password:"};
    }
    if(foundUser.state == State::LOGGING_IN_) {
      foundUser.password = connection_id;
      //TODO: Implement findUserAccountusers
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
  bool addConnection(uintptr_t connection_id){
    auto found_connection = connected_users.find(connection_id);
    if(found_connection == connected_users.end()){
      connected_users.insert(std::pair(connection_id,User{State::CONNECTED}));
      return true;
    } else {
      std::cout << "This connection is not unique: " << connection_id << "\n";
      return false;
    }
  }

  bool removeConnection(uintptr_t connection_id){

  }

  bool isLoggedIn(uintptr_t connection_id){
    auto found_connection = connected_users.find(connection_id);
    if(found_connection == connected_users.end()){
      return false;
    } else {
      User foundUser = found_connection->second;
      return !(foundUser.state != State::LOGGED_IN);
    }
  }
};
