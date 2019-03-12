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

    const Avatar& getAvatarFromAvatarId(const ID& avatarId);

private:
    //map of Avatar IDs to Avatar objects
    std::unordered_map<ID, std::unique_ptr<Avatar>> _avatars;
    DataStorageService _dataStorageService;

    void loadFromStorage();
};


#endif //WEBSOCKETNETWORKING_AVATARSERVICE_H
