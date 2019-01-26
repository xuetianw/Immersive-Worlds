//
// Created by Owner on 1/18/2019.
//

#include <Avatar.h>
#include <ContainerItem.h>

#include "../include/Avatar.h"

void Avatar::takeObject(InventoryItem inventoryItem) {

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

void Avatar::giveObject(InventoryItem inventoryItem, Character receivingCharacter) {
//	TODO uncomment these next lines once Lucy's code is pulled
//	Item removedItem = characterInventory.removeItem(inventoryItem);
//	receivingCharacter.characterInventory.addItem(removedItem);

}

int Avatar::wearObject(InventoryItem inventoryItem) {
	return 0;
}

int Avatar::removeObject(InventoryItem inventoryItem) {
	return 0;
}
