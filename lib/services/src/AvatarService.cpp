#include "AvatarService.h"

/*
 * PUBLIC
 */

bool AvatarService::generateAvatarFromAvatarId(const ID& avatarId, const ID& roomId, const std::string& avatarName, bool isPlayable) {
    if (doesAvatarExist(avatarId)) {
        return false;
    }

    std::unique_ptr<Avatar> avatar = std::make_unique<Avatar>(avatarId, roomId, avatarName, isPlayable);

    _avatars.try_emplace(avatarId, std::move(avatar));

    return true;
}

const std::optional<std::reference_wrapper<Avatar>>
AvatarService::getAvatarFromAvatarId(const ID& avatarId) {
    if (!doesAvatarExist(avatarId)) {
        return std::nullopt;
    }

    const std::unique_ptr<Avatar>& avatar = _avatars.at(avatarId);

    return std::optional<std::reference_wrapper<Avatar>>{*avatar};
}

bool AvatarService::setAvatarRoomId(const ID& avatarId, const ID& roomId) {
    if (!doesAvatarExist(avatarId)) {
        return false;
    }

    Avatar& avatar = *(_avatars.at(avatarId));
    avatar.setRoomId(roomId);

    return true;
}

bool AvatarService::doesAvatarExist(const ID& avatarId) {
    return _avatars.count(avatarId) != 0;
}

const ID& AvatarService::getRoomId(const ID& avatarId){
    return _avatars.at(avatarId)->getRoomId();
}


std::vector<ID> AvatarService::getAllAvatarIds(const ID& roomId) {
    std::vector<ID> avatarIdsInRoom;

    for(auto const& [id, avatar] : _avatars){
        if(avatar->getRoomId() == roomId){
            avatarIdsInRoom.push_back(id);
        }
    }
    return avatarIdsInRoom;
}

bool AvatarService::setAvatarConfuseState(const ID& avatarId, bool isConfused){
    if (!doesAvatarExist(avatarId)) {
        return false;
    }

    Avatar& avatar = *(_avatars.at(avatarId));
    avatar.setConfuseState(isConfused);

    return true;
}

bool AvatarService::getAvatarConfuseState(const ID& avatarId){
    if (!doesAvatarExist(avatarId)) {
        return false;
    }
    return _avatars.at(avatarId)->getConfuseState();
}