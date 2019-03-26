//
// Created by asim on 07/02/19.
//

#ifndef WEBSOCKETNETWORKING_GAMECONTROLLER_H
#define WEBSOCKETNETWORKING_GAMECONTROLLER_H

#include "GameService.h"
#include "AbstractController.h"
#include "MiniGameService.h"

constexpr char INITIAL_ROOM_START_MESSAGE[] = "User has spawned in initial room";
constexpr char USER_CURRENTLY_LOCATED_MESSAGE[] = "You are currently located in ";
constexpr char ROOM_SPAWN_FAIL_MESSAGE[] = "User failed to be spawned in a room";
constexpr char WRONG_DIRECTION_MESSAGE[] = "wrong message for direction";
constexpr char INVALID_GAME_COMMAND[] = "Invalid Command. Please enter a valid game command!";

class GameController : AbstractController {
public:
    GameController() :  _gameService(), _miniGameService() {
        _miniGameService.loadMiniGame(_gameService.getDataStorageService(), _gameService.getRoomConnectionService());
    }

    /**
     * Calls GameService to Move Avatar.
     * Current Directions are north, east, south, west
     * @param message
     * @return response message
     */
    std::vector<Message> move(const Message& message);

    std::vector<Message> respondToMessage(const Message& message) override;

    std::vector<Message> onLogin(Message& message);

    const std::string spawnAvatarInStartingRoom(const ID& avatarId);

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

    /**
     * Displays to the user info about their current location.
     * @param message
     * @return current location info
     */
    std::vector<Message> outputCurrentLocationInfo(const Message& message);


    /**
    * Displays to the user message sent by another user in the same room
    * @param message
    * @return messages that will be sent to user in the same room
    */
    std::vector<Message> say(const Message& message);

    /**
     * Displays to the user the available directions for their avatar
     * @param message
     * @return a list of available directions
     */
    std::vector<Message> listDirections(const Message& message);

    std::vector<Message> displayAvatarInfo(const Message& message);

private:
    GameService _gameService;
    MiniGameService _miniGameService;

    std::unordered_map<ID, User*> _avatarIdToUser;

    User* findUser(const ID& avatarId);
};

#endif //WEBSOCKETNETWORKING_GAMECONTROLLER_H
