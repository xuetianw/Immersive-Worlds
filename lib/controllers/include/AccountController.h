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

static const char *const NOT_LOGIN_MESSAGE = "You are not logged in!";

static const char *const LOGOUT_MESSAGE = "You have logged out";

static const char *const ALREADY_LOGIN_MESSAGE = "You are logged in - logout to preform this command";

static const char *const LOGOUT_BEFORE_REGISTER_MESSAGE = "You are logged in - please logout to register";

static const char *const ESCAPE_WHILE_REGISTERING_MESSAGE = "You have exited out of the registration process\n";

static const char *const LOGGING_IN_ESCAPE_MESSAGE = "You have exited out of the login process\n";

#include <unordered_map>

#include "Server.h"
#include "AccountService.h"
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
    AccountService userService;
};

#endif // WEBSOCKETNETWORKING_CLIENTMANAGER_H
