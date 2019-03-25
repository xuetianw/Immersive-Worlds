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
    return std::vector<Object*&>{};
}

std::vector<Object*> InventoryService::getObjectsByRoomId(const ID& roomId) const {
    return std::vector<Object*>{};
}

void InventoryService::addObjectToRoom(const ID& roomId, Object item) {

}

void InventoryService::giveObjectToAvatar(const ID& avatarId, Object item) {

}

void InventoryService::removeObjectFromRoom(const ID& objectId) {

}

void InventoryService::takeObjectFromAvatar(const ID& objectID) {

}

bool InventoryService::doesObjectExist(const ID &objectId) const {
    return _objects.count(objectId) != 0;
}

// PRIVATE
void InventoryService::loadFromStorage() {

}