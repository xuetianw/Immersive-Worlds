//
// Created by asim on 08/02/19.
//

#ifndef WEBSOCKETNETWORKING_LOGINCOMMAND_H
#define WEBSOCKETNETWORKING_LOGINCOMMAND_H

#include "Command.h"
#include "Service.h"
#include "Server.h"

class LoginCommand : public Command {
public:
    virtual networking::Message execute(Service& service, const Message& message) override;
};

#endif //WEBSOCKETNETWORKING_LOGINCOMMAND_H
