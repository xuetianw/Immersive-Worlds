#include "AvatarService.h"

/*
 * PUBLIC
 */

bool AvatarService::generateAvatarFromAvatarId(const ID& avatarId, const ID& roomId, const std::string& avatarName) {
    if (_avatars.count(avatarId) != 0) {
        return false;
    }

    std::unique_ptr<Avatar> avatar = std::make_unique<Avatar>(avatarId, roomId, avatarName);

    _avatars.try_emplace(avatarId, std::move(avatar));

    return true;
}


bool AvatarService::generateAvatarFromAvatarId(const ID &id, const std::string& avatarName) {
    _avatars.insert(std::make_pair(id, std::make_unique<Avatar>(id, avatarName)));
    return false;
}



const Avatar& AvatarService::getAvatar(const ID& avatarId) {
    Avatar& avatar = *(_avatars.at(avatarId));

    return avatar;
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