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

    explicit GameController(GameService gameService);

    Message move(const networking::Message &message);

    pair<bool, Message> respondToMessage(const Message& message) override;

    void addUser(const networking::Connection &connection);

    Message spawnUserInStartRoom(const networking::Connection &connection);
    void spawnUserInRoom(const networking::Connection &connection, int debugRoomId);

    networking::Message createMinigame(const networking::Message &message);
    networking::Message verifyMinigameAnswer(const networking::Message &message);

private:
    GameService _gameService;
};

#endif //WEBSOCKETNETWORKING_GAMECONTROLLER_H
