//
// Created by vinshit on 16/02/19.
//

#ifndef WEBSOCKETNETWORKING_User_H
#define WEBSOCKETNETWORKING_User_H

#include <unordered_set>

#include "Command.h"
#include "AccountStateTransitions.h"
#include "Server.h"

using Connection = networking::Connection;

class User {
private:
    Connection _connection;

    Account _account;

    std::unordered_set<Command> _allowedCommands;

    std::unique_ptr<CommandType> _commandType;

public:
    User() = default;

    explicit User(Connection c) :
        _connection(c) {
        reset();
    }

    void reset();

    const Connection& getConnection() const;

    void setConnection(const Connection& connection);

    Account& getAccount();

    void setAccount(const Account& account);

    void setCommandType(CommandType* commandType);

    const std::unordered_set<Command>& getAllowedCommands() const;

    bool canPreformCommand(Command command);
};

#endif //WEBSOCKETNETWORKING_User_H
