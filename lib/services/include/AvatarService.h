#ifndef WEBSOCKETNETWORKING_AVATARSERVICE_H
#define WEBSOCKETNETWORKING_AVATARSERVICE_H

#include "DataStorageService.h"
#include "Avatar.h"
#include "ID.h"

using Avatar = models::Avatar;

class AvatarService {
public:
    explicit AvatarService(DataStorageService& dataStorageService)
        : _dataStorageService(dataStorageService) {

    }

    bool generateAvatarFromAvatarId(const ID& avatarId, const ID& roomId, const std::string& avatarName);

    const std::optional<std::reference_wrapper<const models::Avatar>> getAvatarFromAvatarId(const ID& avatarId);

    bool setAvatarRoomId(const ID& avatarId, const ID& roomId);

    bool doesAvatarExist(const ID& avatarId);

    const ID& getRoomId(const ID& avatarId);

    std::vector<ID> getAllAvatarIds(const ID& roomId);

private:
    //map of Avatar IDs to Avatar objects
    std::unordered_map<ID, std::unique_ptr<Avatar>> _avatars;
    DataStorageService _dataStorageService;

    void loadFromStorage();
};


#endif //WEBSOCKETNETWORKING_AVATARSERVICE_H
