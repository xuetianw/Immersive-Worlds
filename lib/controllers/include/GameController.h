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
#include "MiniGame.h"

class GameController : AbstractController {
public:
    GameController() = default;

    explicit GameController(GameService& gameService);

    Message move(const networking::Message& message);

    pair<bool, Message> respondToMessage(const Message& message) override;

    void addUser(const networking::Connection& connection);

    Message spawnUserInStartRoom(const networking::Connection& connection);

    void spawnUserInRoom(const networking::Connection& connection, int debugRoomId);

    /**
     * Creates a MiniGame based on the room.
     * @param message
     * @return the message that will be displayed
     */
    networking::Message startMiniGame(const networking::Message& message);

    /**
     * Verify if the input given by the user is valid.
     * @param message
     * @return the message that will be displayed
     */
    networking::Message verifyMinigameAnswer(const networking::Message& message);

    /**
     * Displays to the user info about their current location.
     * @param message
     * @return current location info
     */
    Message outputCurrentLocationInfo(Message& message);

private:
    GameService _gameService;
    std::vector<std::string> directions = {"east", "west", "south", "north"};

    bool checkIsDirectionMessage(const Message& message);
};

#endif //WEBSOCKETNETWORKING_GAMECONTROLLER_H
