//
// Created by asim on 08/02/19.
//

#ifndef WEBSOCKETNETWORKING_LOGOUTCOMMAND_H
#define WEBSOCKETNETWORKING_LOGOUTCOMMAND_H

#include "Command.h"
#include "Service.h"
#include "Server.h"

class LogoutCommand : public Command {
public:
    Message execute(Service& service, const Message& message) override;
};

#endif //WEBSOCKETNETWORKING_LOGOUTCOMMAND_H
