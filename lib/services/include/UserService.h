//
// Created by asim on 07/02/19.
//

#ifndef WEBSOCKETNETWORKING_USERSERVICE_H
#define WEBSOCKETNETWORKING_USERSERVICE_H

#include "Server.h"
#include "UserState.h"
#include "Service.h"

using Message = networking::Message;
using Connection = networking::Connection;
using ConnectionHasher = networking::ConnectionHasher;

class UserService : public Service {
public:
    Message updateUserState(const Message &message) override;

    void connect(const Connection &connection) override;

    void disconnectClient(const Connection& connection) override;

    bool isLoggedIn(const Connection& connection) override;

private:
    // A map to store currently registered users
    std::unordered_map<Connection, User, ConnectionHasher> _connectedUserMap;

    StateTransitions transitions;

    // Mock dummy usernames and passwords for testing until database is added
    // TODO: Remove the mock usernames and passwords once database is added
    std::unordered_map<string, string> _userData{
            {"John", "password123*"},
            {"Rex", "admin12345"},
            {"Alex", "myPassword!"},
            {"Garfield", "Pwd15081967@merci"}
    };
};

#endif //WEBSOCKETNETWORKING_USERSERVICE_H
