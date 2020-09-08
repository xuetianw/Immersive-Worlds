//
// Created by vinshit on 16/02/19.
//

#include "User.h"

using std::unordered_set;

void User::resetAllowedCommands() {
    _allowedCommands = std::make_unique<AccountCommands>()->getCommands();
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

ID User::getAvatarId() const{
    return _account.avatarId;
}
void User::setAvatarId(ID &id){
    _account.avatarId = id;
}

void User::setAccount(const Account& account) {
    _account = account;
}

void User::setCommandType(CommandType* commandType) {
    _allowedCommands = commandType->getCommands();
}

const unordered_set<Command>& User::getAllowedCommands() const {
    return _allowedCommands;
}

bool User::canPreformCommand(Command command) {
    return _allowedCommands.find(command) != _allowedCommands.end();
}



