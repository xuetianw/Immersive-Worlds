//
// Created by asim on 06/02/19.
//

#ifndef WEBSOCKETNETWORKING_YELLCOMMAND_H
#define WEBSOCKETNETWORKING_YELLCOMMAND_H

#include "Command.h"
#include "Server.h"

class YellCommand : public Command {
public:
    YellCommand() = default;


    virtual networking::Message execute(GameService& service);
};

#endif //WEBSOCKETNETWORKING_YELLCOMMAND_H
