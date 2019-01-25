//
// Created by vinshit on 24/01/19.
//

#ifndef WEBSOCKETNETWORKING_CLIENTMANAGER_H
#define WEBSOCKETNETWORKING_CLIENTMANAGER_H


#include "User.h"
#include "Server.h"

using networking::Connection;
using networking::Message;

class ClientManager {
private:
  //TODO MAKE THIS A MAP!
  std::deque<User> users;
public:
  virtual Message promptLogin(Connection connection);
  virtual bool addConnection(Connection connection);
  virtual bool removeConnection(Connection connection);
  virtual bool isLoggedIn(Connection connection);
};


#endif //WEBSOCKETNETWORKING_CLIENTMANAGER_H
