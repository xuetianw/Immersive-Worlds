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


#include "AccountController.h"

using namespace std;

Message AccountController::startLogin(Message &message) {
    if(userService.isLoggedIn(message.connection)) {
        return Message{message.connection, ALREADY_LOGIN_MESSAGE};
    }
    userService.getUser(message.connection).isLoggingIn = true;
    return userService.updateUserState(message);
}

Message AccountController::startRegister(Message &message) {
    if(userService.isLoggedIn(message.connection)) {
        return Message{message.connection, LOGOUT_BEFORE_REGISTER_MESSAGE};
    }
    userService.getUser(message.connection).isRegistering = true;
    return userService.updateUserState(message);
}

Message AccountController::logoutUser(Message &message) {
    if(userService.isLoggedIn(message.connection)) {
        userService.getUser(message.connection) = User{};
        return Message{message.connection, LOGOUT_MESSAGE};
    }

    return Message{message.connection, NOT_LOGIN_MESSAGE};
}

Message AccountController::escapeLogin(Message &message) {
    User &user = userService.getUser(message.connection);
    stringstream response;
    if (user.isLoggingIn || user.isRegistering) {
        if (user.isRegistering) {
            response << ESCAPE_WHILE_REGISTERING_MESSAGE
                     << message.connection.id;
        } else {
            response << LOGGING_IN_ESCAPE_MESSAGE
                     << message.connection.id;
        }
        user = User{};
    } else {
        response << "You are not submitting any Account information currently";
    }
    return Message{message.connection.id, response.str()};
}

void AccountController::connectClient(const Connection &connection) {
    userService.connect(connection);
}

void AccountController::disconnectClient(const Connection &connection) {
    userService.disconnectClient(connection);
}

pair<bool, Message> AccountController::respondToMessage(const Message &message) {
    if (userService.isLoggedIn(message.connection)){
        return pair<bool, Message> (false, Message{});
    }

    return pair<bool, Message>(true, userService.updateUserState(message));
}


