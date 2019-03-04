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

#include "User.h"
#include "AccountService.h"
#include "AbstractController.h"

constexpr char NOT_LOGIN_MESSAGE[] = "You are not logged in!";
constexpr char LOGOUT_MESSAGE[] = "You have logged out";
constexpr char ALREADY_LOGIN_MESSAGE[] = "You are logged in - logout to preform this command";
constexpr char LOGOUT_BEFORE_REGISTER_MESSAGE[] = "You are logged in - please logout to register";
constexpr char ESCAPE_WHILE_REGISTERING_MESSAGE[] = "You have exited out of the registration process\n";
constexpr char LOGGING_IN_ESCAPE_MESSAGE[] = "You have exited out of the login process\n";
constexpr char ESCAPE_WHILE_NOT_LOGIN_MESSAGE[] = "You are not submitting any Account information currently";

class AccountController : public AbstractController {
public:
    AccountController() : accountService() {}

    Message startLogin(const Message& message);

    Message startRegister(const Message& message);

    Message logoutUser(const Message& message);

    Message escapeLogin(const Message& message);

    Message respondToMessage(const Message& message) override;

private:
    AccountService accountService;
};

#endif // WEBSOCKETNETWORKING_CLIENTMANAGER_H
