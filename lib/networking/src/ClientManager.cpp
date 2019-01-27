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

#include <ClientManager.h>

using namespace std;

//////////////////////////////////////////////PUBLIC///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
Message ClientManager::promptLogin(uintptr_t connectionId, const Message& message) {
    auto userIter = _connectedUserMap.find(connectionId);
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

    return Message{connectionId, response.str()};
}

///////////////////////////////////////////////////////////////////////////////////////////////////
bool ClientManager::isLoggedIn(uintptr_t connectionId, string username) {
    auto userIter = _connectedUserMap.find(connectionId);
    if(userIter != _connectedUserMap.end()) {
        return userIter->second.state == State::LOGGED_IN;
    }

    return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
bool ClientManager::registerClient(uintptr_t connectionId) {
    if(_connectedUserMap.find(connectionId) == _connectedUserMap.end()){
        User user {State::CONNECTED};
        _connectedUserMap.insert(std::make_pair(connectionId, user));
        return true;
    }

    // TODO: Manage non-unique connections when database schema is defined
    std::cout << "This connection is not unique: " << connectionId << endl;
    return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
bool ClientManager::unregisterClient(uintptr_t connectionId) {
    _connectedUserMap.erase(connectionId);
    return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
bool ClientManager::isBeingProcessed(uintptr_t connectionId) {
    auto userIter = _connectedUserMap.find(connectionId);
    if(userIter != _connectedUserMap.end()) {
        return userIter->second.inProcess;
    }

    return false;
}




