//
// Created by asim on 07/02/19.
//

#ifndef WEBSOCKETNETWORKING_GAMECONTROLLER_H
#define WEBSOCKETNETWORKING_GAMECONTROLLER_H

static const char *const ROOM_SPAWN_SUCCESS_MESSAGE = "User has spawned in initial room";

static const char *const ROOM_SPAWN_FAIL_MESSAGE = "User failed to be spawned in a room";

static const char *const WRONG_DIRECTION_MESSAGE = "wrong message for direction";

#include <Server.h>
#include "GameService.h"
#include "AbstractController.h"

class GameController : AbstractController {
public:
    GameController() = default;

    explicit GameController(GameService &gameService);

    Message move(const networking::Message &message);

    pair<bool, Message> respondToMessage(const Message& message) override;

    void addUser(const networking::Connection &connection);

    Message spawnUserInStartRoom(const networking::Connection &connection);
    void spawnUserInRoom(const networking::Connection &connection, int debugRoomId);

private:
    GameService _gameService;
    std::vector<std::string> directions = {"east", "west", "south", "north"};

    bool check_message(const Message &message);
};

#endif //WEBSOCKETNETWORKING_GAMECONTROLLER_H
