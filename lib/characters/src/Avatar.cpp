//
// Created by Owner on 1/18/2019.
//

#include <Avatar.h>

#include "../include/Avatar.h"

void Avatar::takeObject(Object object) {

}

void Avatar::putObject(Object object, Object containerObject) {
//	TODO change after pulling
//	Item removedItem = characterInventory.removeItem(object);

}

void Avatar::dropObject(Object object) {
//	TODO: uncomment these lines after pulling Lucy's code and after implementing an inventory in a room
//	Item removedItem = characterInventory.removeItem(object);
//	currentRoom.inventory.addItem(removedItem);
}

void Avatar::giveObject(Object object, Character receivingCharacter) {
//	TODO uncomment these next lines once Lucy's code is pulled
//	Item removedItem = characterInventory.removeItem(object);
//	receivingCharacter.characterInventory.addItem(removedItem);

}

int Avatar::wearObject(Object object) {
	return 0;
}

int Avatar::removeObject(Object object) {
	return 0;
}
