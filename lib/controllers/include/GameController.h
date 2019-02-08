//
// Created by asim on 07/02/19.
//

#ifndef WEBSOCKETNETWORKING_GAMECONTROLLER_H
#define WEBSOCKETNETWORKING_GAMECONTROLLER_H

#include <Server.h>
#include "Command.h"
#include "GameService.h"

class GameController {
public:
    GameController() = default;

    networking::Message yell(Command* cmd);

private:
    GameService gameService;
};

#endif //WEBSOCKETNETWORKING_GAMECONTROLLER_H
