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

class MiniGameService {
public:
    MiniGameService(){ }

private:
    std::unordered_map<ID, models::MiniGame> _roomIdToMiniGameConnectionsList;

public:
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

    void loadMiniGame(const DataStorageService& dataStorage, const RoomConnectionService& roomConnectionService);

    void nextRound(const ID& roomID);

    void resetMiniGame(const ID& roomID);
};

#endif //WEBSOCKETNETWORKING_MINIGAMESERVICE_H
