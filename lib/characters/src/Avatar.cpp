//
// Created by Owner on 1/18/2019.
//

#include "Avatar.h"
#include "ContainerItem.h"

void Avatar::takeItem(InventoryItem inventoryItem) {
	inventory.addItem(inventoryItem);
}

void Avatar::putItem(InventoryItem inventoryItem, ContainerItem containerObject) {

}

void Avatar::dropItem(InventoryItem inventoryItem) {
//	TODO: uncomment these lines after pulling Lucy's code and after implementing an inventory in a room
	InventoryItem removedItem = removeItem(inventoryItem);
//	currentRoom.inventory.addItem(removedItem);
}


bool Avatar::wearItem(InventoryItem inventoryItem) {
	if (inventoryItem.getItemType() == InventoryItem::ItemType::CLOTHING){
		InventoryItem clothingToRemove = _currentClothing;
		InventoryItem clothingToWear = removeItem(inventoryItem);
		_currentClothing = clothingToWear;
		inventory.addItem(clothingToRemove);
		return true;
	}
	return false;
}

InventoryItem Avatar::removeItem(InventoryItem inventoryItem) {
	return inventory.removeItem(inventoryItem.getId());
}
