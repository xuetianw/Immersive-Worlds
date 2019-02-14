///////////////////////////////////////////////////////////////////////////////////////////////////
// Authors: Asim, Nirag, Vincent
// Created On: January 26, 2019
//
// This file defines the interface for AccountController.
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
#include "AbstractController.h"

using Connection = networking::Connection;
using ConnectionHasher = networking::ConnectionHasher;
using Message = networking::Message;
using string = std::string;

class AccountController : public AbstractController {
public:
    AccountController() : userService() {};

    Message startLogin(Message& message);

    Message startRegister(Message& message);

    Message logoutUser(Message& message);

    Message escapeLogin(Message& message);

    pair<bool, Message> respondToMessage(const Message& message);

    void connectClient(const Connection &connection);

    void disconnectClient(const Connection &connection);

private:
    UserService userService;
};

#endif // WEBSOCKETNETWORKING_CLIENTMANAGER_H
