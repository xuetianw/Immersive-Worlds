//
// Created by Nirag Mehta on 2019-01-30.
//

#ifndef WEBSOCKETNETWORKING_COMMANDPROCESSOR_H
#define WEBSOCKETNETWORKING_COMMANDPROCESSOR_H

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

// maps input command to enum value, which in turn points to a specific API
map<string,command> commandMap;


void parseCommand(Message message);

#endif //WEBSOCKETNETWORKING_COMMANDPROCESSOR_H
