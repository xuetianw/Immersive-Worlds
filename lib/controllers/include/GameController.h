//
// Created by asim on 07/02/19.
//

#ifndef WEBSOCKETNETWORKING_GAMECONTROLLER_H
#define WEBSOCKETNETWORKING_GAMECONTROLLER_H

#include <Server.h>
#include "GameService.h"
#include "AbstractController.h"

class GameController : AbstractController {
public:
    GameController() = default;

    networking::Message yell(const Message& message);
    
    pair<bool, Message> respondToMessage(const Message& message);

private:
    GameService gameService;
};

#endif //WEBSOCKETNETWORKING_GAMECONTROLLER_H
