#include "MiniGameActions.h"

bool MiniGameActions::roomHaveMiniGame(const ID& roomId) {
    return _roomIdToMiniGameConnectionsList.count(roomId) > 0;
}

models::MiniGame MiniGameActions::getMiniGame(const ID& roomId, const std::string keywordString) {
    auto room = _roomIdToMiniGameConnectionsList.find(roomId);
    return room->second;
}

bool MiniGameActions::verifyAnswer(const ID& roomId, const int input) {
    auto room = _roomIdToMiniGameConnectionsList.find(roomId);

    return room->second.checkAnswer(input);
}

void MiniGameActions::loadMiniGame() {
    // load minigame
    for (const CusJson::MiniGame& minigame : _dataStorage.getMiniGameList()._minigames) {
        //auto roomUuid = jsonIdToUuid.find(minigame._roomId);
        auto roomUuid = _roomConnectionService.getRoomByJsonId(minigame._roomId);
        _roomIdToMiniGameConnectionsList.emplace(roomUuid, models::MiniGame(minigame));
    }
}

void MiniGameActions::nextRound(const ID& roomID) {
    auto minigame = _roomIdToMiniGameConnectionsList.find(roomID);
    minigame->second.nextRound();
}

bool MiniGameActions::hasMoreRounds(const ID& roomID) {
    auto minigame = _roomIdToMiniGameConnectionsList.find(roomID);
    return minigame->second.hasMoreRounds();
}

void MiniGameActions::resetMiniGame(const ID& roomID) {
    auto minigame = _roomIdToMiniGameConnectionsList.find(roomID);

    minigame->second.resetMiniGame();
}
