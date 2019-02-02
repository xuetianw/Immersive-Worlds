//
// Created by Owner on 1/18/2019.
//

#include "Avatar.h"
#include "ContainerItem.h"

void Avatar::takeObject(InventoryItem inventoryItem) {

}

void Avatar::putObject(InventoryItem inventoryItem, ContainerItem containerObject) {
	InventoryItem removedItem = characterInventory.removeItem(inventoryItem);

}

void Avatar::dropObject(InventoryItem inventoryItem) {
//	TODO: uncomment these lines after pulling Lucy's code and after implementing an inventory in a room
	InventoryItem removedItem = characterInventory.removeItem(inventoryItem);
//	currentRoom.inventory.addItem(removedItem);
}

InventoryItem Avatar::giveObject(InventoryItem inventoryItem) {
	InventoryItem removedItem = characterInventory.removeItem(inventoryItem);
	return removedItem;

}

int Avatar::wearObject(SingleItem inventoryItem) {
	if (inventoryItem.getItemType() == SingleItem::ItemType::CLOTHING){
		SingleItem currentClothing = _currentClothing;
		//TODO: fix casting here?? HOW????
//		InventoryItem itemToWear = (SingleItem)characterInventory.removeItem(inventoryItem);
//		_currentClothing = itemToWear;
	}
}

int Avatar::removeObject(InventoryItem inventoryItem) {
	return 0;
}
