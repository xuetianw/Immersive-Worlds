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

const models::Avatar& AvatarService::getAvatarFromAvatarId(const ID& avatarId) {
    Avatar& avatar = *(_avatars.at(avatarId));

    return avatar;
}
