///////////////////////////////////////////////////////////////////////////////////////////////////
// Authors: Asim, Nirag, Vincent
// Created On: January 26, 2019
//
// The file implements AccountController which is responsible for managing clients
// connected to the server and users registered with the application.
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include <sstream>
#include <unistd.h>

#include "AccountController.h"

using namespace std;


std::vector<Message> AccountController::startLogin(const Message& message) {
    if(isUserLoggedIn(message)) {
        return std::vector<Message> { Message{message.user, ALREADY_LOGIN_MESSAGE} };
    }
    message.user.getAccount().isLoggingIn = true;

    return _accountService.updateUserState(message, LoginEvent {});
}

std::vector<Message> AccountController::startRegister(const Message& message) {
    if(isUserLoggedIn(message)) {
        return std::vector<Message> { Message{message.user, LOGOUT_BEFORE_REGISTER_MESSAGE} };
    }
    message.user.getAccount().isRegistering = true;

    return _accountService.updateUserState(message, RegisterEvent {});
}

std::vector<Message> AccountController::logoutUser(const Message& message) {
    if(isUserLoggedIn(message)) {
        message.user.removeCommand(LOGOUT, "You are not logged in!");

        message.user.reset();
        return std::vector<Message> { Message{message.user, LOGOUT_MESSAGE} };
    }

    return std::vector<Message>{ Message{message.user, NOT_LOGIN_MESSAGE} };
}

std::vector<Message> AccountController::escapeLogin(const Message& message) {
    const Account& account = message.user.getAccount();
    stringstream response;
    if (account.isLoggingIn || account.isRegistering) {
        if (account.isRegistering) {
            response << ESCAPE_WHILE_REGISTERING_MESSAGE
                     << message.user.getConnection().id;
        } else {
            response << LOGGING_IN_ESCAPE_MESSAGE
                     << message.user.getConnection().id;
        }

        message.user.reset();
    } else {
        response << ESCAPE_WHILE_NOT_LOGIN_MESSAGE;
    }
    return std::vector<Message>{ Message{message.user, response.str()} };
}

Message AccountController::respondToMessage(const Message& message) {
    return isUserLoggedIn(message)
        ? Message {message.user, ""}
        : _accountService.updateUserState(message, UpdateEvent {}).front();
}


/*
 * PRIVATE METHODS
 */
bool AccountController::isUserLoggedIn(const Message& message) const {
    return message.user.getAccount().isLoggedIn;
}