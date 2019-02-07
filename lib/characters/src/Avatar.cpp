//
// Created by Owner on 1/18/2019.
//

#include "Avatar.h"
#include "ContainerItem.h"

void Avatar::takeObject(InventoryItem inventoryItem) {
	inventory.addItem(inventoryItem);
}

void Avatar::putObject(InventoryItem inventoryItem, ContainerItem containerObject) {
//TODO fix this when you pull Lucy's code
	//	 InventoryItem removedItem = characterInventory.removeItem(inventoryItem);

}

void Avatar::dropObject(InventoryItem inventoryItem) {
//	TODO: uncomment these lines after pulling Lucy's code and after implementing an inventory in a room
//	InventoryItem removedItem = characterInventory.removeItem(inventoryItem);
//	currentRoom.inventory.addItem(removedItem);
}


int Avatar::wearObject(SingleItem singleItem) {
	if (singleItem.getType() == SingleItem::ItemType::)
}

InventoryItem Avatar::removeObject(InventoryItem inventoryItem) {
	return inventory.removeItem(inventoryItem);
}
