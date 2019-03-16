#include "AvatarService.h"

/*
 * PUBLIC
 */

bool AvatarService::generateAvatarFromAvatarId(const int& avatarId, const ID& roomId, const std::string& avatarName) {
    if (_avatars.count(avatarId) != 0) {
        return false;
    }

    std::unique_ptr<models::Avatar> avatar = std::make_unique<models::Avatar>(avatarId, roomId, avatarName);

    _avatars.try_emplace(avatarId, std::move(avatar));

    return true;
}


bool AvatarService::generateAvatarFromAvatarId(int id, const std::string& avatarName) {
    _avatars.insert(std::make_pair(id, std::make_unique<models::Avatar>(id, avatarName)));
    return false;
}



const models::Avatar& AvatarService::getAvatar(const int& avatarId) {
    models::Avatar& avatar = *(_avatars.at(avatarId));

    return avatar;
}

const ID& AvatarService::getRoomId(const int& avatarId){
    return _avatars.at(avatarId)->getRoomId();
}


std::vector<int> AvatarService::getAllAvatarIds(const ID& roomId) {
    std::vector<int> avatarIdsInRoom;

    for(auto const& [id, avatar] : _avatars){
        if(avatar->getRoomId() == roomId){
            avatarIdsInRoom.push_back(id);
        }
    }
    return avatarIdsInRoom;
}