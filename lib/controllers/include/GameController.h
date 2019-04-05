//
// Created by asim on 07/02/19.
//

#ifndef WEBSOCKETNETWORKING_GAMECONTROLLER_H
#define WEBSOCKETNETWORKING_GAMECONTROLLER_H

#include "GameActions.h"
#include "CombatActions.h"
#include "MiniGame.h"
#include "MiniGameActions.h"
#include "InventoryService.h"

constexpr char INITIAL_ROOM_START_MESSAGE[] = "User has spawned in initial room";
constexpr char USER_CURRENTLY_LOCATED_MESSAGE[] = "You are currently located in ";
constexpr char ROOM_SPAWN_FAIL_MESSAGE[] = "User failed to be spawned in a room";
constexpr char WRONG_DIRECTION_MESSAGE[] = "wrong message for direction";
constexpr char INVALID_GAME_COMMAND[] = "Invalid Command. Please enter a valid game command!";
constexpr char USER_CONFUSED_MESSAGE[] = "You have been confused by another player!";

class GameController {
public:
    GameController() : _dataStorageService(DataStorageService{}),
                       _roomConnectionService{_dataStorageService},
                       _avatarService{_dataStorageService},
                       _inventoryService{_dataStorageService},
                       _gameActions(_roomConnectionService, _avatarService),
                       _miniGameActions(_dataStorageService, _roomConnectionService),
                       _combatActions(_avatarService, _roomConnectionService){ }

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
     * Output Avatars in the current room
     * @param message
     * @return
     */
     std::vector<Message> outputAvatarsInCurrentRoom(const Message& message);

    /* 
     * increment the next round if a game exists
     * @param message
     * @return prints next round if there are rounds left. 
     */
    std::vector<Message> nextRound(const Message& message);

    /**
    * Displays to the user message sent by another user in the same room
    * @param message
    * @return messages that will be sent to user in the same room
    */
    std::vector<Message> say(const Message& message);

    /**
    * Displays to the user message sent by another user in the same or adjacent rooms
    * @param message
    * @return messages that will be sent to user in the same or adjacent rooms
    */
    std::vector<Message> yell(const Message& message);

    /**
    * Deliver private message from a user to another user in the world
    * @param message
    * @return messages that will be sent to the receiver and sender (so they are aware of msg sent)
    */
    std::vector<Message> tell(const Message& message);

    /**
     * Displays to the user the available directions for their avatar
     * @param message
     * @return a list of available directions
     */
    std::vector<Message> listDirections(const Message& message);

    std::vector<Message> displayAvatarInfo(const Message& message);

    std::vector<Message> swapAvatar(const Message& message);

    /**
     * Confuses an avatar (i.e. the message avatar sees is scrambled)
     * @param message
     * @return message telling the initiator and target that this action has been done
     */
    std::vector<Message> confuseAvatar(const Message& message);

    std::vector<Message> unconfuseAvatar(const Message& message);

    /**
     * Determine whether or not an avatar is confused
     * @param avatarId
     * @return whether or not the avatar associated with given avatarId is confused
     */
    bool getAvatarConfuseState(const ID& avatarId);

    void scrambleMessages(std::vector<Message>& messages);

    void scrambleMessage(Message& message);


private:
    // Services
    DataStorageService _dataStorageService;
    RoomConnectionService _roomConnectionService;
    AvatarService _avatarService;
    InventoryService _inventoryService;

    // Actions
    GameActions _gameActions;
    CombatActions _combatActions;
    MiniGameActions _miniGameActions;

    std::unordered_map<ID, User*> _avatarIdToUser;

    User* findUser(const ID& avatarId);

    User* findUser(std::string username);

    std::string scrambleMessage(std::string message);

    /**
     * Change confuse state of an avatar
     * @param avatarId: id of target avatar
     *        isConfused: new value of confuse state
     * @return false if avatar not found, true if found and set to new value
     */
    bool setAvatarConfuseState(const ID& avatarId, bool isConfused);

    /**
    * Construct message to send to multiple avatars
    * @param message    the system message to be sent to avatars
    * @param avatarIds  list of avatar that should receive the message
    * @return vector of Messages that will be sent to the given list of avatars
    */
    std::vector<Message> constructMessageToAvatars(std::string messageHeader, std::string messageBody,
                                                                   const ID& senderAvatarId, const std::vector<ID>& avatarIds);

    //scrambles string if needed based on confuse state
    std::string processMessageForConfuse(std::string messageHeader, std::string messageBody,
                                                     bool senderIsConfused, bool isSender);
};

#endif //WEBSOCKETNETWORKING_GAMECONTROLLER_H
