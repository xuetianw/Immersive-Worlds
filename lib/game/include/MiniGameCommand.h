//
// Created by Jan Ycasas on 14/02/19.
//

#ifndef WEBSOCKETNETWORKING_MINIGAMECOMMAND_H
#define WEBSOCKETNETWORKING_MINIGAMECOMMAND_H

#include "Command.h"
#include "Server.h"
#include "ClientManager.h"

class MiniGameCommand : public Command {
public:
    MiniGameCommand() = default;


    virtual networking::Message execute(GameService& service);
    networking::Message test(GameService& service,  const Message& message);
};

#endif //WEBSOCKETNETWORKING_MINIGAMECOMMAND_H
