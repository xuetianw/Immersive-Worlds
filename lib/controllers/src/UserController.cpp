///////////////////////////////////////////////////////////////////////////////////////////////////
// Authors: Asim, Nirag, Vincent
// Created On: January 26, 2019
//
// The file implements UserController which is responsible for managing clients
// connected to the server and users registered with the application.
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <UserController.h>


#include "UserController.h"

using namespace std;

Message UserController::startLogin(Message &message) {
    if(userService.isLoggedIn(message.connection)) {
        return Message{message.connection, "You are logged in - logout to preform this command"};
    }
    userService.getUser(message.connection).isLoggingIn = true;
    return userService.updateUserState(message);
}

Message UserController::startRegister(Message &message) {
    if(userService.isLoggedIn(message.connection)) {
        return Message{message.connection, "You are logged in - logout to preform this command"};
    }
    userService.getUser(message.connection).isRegistering = true;
    return userService.updateUserState(message);
}

Message UserController::logoutUser(Message &message) {
    if(userService.isLoggedIn(message.connection)) {
        userService.getUser(message.connection) = User{};
        return Message{message.connection, "You have logged out"};
    }

    return Message{message.connection, "You are not logged in!"};
}

Message UserController::escapeLogin(Message &message) {
    User &user = userService.getUser(message.connection);
    stringstream response;
    if (user.isLoggingIn || user.isRegistering) {
        if (user.isRegistering) {
            response << "You have exited out of the registration process\n"
                     << message.connection.id;
        } else {
            response << "You have exited out of the login process\n"
                     << message.connection.id;
        }
        user = User{};
    } else {
        response << "You are not submitting any Account information currently";
    }
    return Message{message.connection.id, response.str()};
}

void UserController::connectClient(const Connection &connection) {
    userService.connect(connection);
}

void UserController::disconnectClient(const Connection &connection) {
    userService.disconnectClient(connection);
}

pair<bool, Message> UserController::respondToMessage(const Message &message) {
    if (userService.isLoggedIn(message.connection)){
        return pair<bool, Message> (false, Message{});
    }

    return pair<bool, Message>(true, userService.updateUserState(message));
}


