//
// Created by vinshit on 24/01/19.
//

#include "ClientManager.h"

class ClientManagerImpl: public ClientManager{
private:
public:
  Message promptLogin(Connection connection){

  return Message{connection, "Sucessfully Logged In."};
}
  bool addConnection(Connection connection){


  }
  bool removeConnection(Connection connection){

  }

  bool isLoggedIn(Connection connection){

  }
};
