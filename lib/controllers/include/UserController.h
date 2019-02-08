///////////////////////////////////////////////////////////////////////////////////////////////////
// Authors: Asim, Nirag, Vincent
// Created On: January 26, 2019
//
// This file defines the interface for UserController.
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef WEBSOCKETNETWORKING_CLIENTMANAGER_H
#define WEBSOCKETNETWORKING_CLIENTMANAGER_H

#include <unordered_map>

#include "Server.h"
#include "Command.h"
#include "UserService.h"

using Connection = networking::Connection;
using ConnectionHasher = networking::ConnectionHasher;
using Message = networking::Message;
using string = std::string;

class UserController {
public:
    UserController() : userService() {};

    Message handleCommand(Command *cmd, const Message& message);

    bool isLoggedIn(const Connection &connection);

    void connectClient(const Connection &connection);

    void disconnectClient(const Connection &connection);

private:
    UserService userService;
};

#endif // WEBSOCKETNETWORKING_CLIENTMANAGER_H
