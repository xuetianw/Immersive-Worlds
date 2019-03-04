//
// Created by vinshit on 16/02/19.
//

#ifndef WEBSOCKETNETWORKING_User_H
#define WEBSOCKETNETWORKING_User_H

#include <unordered_set>

#include "Server.h"
#include "Command.h"
#include "UserState.h"

using Connection = networking::Connection;

class User {
private:
    networking::Connection _connection;
    Account _account;
    std::unordered_set<Command> _allowedCommands;

public:
    User() = default;

    explicit User(Connection c) : _connection(c) {
        reset();
    }

    void reset();

    void removeCommand(Command command);

    void addCommand(Command command);

    const Connection& getConnection() const;

    void setConnection(const Connection& connection);

    Account& getAccount();

    void setAccount(const Account& account);

    const std::unordered_set<Command>& getAllowedCommands() const;

    void setAllowedCommands(std::unordered_set<Command> allowedCommands);

    bool canPreformCommand(Command command);
};

#endif //WEBSOCKETNETWORKING_User_H
