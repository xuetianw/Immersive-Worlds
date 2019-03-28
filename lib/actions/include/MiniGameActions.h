#ifndef WEBSOCKETNETWORKING_MINIGAMESERVICE_H
#define WEBSOCKETNETWORKING_MINIGAMESERVICE_H

#include <unordered_map>
#include "MiniGame.h"
#include "User.h"
#include "Room.h"
#include "DataStorageService.h"
#include "AccountStateTransitions.h"
#include "AvatarService.h"
#include "RoomConnectionService.h"

class MiniGameActions {
public:
    MiniGameActions(DataStorageService& dataStorageService, RoomConnectionService& roomConnectionService) 
        : _dataStorage(dataStorageService), _roomConnectionService(roomConnectionService) { 
            _roomIdToMiniGameConnectionsList = _dataStorage.getRoomIdToMiniGameCopy();
        }

    /** 
     * Get the current minigame available in this room
     * @param roomId
     * @return the minigame
     */
    models::MiniGame getMiniGame(const ID& roomId);

    /**
     * Check if the room has a minigame inside
     * @param roomId
     * @return true if minigame inside
     */
    bool roomHaveMiniGame(const ID& roomId);

    /**
     * Check if the minigame has more rounds to show
     * @return true if there are more rounds
     */
    bool hasMoreRounds(const ID& roomID);

    /** 
     * Verify if the answer given in the minigame is the correct one.
     * @param roomId
     * @param input
     * @return true if the answer the user put was correct.
     */
    bool verifyAnswer(const ID& roomId, const int input);

    /** 
     * increment the next round if a game exists
     */
    void nextRound(const ID& roomID);

    /**
     * Reset the minigame by making the round to zero
     * @param roomID
     */
    void resetMiniGame(const ID& roomID);

private:
    std::unordered_map<ID, models::MiniGame> _roomIdToMiniGameConnectionsList;
    
    DataStorageService& _dataStorage;
    RoomConnectionService& _roomConnectionService;
};

#endif //WEBSOCKETNETWORKING_MINIGAMESERVICE_H
