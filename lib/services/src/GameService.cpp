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

    const std::optional<std::reference_wrapper<const Avatar>> avatar = _avatarService.getAvatarFromAvatarId(avatarId);
    const ID& currentAvatarRoomId = avatar->get().getRoomId();
    const std::optional<std::reference_wrapper<const ID>> neighbourId = _roomConnectionService.getNeighbourId(
        currentAvatarRoomId, directionString);

    if (!neighbourId) {
        return false;
    }

    return _avatarService.setAvatarRoomId(avatarId, neighbourId.value());
}

bool GameService::userYell(const User& user, const std::string& messageString) {
    return false;
}

string GameService::getCurrentRoomName(const Connection& connection) {
    const ID& roomId = _connectionToRoomId[connection];
    auto roomIter = _roomIdToRoom.find(roomId);
    return roomIter != _roomIdToRoom.end() ? roomIter->second.getName() : "";
}

bool GameService::spawnAvatarInStartingRoom(const ID& avatarId) {
    const ID& startingRoomID = _roomConnectionService.getStartingRoom();

    return _avatarService.generateAvatarFromAvatarId(avatarId, startingRoomID, "SOMENAME"); //TODO input avatar name
}

std::optional<std::string> GameService::getAvatarRoomName(const ID& avatarId) {
    if (!_avatarService.doesAvatarExist(avatarId)) {
        return std::nullopt;
    }

    const std::optional<std::reference_wrapper<const Avatar>> avatar = _avatarService.getAvatarFromAvatarId(avatarId);
    const ID& avatarRoomId = avatar->get().getRoomId();

    std::optional<std::string> avatarRoomName = _roomConnectionService.getRoomName(avatarRoomId);

    return avatarRoomName.value();
}

const Room* GameService::getRoomByName(const string& roomName) const {
    for(const auto& room : _roomIdToRoom) {
        if(room.second.getName() == roomName) {
            return &room.second;
        }
    }
    return nullptr;
}

bool GameService::roomHaveMiniGame(const User& user) {
    auto roomName = getCurrentRoomName(user.getConnection());
    return roomName != "";
}

models::MiniGame GameService::getMiniGame(const User& user, const std::string keywordString) {
    //auto roomId = _connectionToRoomId.at(user.getConnection());
    auto roomId = getCurrentRoomName(user.getConnection());
    auto found = _roomIdToMiniGameConnectionsList.find(roomId);

    return found->second;
}

bool GameService::verifyAnswer(const User& user, const int input) {
    //auto roomId = _connectionToRoomId.at(user.getConnection());
    auto roomId = getCurrentRoomName(user.getConnection());
    auto result = _roomIdToMiniGameConnectionsList.find(roomId);
    auto correctAnswer = result->second.checkAnswer(input);
    result->second.nextRound();

    return correctAnswer;
}

//========================= Avatar Service =============================

std::vector<ID> GameService::getAllAvatarIds(ID roomId) {
    return _avatarService.getAllAvatarIds(roomId);
};

const ID& GameService::getRoomId(const ID& avatarId){
    return _avatarService.getRoomId(avatarId);
};