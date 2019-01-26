//
// Created by vinshit on 24/01/19.
//

#include <iostream>

#include <ClientManager.h>


bool findUserAccount(User user) {
    return true;
}


Message ClientManager::promptLogin(uintptr_t connection_id, const Message& message) {
    auto found_connection = connectedUserMap.find(connection_id);
    User &foundUser = found_connection->second;

    if(foundUser.state == State::CONNECTED) {
        foundUser.username = message.text;
        foundUser.state = State::LOGGING_IN_USER;
        return Message{connection_id, "Please enter your Password:"};
    }

    if(foundUser.state == State::LOGGING_IN_PWD) {
        foundUser.password = connection_id;
        //TODO: Implement findUserAccountusers to login
        if (findUserAccount(foundUser)) {
            foundUser.state = State::LOGGED_IN;
            return Message{connection_id, "Sucessfully logged in!:"};
        }
        else {
            foundUser.state = State::CONNECTED;
            return Message{connection_id, "Login Unsucessfull"};
        }
    }

    return Message{connection_id, "Sucessfully Logged In."};
}

bool ClientManager::isLoggedIn(uintptr_t connectionId, string username) {
    auto found_connection = connectedUserMap.find(connectionId);
    if(found_connection == connectedUserMap.end()){
        return false;
    } else {
        User foundUser = found_connection->second;
        return !(foundUser.state != State::LOGGED_IN);
    }
}

// A stub to register a client
bool ClientManager::registerClient(uintptr_t connectionId) { 
    auto found_connection = connectedUserMap.find(connectionId);
    if(found_connection == connectedUserMap.end()){
        User newUser{State::CONNECTED};
        connectedUserMap.insert(std::pair(connectionId, newUser));
        return true;
    } else {
        std::cout << "This connection is not unique: " << connectionId << "\n";
        return false;
    }
}

bool ClientManager::unregisterClient(uintptr_t connectionId) {
    connectedUserMap.erase(connectionId);
    return true;
}





