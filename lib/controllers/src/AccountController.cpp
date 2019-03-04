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

Message AccountController::startLogin(Message &message) {
    if(message.user.getAccount().isLoggedIn) {
        return Message{message.user, ALREADY_LOGIN_MESSAGE};
    }
    message.user.getAccount().isLoggingIn = true;
    
    message.user.addCommand(ESCAPE);
    message.user.removeCommand(REGISTER);
    message.user.removeCommand(LOGIN);
    
    return accountService.updateUserState(message);
}

Message AccountController::startRegister(Message &message) {
    if(message.user.getAccount().isLoggedIn) {
        return Message{message.user, LOGOUT_BEFORE_REGISTER_MESSAGE};
    }
    message.user.getAccount().isRegistering = true;

    message.user.addCommand(ESCAPE);
    message.user.removeCommand(REGISTER);
    message.user.removeCommand(LOGIN);
    
    return accountService.updateUserState(message);
}

Message AccountController::logoutUser(Message &message) {
    if(message.user.getAccount().isLoggedIn) {
        message.user.removeCommand(LOGOUT);
        
        disconnectClient(message.user);
        return Message{message.user, LOGOUT_MESSAGE};
    }

    return Message{message.user, NOT_LOGIN_MESSAGE};
}

Message AccountController::escapeLogin(Message &message) {
    Account &account = message.user.getAccount();
    stringstream response;
    if (account.isLoggingIn || account.isRegistering) {
        if (account.isRegistering) {
            response << ESCAPE_WHILE_REGISTERING_MESSAGE
                     << message.user.getConnection().id;
        } else {
            response << LOGGING_IN_ESCAPE_MESSAGE
                     << message.user.getConnection().id;
        }
        message.user.removeCommand(ESCAPE);
        disconnectClient(message.user);
    } else {
        response << ESCAPE_WHILE_NOT_LOGIN_MESSAGE;
    }
    return Message{message.user, response.str()};
}

void AccountController::connectClient(User &user) {
    accountService.connectUser(user);
}

void AccountController::disconnectClient(User &user) {
    accountService.disconnectUser(user);
}

pair<bool, Message> AccountController::respondToMessage(Message &message) {
    if (message.user.getAccount().isLoggedIn){
        return pair<bool, Message> (false, Message{message.user, ""});
    }

    Message response = accountService.updateUserState(message);
    if (message.user.getAccount().isLoggedIn && (onLoginFunction != nullptr)){
        Message onLoginResponse = onLoginFunction(message);
        response.text = response.text + "\n" + onLoginResponse.text;
    }

    return pair<bool, Message>(true, response);
}

void AccountController::setupFunctionPointer(function_ptr fnPtr){
    onLoginFunction = fnPtr;
}



