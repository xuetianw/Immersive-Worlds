//
// Created by vinshit on 24/01/19.
//

#ifndef WEBSOCKETNETWORKING_CLIENTMANAGER_H
#define WEBSOCKETNETWORKING_CLIENTMANAGER_H

#include "Server.h"

using networking::Connection;
using networking::Message;
using std::string;

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

class ClientManager {

public:
  virtual Message promptLogin(uintptr_t connection_id, string message);
  virtual bool addConnection(uintptr_t connection_id);
  virtual void removeConnection(uintptr_t connection_id);
  virtual bool isLoggedIn(uintptr_t connection_id);

  ClientManager();

private:
  friend class ClientManagerImpl;
  std::unordered_map<uintptr_t, User > connected_users;
};


#endif //WEBSOCKETNETWORKING_CLIENTMANAGER_H
