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

    //creates an avatar and adds it to the avatar map
    bool generateAvatarFromAvatarId(const ID& avatarId, const ID& roomId, const std::string& avatarName, bool isPlayable);

    //Returns an Avatar object of an avatarId
    const std::optional<std::reference_wrapper<models::Avatar>> getAvatarFromAvatarId(const ID& avatarId);

    //sets the room for an avatar
    bool setAvatarRoomId(const ID& avatarId, const ID& roomId);

    //checks avatars map if avatarId exists
    bool doesAvatarExist(const ID& avatarId);

    const ID& getRoomId(const ID& avatarId);

    std::vector<ID> getAllAvatarIds(const ID& roomId);

    //set the confuse state of an avatar
    bool setAvatarConfuseState(const ID& avatarId, bool isConfused);

    //get the confuse state of an avatar
    bool getAvatarConfuseState(const ID& avatarId);

private:
    //map of Avatar IDs to Avatar objects
    std::unordered_map<ID, std::unique_ptr<Avatar>> _avatars;
    DataStorageService& _dataStorageService;

    //TODO implement
    void loadFromStorage();
};


#endif //WEBSOCKETNETWORKING_AVATARSERVICE_H
