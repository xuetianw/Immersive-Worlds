//
// Created by asim on 08/02/19.
//

#ifndef WEBSOCKETNETWORKING_SERVICE_H
#define WEBSOCKETNETWORKING_SERVICE_H

#include "Server.h"
#include <string>

using Message = networking::Message;
using Connection = networking::Connection;

class Service {
public:
    virtual ~Service() = default;

    virtual Message updateUserState(const Message &message) { return Message {}; }

    virtual void connect(const Connection &connection) { }

    virtual void disconnectClient(const Connection& connection) { }

    virtual bool isLoggedIn(const Connection& connection) { return false; }

protected:
    Service() = default;
};

#endif //WEBSOCKETNETWORKING_SERVICE_H
