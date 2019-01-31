//
// Created by Nirag Mehta on 2019-01-30.
//

#ifndef WEBSOCKETNETWORKING_COMMANDPROCESSOR_H
#define WEBSOCKETNETWORKING_COMMANDPROCESSOR_H

#include "ClientManager.h"
#include "Server.h"
#include "string"
#include "map"


using std::string;
using std::map;
using networking::Message;
using networking::Server;


enum class command{
    LOGIN,
    LOGOUT,
    QUIT,
    SHUTDOWN,
    ESCAPE,
    HELP,
    GO,
    TELL,
    YELL,
    ATTACK,
    TAKE,
    PUT,
    DROP
};

bool parseCommand(Message message, ClientManager &clientManager, Server& server);

bool isCommand(Message message);

void handleEscape(const Message message, ClientManager &clientManager);

#endif //WEBSOCKETNETWORKING_COMMANDPROCESSOR_H
