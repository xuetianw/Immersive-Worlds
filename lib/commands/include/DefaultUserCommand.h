//
// Created by asim on 08/02/19.
//

#ifndef WEBSOCKETNETWORKING_DEFAULTUSERCOMMAND_H
#define WEBSOCKETNETWORKING_DEFAULTUSERCOMMAND_H

#include "Command.h"
#include "Service.h"
#include "Server.h"

class DefaultUserCommand : public Command {
public:
    networking::Message execute(Service& service, const Message& message) override;
};

#endif //WEBSOCKETNETWORKING_DEFAULTUSERCOMMAND_H
