//
// Created by asim on 25/03/19.
//

#include "InventoryService.h"

Object* InventoryService::getObjectById(const ID& objectId) {
    if(!doesObjectExist(objectId)) {
        return nullptr;
    }

    return _objects[objectId].get();
}

std::vector<Object*> InventoryService::getObjectsByAvatarId(const ID& avatarId) {
    return getObjectsByEntity(_avatarIdToObjectIds, avatarId);
}

std::vector<Object*> InventoryService::getObjectsByRoomId(const ID& roomId) {
    return getObjectsByEntity(_roomIdToObjectIds, roomId);
}

void InventoryService::addObjectToRoom(const ID& roomId, const ID& objectId) {
    _roomIdToObjectIds[roomId].emplace(objectId);
}

void InventoryService::giveObjectToAvatar(const ID& avatarId, const ID& objectId) {
    _avatarIdToObjectIds[avatarId].emplace(objectId);
}

void InventoryService::removeObjectFromRoom(const ID& roomId, const ID& objectId) {
    removeObjectFromEntity(_roomIdToObjectIds, roomId, objectId);
}

void InventoryService::takeObjectFromAvatar(const ID& avatarId, const ID& objectId) {
    removeObjectFromEntity(_avatarIdToObjectIds, avatarId, objectId);
}

bool InventoryService::doesObjectExist(const ID& objectId) const {
    return _objects.count(objectId) != 0;
}

// PRIVATE
std::vector<Object*> InventoryService::getObjectsByEntity(std::unordered_map<ID, std::unordered_set<ID>> &objectIdMap,
                                                          const ID &entityId) {
    std::vector<Object*> objectsContainer;

    auto iter = objectIdMap.find(entityId);
    if(iter != objectIdMap.end()) {
        for(const auto& objectId : iter->second) {
            auto obj = getObjectById(objectId);

            if(obj) {
                objectsContainer.emplace_back(obj);
            }
        }
    }

    return objectsContainer;
}

void InventoryService::removeObjectFromEntity(std::unordered_map<ID, std::unordered_set<ID>> &objectIdMap,
                                                const ID &entityId, const ID& objectId) {
    auto iter = objectIdMap.find(entityId);

    if(iter != objectIdMap.end()) {
        iter->second.erase(objectId);
    }

}

void InventoryService::loadFromStorage() {

}