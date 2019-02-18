//
// Created by Owner on 1/18/2019.
//

#include <Avatar.h>

#include "Avatar.h"
#include "ContainerItem.h"

void Avatar::takeItem(InventoryItem inventoryItem) {
	_inventory.addItem(inventoryItem);
}

void Avatar::putItem(InventoryItem inventoryItem, ContainerItem containerObject) {
	//TODO complete once adding to a containerItem is implemented
	//	containerObject.addItem(inventoryItem);

}

void Avatar::dropItem(InventoryItem inventoryItem) {
//	TODO: complete after implementing an _inventory in a room
	InventoryItem removedItem = removeItem(inventoryItem);
//	currentRoom._inventory.addItem(removedItem);
}


bool Avatar::wearItem(InventoryItem inventoryItem) {
	if (inventoryItem.getItemType() == InventoryItem::ItemType::CLOTHING) {
		InventoryItem clothingToRemove = _currentClothing;
		InventoryItem clothingToWear = removeItem(inventoryItem);
		_currentClothing = clothingToWear;
		_inventory.addItem(clothingToRemove);
		return true;
	}
	return false;
}

InventoryItem Avatar::removeItem(InventoryItem inventoryItem) {
	return _inventory.removeItem(inventoryItem.getId());
}

bool Avatar::isPlayable() {
	return _avatarType == AvatarType::PLAYABLE;
}

Avatar::Avatar(const Avatar::AvatarType avatarType, int userId)
		: _avatarType(avatarType), _userID(userId), _inventory(Inventory(_userID)) {
}
