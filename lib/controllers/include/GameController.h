//
// Created by asim on 07/02/19.
//

#ifndef WEBSOCKETNETWORKING_GAMECONTROLLER_H
#define WEBSOCKETNETWORKING_GAMECONTROLLER_H

#include "GameService.h"
#include "AbstractController.h"
#include "MiniGame.h"

constexpr char INITIAL_ROOM_START_MESSAGE[] = "User has spawned in initial room";
constexpr char USER_CURRENTLY_LOCATED_MESSAGE[] = "You are currently located in ";
constexpr char ROOM_SPAWN_FAIL_MESSAGE[] = "User failed to be spawned in a room";
constexpr char WRONG_DIRECTION_MESSAGE[] = "wrong message for direction";

class GameController : AbstractController {
public:
    GameController() : _gameService() {}

    std::vector<Message> move(const Message &message);

    Message respondToMessage(const Message& message) override;

    Message spawnUserInRoomOnLogin(User &user);

    void spawnUserInRoom(const networking::Connection& connection, int debugRoomId);

    /**
     * Creates a MiniGame based on the room.
     * @param message
     * @return the message that will be displayed
     */
    std::vector<Message> startMiniGame(const Message& message);

    /**
     * Verify if the input given by the user is valid.
     * @param message
     * @return the message that will be displayed
     */
    std::vector<Message> verifyMinigameAnswer(const Message& message);
    
    void spawnUserInRoom(User& user, ID roomId);

    /**
     * Displays to the user info about their current location.
     * @param message
     * @return current location info
     */
    std::vector<Message> outputCurrentLocationInfo(const Message& message);


private:
    GameService _gameService;

    std::vector<std::string> directions = {"east", "west", "south", "north"};

    bool checkIsDirectionMessage(const Message& message);
};

#endif //WEBSOCKETNETWORKING_GAMECONTROLLER_H
