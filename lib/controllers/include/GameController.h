//
// Created by asim on 07/02/19.
//

#ifndef WEBSOCKETNETWORKING_GAMECONTROLLER_H
#define WEBSOCKETNETWORKING_GAMECONTROLLER_H

constexpr char INITIAL_ROOM_START_MESSAGE[] = "User has spawned in initial room";

constexpr char USER_CURRENTLY_LOCATED_MESSAGE[] = "You are currently located in ";

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

    /**
     * Displays to the user info about their current location.
     * @param message
     * @return current location info
     */
    Message outputCurrentLocationInfo(Message& message);

private:
    GameService _gameService;
};

#endif //WEBSOCKETNETWORKING_GAMECONTROLLER_H
