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
     */
    models::MiniGame getMiniGame(const ID& roomId, const std::string keywordString);

    bool roomHaveMiniGame(const ID& roomId);

    bool hasMoreRounds(const ID& roomID);

    /** 
     * Verify if the answer given in the minigame is the correct one.
     */
    bool verifyAnswer(const ID& roomId, const int input);

    /* 
     * increment the next round if a game exists
     */
    void nextRound(const ID& roomID);

    void resetMiniGame(const ID& roomID);

private:
    std::unordered_map<ID, models::MiniGame> _roomIdToMiniGameConnectionsList;
    
    DataStorageService _dataStorage;
    RoomConnectionService _roomConnectionService;
};

#endif //WEBSOCKETNETWORKING_MINIGAMESERVICE_H
