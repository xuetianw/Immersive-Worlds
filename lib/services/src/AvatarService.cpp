#include "AvatarService.h"

/*
 * PUBLIC
 */

bool AvatarService::generateAvatarFromAvatarId(const ID& avatarId, const ID& roomId, const std::string& avatarName) {

    std::unique_ptr<Avatar> avatar = std::make_unique<Avatar>(avatarId, roomId, avatarName);

    _avatars.try_emplace(avatarId, std::move(avatar));

    return true;
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