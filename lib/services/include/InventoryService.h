//
// Created by asim on 25/03/19.
//

#ifndef WEBSOCKETNETWORKING_INVENTORYSERVICE_H
#define WEBSOCKETNETWORKING_INVENTORYSERVICE_H

#include <unordered_map>
#include <unordered_set>

#include "ID.h"
#include "Object.h"
#include "DataStorageService.h"

using namespace models;

class InventoryService {
public:
    explicit InventoryService(DataStorageService& dataStorageService)
    : _dataStorageService(dataStorageService) {
            loadFromStorage();
    }

    const std::optional<std::reference_wrapper<const Object>>
    getObjectById(const ID& objectId) const;

    std::vector<Object*> getObjectsByAvatarId(const ID& avatarId) const;

    std::vector<Object*> getObjectsByRoomId(const ID& roomId) const;

    void addObjectToRoom(const ID& roomId, const ID& objectId);

    void giveObjectToAvatar(const ID& avatarId, const ID& objectId);

    void removeObjectFromRoom(const ID& roomId, const ID& objectId);

    void takeObjectFromAvatar(const ID& avatarId, const ID& objectId);

    bool doesObjectExist(const ID& objectId) const;

private:
    void loadFromStorage();

    DataStorageService& _dataStorageService;

    std::unordered_map<ID, Object> _objects;

    std::unordered_map<ID, std::unordered_set<ID>> _roomIdToObjectIds;

    std::unordered_map<ID, std::unordered_set<ID>> _avatarIdToObjectIds;
};

#endif //WEBSOCKETNETWORKING_INVENTORYSERVICE_H
