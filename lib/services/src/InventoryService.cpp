//
// Created by asim on 25/03/19.
//

#include "InventoryService.h"

const std::optional<std::reference_wrapper<const Object>>
InventoryService::getObjectById(const ID& objectId) const {
    if(!doesObjectExist(objectId)) {
        return std::nullopt;
    }

    return _objects.at(objectId);
}

std::vector<Object*> InventoryService::getObjectsByAvatarId(const ID& avatarId) const {
    return std::vector<Object*>{};
}

std::vector<Object*> InventoryService::getObjectsByRoomId(const ID& roomId) const {
    return std::vector<Object*>{};
}

void InventoryService::addObjectToRoom(const ID& roomId, const ID& objectId) {
    _roomIdToObjectIds[roomId].emplace(objectId);
}

void InventoryService::giveObjectToAvatar(const ID& avatarId, const ID& objectId) {
    _avatarIdToObjectIds[avatarId].emplace(objectId);
}

void InventoryService::removeObjectFromRoom(const ID& roomId, const ID& objectId) {
    auto roomIter = _roomIdToObjectIds.find(roomId);

    if(roomIter != _roomIdToObjectIds.end()) {
        roomIter->second.erase(objectId);
    }
}

void InventoryService::takeObjectFromAvatar(const ID& avatarId, const ID& objectId) {
    auto avatarIter = _avatarIdToObjectIds.find(avatarId);

    if(avatarIter != _avatarIdToObjectIds.end()) {
        avatarIter->second.erase(objectId);
    }
}

bool InventoryService::doesObjectExist(const ID& objectId) const {
    return _objects.count(objectId) != 0;
}

// PRIVATE
void InventoryService::loadFromStorage() {

}