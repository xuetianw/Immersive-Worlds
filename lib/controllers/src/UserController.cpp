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

#include "UserController.h"

using namespace std;

bool UserController::isLoggedIn(const Connection &connection) {
    return userService.isLoggedIn(connection);
}

void UserController::connectClient(const Connection &connection) {
    userService.connect(connection);
}

void UserController::disconnectClient(const Connection &connection) {
    userService.disconnectClient(connection);
}

Message UserController::handleCommand(Command *cmd, const Message& message) {
    return cmd->execute(userService, message);
}

//Message UserController::escapeLogin(const Message &message) {
//    User &user = _connectedUserMap.find(message.connection)->second;
//    stringstream response;
//    if (user.isLoggingIn() || user.isRegistering()) {
//        if (user.isRegistering()) {
//            response << "You have exited out of the registration process\n"
//                     << message.connection.id;
//        } else {
//            response << "You have exited out of the login process\n"
//                     << message.connection.id;
//        }
//        user = User{};
//    } else {
//        response << "You are not submitting any Account information currently";
//    }
//    return Message{message.connection.id, response.str()};
//}
