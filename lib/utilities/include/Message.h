#ifndef WEBSOCKETNETWORKING_MESSAGE_H
#define WEBSOCKETNETWORKING_MESSAGE_H

#include <Server.h>
#include "User.h"
#include "Server.h"

struct Message {
    User& user;
    string text;

    explicit Message(User& user) : user(user), text(""){}

    Message(User& user, string text) : user(user), text(std::move(text)){}
};

#endif