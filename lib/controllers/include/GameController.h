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

    /**
     * Calls GameService to Move Avatar.
     * Current Directions are north, east, south, west
     * @param message
     * @return response message
     */
    std::vector<Message> move(const Message& message);

    Message respondToMessage(const Message& message) override;

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

    std::vector<Message> yell(const Message& message);


private:
    GameService _gameService;

    //TODO make user a unique point
    std::unordered_map<ID, User*> _avatarIdToUser;

    User* findUser(const ID& avatarId);

    std::vector<std::string> directions = {"east", "west", "south", "north"};

    bool checkIsDirectionMessage(const Message& message);

    /**
    * Construct message to send to multiple avatars
    * @param message    the system message to be sent to avatars
    * @param avatarIds  list of avatar that should receive the message
    * @return vector of Messages that will be sent to the given list of avatars
    */
    std::vector<Message> constructMessageToAvatars(std::string message, const std::vector<ID>& avatarIds);
};

#endif //WEBSOCKETNETWORKING_GAMECONTROLLER_H
