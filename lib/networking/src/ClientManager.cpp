///////////////////////////////////////////////////////////////////////////////////////////////////
// Authors: Asim, Nirag, Vincent
// Created On: January 26, 2019
//
// The file implements ClientManager which is responsible for managing clients connected to the
// server and users registered with the application.
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include <sstream>
#include <unistd.h>

#include "ClientManager.h"

using namespace std;

//////////////////////////////////////////////PUBLIC///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
bool ClientManager::isClientPromptingLogin(const Connection &connection) const {
    auto userIter = _connectedUserMap.find(connection.id);
    if(userIter != _connectedUserMap.end()) {
        return userIter->second.state == State::LOGGING_IN_USER ||
            userIter->second.state == State::LOGGING_IN_PWD;
    }

    return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
bool ClientManager::isLoggedIn(const uintptr_t connectionId) const {
    auto userIter = _connectedUserMap.find(connectionId);
    if(userIter != _connectedUserMap.end()) {
        return userIter->second.state == State::LOGGED_IN;
    }

    return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
Message ClientManager::promptLogin(const Message& message) {
    auto userIter = _connectedUserMap.find(message.connection.id);
    User& user = userIter->second;

    // Response to be sent back to the specific user
    std::ostringstream response;

    switch(user.state) {
        case State::CONNECTED: {
            user.state = State::LOGGING_IN_USER;
            response << "Please enter your username:\n";
            break;
        }
        case State::LOGGING_IN_USER: {
            // TODO: Implement DBUtility to validate username for a registered user in the database
            user.username = message.text;
            user.state = State::LOGGING_IN_PWD;
            response << "Please enter your password:\n";
            break;
        }
        case State::LOGGING_IN_PWD: {
            //TODO: Implement DBUtility to authenticate user
            auto dummyUser = _userData.find(user.username);
            if (dummyUser != _userData.end() && dummyUser->second == message.text) {
                user.state = State::LOGGED_IN;
                response << "Successfully logged in!\n";
            } else {
                user.state = State::LOGGING_IN_USER;
                response << "Login Unsuccessful\nPlease enter your username again:\n";
            }
            break;
        }
        default:
            // Execution should never reach here.
            // TODO: Log the state on server

            response << "Invalid Request\nPlease try logging in again\n" << message.connection.id;
            response << "> " << message.text + "\n";
    }

    // TODO: Imeplement a quit on this

    return Message{message.connection.id, response.str()};
}

///////////////////////////////////////////////////////////////////////////////////////////////////
Message ClientManager::logoutClient(const Message &message){
    string response;
    auto connectionId = message.connection.id;
    if(isLoggedIn(connectionId)) {
        auto userIter = _connectedUserMap.find(connectionId);
        User& user = userIter->second;
        user.state = State::CONNECTED;
        return Message{connectionId, "User successfully logged out!\n"};
    }
    return Message{connectionId, "User not logged in!\n"};

}

///////////////////////////////////////////////////////////////////////////////////////////////////
bool ClientManager::registerClient(const Connection &connection) {
    if(_connectedUserMap.find(connection.id) == _connectedUserMap.end()){
        //TODO
        // before creating another user, check if the user exists
        User user {State::CONNECTED};
        _connectedUserMap.insert(std::make_pair(connection.id, user));
        return true;
    }

    // TODO: Manage non-unique connections when database schema is defined
    // connectionId is always unique
    std::cout << "This connection is not unique: " << connection.id << endl;
    return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
bool ClientManager::unregisterClient(const Connection &connection) {
    _connectedUserMap.erase(connection.id);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////
Message ClientManager::escapeLogin(const Message& message) {

    User& user = _connectedUserMap.find(message.connection.id)->second;
    std::ostringstream response;

    //revert back to connected
    if(isClientPromptingLogin(message.connection)){
        user.state = State::CONNECTED;
        response << "You have exited out of the login process\n" << message.connection.id;
    } else{
        response << "Invalid command. Use when trying to log in\n" << message.connection.id;
    }
    return Message{message.connection.id, response.str()};

}



