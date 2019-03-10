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
    return _accountService.updateUserState(message, LoginEvent {});
}

std::vector<Message> AccountController::startRegister(const Message& message) {
    return _accountService.updateUserState(message, RegisterEvent {});
}

std::vector<Message> AccountController::logoutUser(const Message& message) {
    return _accountService.updateUserState(message, LogoutEvent {});
}

std::vector<Message> AccountController::escapeLogin(const Message& message) {
    return _accountService.updateUserState(message, EscapeEvent {});
}

Message AccountController::respondToMessage(const Message& message) {
    return message.user.getAccount().isLoggedIn
        ? Message {message.user, ""}
        : _accountService.updateUserState(message, UpdateEvent {}).front();
}