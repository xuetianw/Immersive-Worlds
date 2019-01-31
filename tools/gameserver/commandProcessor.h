//
// Created by Nirag Mehta on 2019-01-30.
//

#ifndef WEBSOCKETNETWORKING_COMMANDPROCESSOR_H
#define WEBSOCKETNETWORKING_COMMANDPROCESSOR_H


#include "Server.h"
#include "string"
#include "map"

using std::string;
using std::map;
using networking::Message;

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

void parseCommand(Message message);

bool isCommand(Message message);

#endif //WEBSOCKETNETWORKING_COMMANDPROCESSOR_H
