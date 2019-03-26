#include "MiniGameService.h"
#include <iostream>

bool MiniGameService::roomHaveMiniGame(const ID& roomId) {
    return _roomIdToMiniGameConnectionsList.count(roomId) > 0;
}

models::MiniGame MiniGameService::getMiniGame(const ID& roomId, const std::string keywordString) {
    auto room = _roomIdToMiniGameConnectionsList.find(roomId);
    return room->second;
}

bool MiniGameService::verifyAnswer(const ID& roomId, const int input) {
    auto room = _roomIdToMiniGameConnectionsList.find(roomId);

    return room->second.checkAnswer(input);
}

void MiniGameService::loadMiniGame() {
    // load minigame
    for (const CusJson::MiniGame& minigame : _dataStorage.getMiniGameList()._minigames) {
        //auto roomUuid = jsonIdToUuid.find(minigame._roomId);
        auto roomUuid = _roomConnectionService.getRoomByJsonId(minigame._roomId);
        _roomIdToMiniGameConnectionsList.emplace(roomUuid, models::MiniGame(minigame));
    }
}

void MiniGameService::nextRound(const ID& roomID) {
    auto minigame = _roomIdToMiniGameConnectionsList.find(roomID);
    minigame->second.nextRound();
}

bool MiniGameService::hasMoreRounds(const ID& roomID) {
    auto minigame = _roomIdToMiniGameConnectionsList.find(roomID);
    return minigame->second.hasMoreRounds();
}

void MiniGameService::resetMiniGame(const ID& roomID) {
    auto minigame = _roomIdToMiniGameConnectionsList.find(roomID);

    minigame->second.resetMiniGame();
}
