//
// Created by vinshit on 24/01/19.
//

#ifndef WEBSOCKETNETWORKING_CLIENTMANAGER_H
#define WEBSOCKETNETWORKING_CLIENTMANAGER_H

#include "Server.h"

using networking::Connection;
using networking::Message;
using std::string;


class ClientManager {

public:
  virtual Message promptLogin(Connection connection);
  virtual bool addConnection(Connection connection);
  virtual bool removeConnection(Connection connection);
  virtual bool isLoggedIn(Connection connection);
};


#endif //WEBSOCKETNETWORKING_CLIENTMANAGER_H
