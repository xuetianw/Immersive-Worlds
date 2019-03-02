//
// Created by asim on 07/02/19.
//

#ifndef WEBSOCKETNETWORKING_GAMECONTROLLER_H
#define WEBSOCKETNETWORKING_GAMECONTROLLER_H

constexpr char INITIAL_ROOM_START_MESSAGE[] = "User has spawned in initial room";

constexpr char USER_CURRENTLY_LOCATED_MESSAGE[] = "You are currently located in ";

constexpr char ROOM_SPAWN_FAIL_MESSAGE[] = "User failed to be spawned in a room";

constexpr char WRONG_DIRECTION_MESSAGE[] = "wrong message for direction";

#include <Server.h>
#include "GameService.h"
#include "AbstractController.h"

class GameController : AbstractController {
public:
    GameController() = default;

    explicit GameController(GameService &gameService);

    Message move(const Message &message);

    pair<bool, Message> respondToMessage(Message& message) override;

    void addUser(const networking::Connection &connection);

    Message spawnUserInStartRoom(User& user);

    void spawnUserInRoom(User& user, int debugRoomId);

    /**
     * Displays to the user info about their current location.
     * @param message
     * @return current location info
     */
    Message outputCurrentLocationInfo(Message& message);

private:
    GameService _gameService;
    std::vector<std::string> directions = {"east", "west", "south", "north"};

    bool checkIsDirectionMessage(const Message &message);
};

#endif //WEBSOCKETNETWORKING_GAMECONTROLLER_H
