//
// Created by asim on 06/02/19.
//

#ifndef WEBSOCKETNETWORKING_COMMAND_H
#define WEBSOCKETNETWORKING_COMMAND_H

#include <Server.h>
#include "GameService.h"

class Command {
public:
    virtual ~Command() {}

    virtual networking::Message execute(GameService& actor) = 0;

protected:
    Command() {}
};

#endif //WEBSOCKETNETWORKING_COMMAND_H
