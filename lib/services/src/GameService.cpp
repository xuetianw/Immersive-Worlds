//
// Created by user on 2/8/19.
//

#include "Server.h"
#include "GameService.h"

using models::RoomConnection;

bool GameService::moveAvatar(const ID& avatarId, const string& directionString) {
    if (!_avatarService.doesAvatarExist(avatarId)) {
        return false;
    }

    const std::optional<std::reference_wrapper<const Avatar>> avatarOptional = _avatarService.getAvatarFromAvatarId(
        avatarId);
    const ID& currentAvatarRoomId = avatarOptional->get().getRoomId();

    const std::optional<std::reference_wrapper<const ID>> neighbourIdOptional = _roomConnectionService.getNeighbourId(
        currentAvatarRoomId, directionString);

    if (!neighbourIdOptional.has_value()) {
        return false;
    }

    bool didAvatarMove = _avatarService.setAvatarRoomId(avatarId, neighbourIdOptional.value());

    return didAvatarMove;
}


std::vector<string> GameService::getDirectionsForAvatarId(const ID& avatarId) {
    std::vector<string> response;

    if (!_avatarService.doesAvatarExist(avatarId)) {
        return response;
    }

    //get the Avatar object
    const std::optional<std::reference_wrapper<const Avatar>> avatarOptional =
        _avatarService.getAvatarFromAvatarId(avatarId);

    //get the room ID of the Avatar
    const ID& currentAvatarRoomId = avatarOptional->get().getRoomId();

    //get the available directions for the room ID
    response = _roomConnectionService.getAvailableRoomDirections(currentAvatarRoomId);

    return response;
};

bool GameService::userYell(const User& user, const std::string& messageString) {
    return false;
}

bool GameService::spawnAvatarInStartingRoom(const ID& avatarId) {
    const ID& startingRoomID = _roomConnectionService.getStartingRoom();

    //TODO input avatar name on registration
    return _avatarService.generateAvatarFromAvatarId(avatarId, startingRoomID, "SOMENAME");
}

std::optional<std::string> GameService::getAvatarRoomName(const ID& avatarId) {
    if (!_avatarService.doesAvatarExist(avatarId)) {
        return std::nullopt;
    }

    const std::optional<std::reference_wrapper<const Avatar>> avatarOptional = _avatarService.getAvatarFromAvatarId(
        avatarId);
    const ID& avatarRoomId = avatarOptional->get().getRoomId();

    std::optional<std::string> avatarRoomName = _roomConnectionService.getRoomName(avatarRoomId);

    return avatarRoomName.value();
}

//TODO FIX - getCurrentRoomName() is removed
bool GameService::roomHaveMiniGame(const User& user) {
//    auto roomName = getCurrentRoomName(user.getConnection());
//    return roomName != "";
}

//TODO FIX - getCurrentRoomName() is removed
models::MiniGame GameService::getMiniGame(const User& user, const std::string keywordString) {
    //auto roomId = _connectionToRoomId.at(user.getConnection());
//    auto roomId = getCurrentRoomName(user.getConnection());
//    auto found = _roomIdToMiniGameConnectionsList.find(roomId);

//    return found->second;
}

//TODO FIX - getCurrentRoomName() is removed
bool GameService::verifyAnswer(const User& user, const int input) {
    //auto roomId = _connectionToRoomId.at(user.getConnection());
//    auto roomId = getCurrentRoomName(user.getConnection());
//    auto result = _roomIdToMiniGameConnectionsList.find(roomId);
//    auto correctAnswer = result->second.checkAnswer(input);
//    result->second.nextRound();

//    return correctAnswer;
}

//========================= Avatar Service =============================

std::vector<ID> GameService::getAllAvatarIds(ID roomId) {
    return _avatarService.getAllAvatarIds(roomId);
};

const ID& GameService::getRoomId(const ID& avatarId){
    return _avatarService.getRoomId(avatarId);
}