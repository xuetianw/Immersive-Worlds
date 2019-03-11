#ifndef WEBSOCKETNETWORKING_MESSAGE_H
#define WEBSOCKETNETWORKING_MESSAGE_H

#include "User.h"
#include "Server.h"

struct Message{
    User& user;
    string text;

    Message(User& user) : user(user), text(""){}

    Message(User& user, string text) : user(user), text(text){}

    networking::ServerMessage convertToServerMessage(){
        return networking::ServerMessage{this->user.getConnection(), this->text};
    }
};

#endif