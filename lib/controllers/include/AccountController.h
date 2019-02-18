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


constexpr char NOT_LOGIN_MESSAGE[] = "You are not logged in!";

constexpr char LOGOUT_MESSAGE[] = "You have logged out";

constexpr char ALREADY_LOGIN_MESSAGE[] = "You are logged in - logout to preform this command";

constexpr char LOGOUT_BEFORE_REGISTER_MESSAGE[] = "You are logged in - please logout to register";

constexpr char ESCAPE_WHILE_REGISTERING_MESSAGE[] = "You have exited out of the registration process\n";

constexpr char LOGGING_IN_ESCAPE_MESSAGE[] = "You have exited out of the login process\n";

constexpr char ESCAPE_WHILE_NOT_LOGIN_MESSAGE[] = "You are not submitting any Account information currently";

#include <unordered_map>
#include <CommandProcessor.h>

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

    void onCompleteLogin(function_ptr fnPtr);

    pair<bool, Message> respondToMessage(const Message& message);

    void connectClient(const Connection &connection);

    void disconnectClient(const Connection &connection);

private:
    AccountService userService;
    function_ptr onLoginFunction;
};

#endif // WEBSOCKETNETWORKING_CLIENTMANAGER_H
