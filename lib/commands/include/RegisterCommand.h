//
// Created by asim on 08/02/19.
//

#ifndef WEBSOCKETNETWORKING_REGISTERCOMMAND_H
#define WEBSOCKETNETWORKING_REGISTERCOMMAND_H

#include "Command.h"
#include "Service.h"

class RegisterCommand : public Command {
public:
    networking::Message execute(Service& service, const Message& message) override;
};

#endif //WEBSOCKETNETWORKING_REGISTERCOMMAND_H
