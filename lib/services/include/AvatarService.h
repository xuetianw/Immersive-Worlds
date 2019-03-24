#ifndef WEBSOCKETNETWORKING_AVATARSERVICE_H
#define WEBSOCKETNETWORKING_AVATARSERVICE_H

#include "DataStorageService.h"
#include "Avatar.h"
#include "ID.h"

using Avatar = models::Avatar;

class AvatarService {
public:
    AvatarService() = default;

    explicit AvatarService(DataStorageService& dataStorageService)
        : _dataStorageService(dataStorageService) {

    }

    bool generateAvatarFromAvatarId(const ID& avatarId, const ID& roomId, const std::string& avatarName);

    bool generateAvatarFromAvatarId(const ID& avatarId, const std::string& avatarName);

    const Avatar& getAvatar(const ID& avatarId);

    const ID& getRoomId(const ID& avatarId);

    std::vector<ID> getAllAvatarIds(const ID& roomId);

private:
    //map of Avatar IDs to Avatar objects
    std::unordered_map<ID, std::unique_ptr<Avatar>> _avatars;
    DataStorageService _dataStorageService;

    void loadFromStorage();
};


#endif //WEBSOCKETNETWORKING_AVATARSERVICE_H
