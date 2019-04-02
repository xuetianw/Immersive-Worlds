//
// Created by asim on 25/03/19.
//

#include <GameActions.h>

#include "GameActions.h"

using models::RoomConnection;

bool GameActions::moveAvatar(const ID& avatarId, const string& directionString) {
    if (!_avatarService.doesAvatarExist(avatarId)) {
        return false;
    }

    const std::optional<std::reference_wrapper<Avatar>> avatarOptional = _avatarService.getAvatarFromAvatarId(
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


std::vector<string> GameActions::getDirectionsForAvatarId(const ID& avatarId) {
    std::vector<string> response;

    if (!_avatarService.doesAvatarExist(avatarId)) {
        return response;
    }

    //get the Avatar object
    const std::optional<std::reference_wrapper<Avatar>> avatarOptional =
            _avatarService.getAvatarFromAvatarId(avatarId);

    //get the room ID of the Avatar
    const ID& currentAvatarRoomId = avatarOptional->get().getRoomId();

    //get the available directions for the room ID
    response = _roomConnectionService.getAvailableRoomDirections(currentAvatarRoomId);

    return response;
};


bool GameActions::spawnAvatarInStartingRoom(const ID& avatarId) {
    const ID& startingRoomID = _roomConnectionService.getStartingRoom();
    //TODO retrive avatar name from the database
    return _avatarService.generateAvatarFromAvatarId(avatarId, startingRoomID, "AVATAR NAME");
}

std::optional<std::string> GameActions::getAvatarRoomName(const ID& avatarId) {
    if (!_avatarService.doesAvatarExist(avatarId)) {
        return std::nullopt;
    }

    const std::optional<std::reference_wrapper<Avatar>> avatarOptional = _avatarService.getAvatarFromAvatarId(
            avatarId);
    const ID& avatarRoomId = avatarOptional->get().getRoomId();

    std::optional<std::string> avatarRoomName = _roomConnectionService.getRoomName(avatarRoomId);

    return avatarRoomName.value();
}

std::vector<ID> GameActions::getAllAvatarIdsInNeighbourAndCurrent(ID roomId) {

    std::vector<ID> currAvatars;
    std::vector<ID> neighbours;

    std::vector<ID> avatars = getAllAvatarIds(roomId);

    neighbours = _roomConnectionService.getAllNeighbourId(roomId);

    for (const ID& neighbourId : neighbours) {
        currAvatars = getAllAvatarIds(neighbourId);
        avatars.insert(avatars.end(), currAvatars.begin(), currAvatars.end());
    }
    return avatars;
}

//========================= Avatar Service =============================

std::vector<ID> GameActions::getAllAvatarIds(ID roomId) {
    return _avatarService.getAllAvatarIds(roomId);
};

const ID& GameActions::getRoomId(const ID& avatarId) {
    return _avatarService.getRoomId(avatarId);
}

std::string GameActions::displayAvatarinfoFromID(const ID& id) {
    std::optional<std::reference_wrapper<const Avatar>> avatar = _avatarService.getAvatarFromAvatarId(id);

    auto userAvatar = avatar.value().get();
    std::string response = "name :" + userAvatar.getName() + "\n"
                           + "_hp: " + std::to_string(userAvatar.get_hp()) + "\n"
                           + "_mana: " + std::to_string(userAvatar.get_mana()) + "\n";
    return response;
}

std::vector<Message> GameActions::swapAvatar(const Message& message) {
    std::string response;
    std::vector<ID> allAvatarIds = getAllAvatarIds(_avatarService.getAvatarFromAvatarId(message.user.getAvatarId()).value().get().getRoomId());
    auto it = std::find(allAvatarIds.begin(), allAvatarIds.end(), message.user.getAvatarId());
    allAvatarIds.erase(it);
    if (allAvatarIds.empty()) {
        response = "there is no avatar available currently in the room, use look command to check";
    } else {
        message.user.setAvatarId(allAvatarIds.at(0));
        response = "swapped successfully";
    }

    return std::vector<Message>{Message(message.user, response)};
}

std::vector<std::string> GameActions::getAllAvatarsNamesForRoomId(const ID& roomId){
    std::vector<ID> avatarIds = _avatarService.getAllAvatarIds(roomId);
    std::vector<std::string> avatarsNames{};

    for (const ID& avatarId : avatarIds) {
        Avatar& avatar = _avatarService.getAvatarFromAvatarId(avatarId)->get();
        avatarsNames.push_back(avatar.getName());
    }

    return avatarsNames;
}
