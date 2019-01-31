//
// Created by Nirag Mehta on 2019-01-30.
//

#ifndef WEBSOCKETNETWORKING_COMMANDPROCESSOR_H
#define WEBSOCKETNETWORKING_COMMANDPROCESSOR_H

#include "ClientManager.h"
#include "Server.h"
#include "string"
#include "map"
#include "Server.h"
using namespace std;
using namespace networking;

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

bool isCommand(Message message);

#endif //WEBSOCKETNETWORKING_COMMANDPROCESSOR_H
