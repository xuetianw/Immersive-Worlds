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

void InventoryService::addObjectToRoom(const ID& roomId, Object item) {

}

void InventoryService::giveObjectToAvatar(const ID& avatarId, Object item) {

}

void InventoryService::removeObjectFromRoom(const ID& roomId, const ID& objectId) {
    auto roomIter = _roomIdToObjectIds.find(roomId);

    if(roomIter != _roomIdToObjectIds.end()) {
        roomIter->second.erase(
                std::remove_if(roomIter->second.begin(), roomIter->second.end(),
                        [&](const ID& id) {
                            return objectId == id;
                }),
                roomIter->second.end()
        );
    }
}

void InventoryService::takeObjectFromAvatar(const ID& avatarId, const ID& objectID) {
    auto avatarIter = _avatarIdToObjectIds.find(avatarId);

    if(avatarIter != _avatarIdToObjectIds.end()) {
        avatarIter->second.erase(
                std::remove_if(avatarIter->second.begin(), avatarIter->second.end(),
                        [&](const ID& id){
                            return objectID == id;
                }),
                avatarIter->second.end()
        );
    }
}

bool InventoryService::doesObjectExist(const ID& objectId) const {
    return _objects.count(objectId) != 0;
}

// PRIVATE
void InventoryService::loadFromStorage() {

}