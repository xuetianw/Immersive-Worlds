//
// Created by asim on 07/02/19.
//

#ifndef WEBSOCKETNETWORKING_USERSERVICE_H
#define WEBSOCKETNETWORKING_USERSERVICE_H

#include "Server.h"
#include "UserState.h"

using Message = networking::Message;
using Connection = networking::Connection;
using ConnectionHasher = networking::ConnectionHasher;

class UserService {
public:
    Message getResponse(Message message);

    void connect(const Connection &connection);

    void disconnectClient(const Connection &connection);

private:
    // A map to store currently registered users
    std::unordered_map<Connection, User, ConnectionHasher> _connectedUserMap;

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
