#include "AvatarService.h"

/*
 * PUBLIC
 */

void AvatarService::generateAvatarFromAvatarId(const ID& avatarId, const ID& roomId, const std::string& avatarName) {
    std::unique_ptr<Avatar> avatar = std::make_unique<Avatar>(Avatar{avatarId, roomId, avatarName});
    _avatars.try_emplace(avatarId, std::move(avatar));
}

const models::Avatar& AvatarService::getAvatarFromAvatarId(const ID& avatarId) {
    Avatar& avatar = *(_avatars.at(avatarId));

    return avatar;
}
