#ifndef WEBSOCKETNETWORKING_AVATARSERVICE_H
#define WEBSOCKETNETWORKING_AVATARSERVICE_H

#include "DataStorageService.h"
#include "Avatar.h"
#include "ID.h"


class AvatarService {
public:
    AvatarService() = default;;

    explicit AvatarService(DataStorageService& dataStorageService)
        : _dataStorageService(dataStorageService) {

    }

    bool generateAvatarFromAvatarId(const int& avatarId, const ID& roomId, const std::string& avatarName);

    bool generateAvatarFromAvatarId(const int avatarId, const std::string& avatarName);

    const models::Avatar& getAvatar(const int& avatarId);

    const ID& getRoomId(const int& avatarId);

    std::vector<int> getAllAvatarIds(const ID& roomId);

private:
    //map of Avatar IDs to Avatar objects
    std::unordered_map<int, std::unique_ptr<models::Avatar>> _avatars;
    DataStorageService _dataStorageService;

    void loadFromStorage();
};


#endif //WEBSOCKETNETWORKING_AVATARSERVICE_H
