//
// Created by asim on 07/02/19.
//

#ifndef WEBSOCKETNETWORKING_GAMECONTROLLER_H
#define WEBSOCKETNETWORKING_GAMECONTROLLER_H

#include "GameActions.h"
#include "GameService.h"
#include "CombatService.h"
#include "AbstractController.h"
#include "MiniGame.h"

constexpr char INITIAL_ROOM_START_MESSAGE[] = "User has spawned in initial room";
constexpr char USER_CURRENTLY_LOCATED_MESSAGE[] = "You are currently located in ";
constexpr char ROOM_SPAWN_FAIL_MESSAGE[] = "User failed to be spawned in a room";
constexpr char WRONG_DIRECTION_MESSAGE[] = "wrong message for direction";
constexpr char INVALID_GAME_COMMAND[] = "Invalid Command. Please enter a valid game command!";

class GameController {
public:
    GameController() : _dataStorageService(DataStorageService{}),
                       _roomConnectionService{_dataStorageService},
                       _avatarService{_dataStorageService},
                       _gameActions(_roomConnectionService, _avatarService) {}

    /**
     * Calls GameService to Move Avatar.
     * Current Directions are north, east, south, west
     * @param message
     * @return response message
     */
    std::vector<Message> move(const Message& message);

    std::vector<Message> respondToMessage(const Message& message);

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

    /*
     * Start a combat session with an NPC
     * OR
     * continue combat session
     * @param message
     * @return the message that will be displayed
     */
    std::vector<Message> attackNPC(const Message& message);

    /*
     * Escape/Flee combat
     * @param message
     * @return the message that will be displayed
     */
    std::vector<Message> fleeCombat(const Message& message);

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
    // Services
    DataStorageService _dataStorageService;
    RoomConnectionService _roomConnectionService;
    AvatarService _avatarService;

    // Actions
    GameActions _gameActions;
    GameService _gameService;
    CombatService _combatService;

    std::unordered_map<ID, User*> _avatarIdToUser;

    User* findUser(const ID& avatarId);
};

#endif //WEBSOCKETNETWORKING_GAMECONTROLLER_H
