//
// Created by Nirag Mehta on 2019-01-30.
//

#ifndef WEBSOCKETNETWORKING_COMMANDPROCESSOR_H
#define WEBSOCKETNETWORKING_COMMANDPROCESSOR_H

#include "string"
#include "map"
using namespace std;

enum class command{
    LOGIN,
    LOGOUT,
    ESCAPE,
    LIST,
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

#endif //WEBSOCKETNETWORKING_COMMANDPROCESSOR_H
