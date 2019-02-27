//
// Created by vinshit on 16/02/19.
//

#ifndef WEBSOCKETNETWORKING_User_H
#define WEBSOCKETNETWORKING_User_H


#include <Server.h>
#include <Command.h>
#include <unordered_set>
#include <UserState.h>

using networking::Connection;
using std::unordered_set;

class User {

private:
    networking::Connection connection;
    Account account;
    // Game Character here too;
    unordered_set<Command> allowedCommands;

public:
    User(){
        account = Account{};
    };

    User(Connection c) : connection(c){
        account = Account{};
    }

    void removeCommand(Command command);

    void addCommand(Command command);

    Connection & getConnection();

    void setConnection(const Connection &connection);

    Account& getAccount();

    void setAccount(const Account &account);

    const unordered_set<Command> &getAllowedCommands() const;

    void setAllowedCommands(const unordered_set<Command> &allowedCommands);

    bool canPreformCommand(Command command);
};



#endif //WEBSOCKETNETWORKING_User_H
