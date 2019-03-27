#include "MiniGameActions.h"

bool MiniGameActions::roomHaveMiniGame(const ID& roomId) {
    return _roomIdToMiniGameConnectionsList.count(roomId) > 0;
}

models::MiniGame MiniGameActions::getMiniGame(const ID& roomId) {
    auto room = _roomIdToMiniGameConnectionsList.find(roomId);
    return room->second;
}

bool MiniGameActions::verifyAnswer(const ID& roomId, const int input) {
    auto room = _roomIdToMiniGameConnectionsList.find(roomId);

    return room->second.checkAnswer(input);
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
