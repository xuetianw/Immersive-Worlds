//
// Created by vinshit on 16/02/19.
//

#include "User.h"

using std::unordered_set;

void User::reset() {
    setAccount(Account{});
    setAllowedCommands({LOGIN, REGISTER, HELP});
}

void User::removeCommand(Command command) {
    _allowedCommands.erase(command);
}


void User::removeCommand(Command command, string message) {
    removeCommand(command);
    _disabledCommands[command] = message;
}

void User::addCommand(Command command) {
    _allowedCommands.insert(command);
    _disabledCommands.erase(command);
}

const Connection& User::getConnection() const {
    return _connection;
}

void User::setConnection(const Connection& connection) {
    _connection = connection;
}

Account& User::getAccount() {
    return _account;
}

void User::setAccount(const Account& account) {
    _account = account;
}

const unordered_set<Command>& User::getAllowedCommands() const {
    return _allowedCommands;
}

void User::setAllowedCommands(unordered_set<Command> allowedCommands) {
    _allowedCommands = move(allowedCommands);
}

bool User::canPreformCommand(Command command) {
    return _allowedCommands.find(command) != _allowedCommands.end();
}

const std::unordered_map<Command, string>& User::getDisabledCommands() const {
    return _disabledCommands;
}



