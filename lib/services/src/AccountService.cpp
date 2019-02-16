//
// Created by asim on 07/02/19.
//

#include <iostream>
#include <variant>

#include "AccountService.h"

void AccountService::connect(const Connection& connection) {
    if (_connectedUserMap.find(connection) == _connectedUserMap.end()) {
        _connectedUserMap.insert(std::make_pair(connection, User{}));
    }
    else {
        std::cout << "This connection is not unique: " << connection.id << std::endl;
    }
}

void AccountService::disconnectClient(const Connection &connection) {
    _connectedUserMap.erase(connection);
}

User& AccountService::getUser(Connection& connection){
    return _connectedUserMap.find(connection)->second;
}

Message AccountService::updateUserState(const Message &message) {
    auto userIter = _connectedUserMap.find(message.connection);
    // std::optional<UserStateVariant> newState = std::visit(StateTransitions {}, userIter->second._state);
    auto newState = std::visit(
            [&](auto& state) -> std::optional<UserStateVariant>
            {
                return transitions(state, userIter->second, message);
            }, userIter->second._state);
    userIter->second._state = *std::move(newState);

    return transitions._currentUserResponseMessage;
}

bool AccountService::isLoggedIn(const Connection &connection) {
    auto userIter = _connectedUserMap.find(connection);
    return (userIter != _connectedUserMap.end() && std::holds_alternative<LoggedInState>(userIter->second._state));
}
