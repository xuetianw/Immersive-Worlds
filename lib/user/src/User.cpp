//
// Created by vinshit on 16/02/19.
//

#include <User.h>

#include "User.h"

void User::removeCommand(Command command) {
    allowedCommands.erase(command);
}

void User::addCommand(Command command) {
    allowedCommands.insert(command);
}

Connection & User::getConnection() {
    return connection;
}

void User::setConnection(const Connection &connection) {
    User::connection = connection;
}

Account& User::getAccount() {
    return account;
}

void User::setAccount(const Account &account) {
    User::account = account;
}

const unordered_set<Command> &User::getAllowedCommands() const {
    return allowedCommands;
}

void User::setAllowedCommands(const unordered_set<Command> &allowedCommands) {
    User::allowedCommands = allowedCommands;
}

bool User::canPreformCommand(Command command) {
    return allowedCommands.find(command) != allowedCommands.end();
}
