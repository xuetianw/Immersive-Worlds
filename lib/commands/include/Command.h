//
// Created by asim on 06/02/19.
//

#ifndef WEBSOCKETNETWORKING_COMMAND_H
#define WEBSOCKETNETWORKING_COMMAND_H

#include <Server.h>

using networking::Message;

class Command {
public:
    virtual ~Command() = default;

    virtual Message execute(const Message& message) = 0;

protected:
    Command() = default;
};

#endif //WEBSOCKETNETWORKING_COMMAND_H
