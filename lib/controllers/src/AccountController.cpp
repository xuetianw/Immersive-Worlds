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
#include <AccountController.h>

using namespace std;

Message AccountController::startLogin(const Message& message) {
    if(isUserLoggedIn(message)) {
        return Message{message.user, ALREADY_LOGIN_MESSAGE};
    }
    message.user.getAccount().isLoggingIn = true;

    message.user.addCommand(ESCAPE);
    message.user.removeCommand(REGISTER);
    message.user.removeCommand(LOGIN);

    return _accountService.updateUserState(message);
}

Message AccountController::startRegister(const Message& message) {
    if(isUserLoggedIn(message)) {
        return Message{message.user, LOGOUT_BEFORE_REGISTER_MESSAGE};
    }
    message.user.getAccount().isRegistering = true;

    message.user.addCommand(ESCAPE);
    message.user.removeCommand(REGISTER);
    message.user.removeCommand(LOGIN);

    return _accountService.updateUserState(message);
}

Message AccountController::logoutUser(const Message& message) {
    if(isUserLoggedIn(message)) {
        message.user.removeCommand(LOGOUT);

        message.user.reset();
        return Message{message.user, LOGOUT_MESSAGE};
    }

    return Message{message.user, NOT_LOGIN_MESSAGE};
}

Message AccountController::escapeLogin(const Message& message) {
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
    return Message{message.user, response.str()};
}

Message AccountController::respondToMessage(const Message& message) {
    return isUserLoggedIn(message)
        ? Message {message.user, ""}
        : _accountService.updateUserState(message);
}


/*
 * PRIVATE METHODS
 */
bool AccountController::isUserLoggedIn(const Message& message) const {
    return message.user.getAccount().isLoggedIn;
}