//
// Created by Owner on 1/18/2019.
//

#ifndef WEBSOCKETNETWORKING_AVATAR_H
#define WEBSOCKETNETWORKING_AVATAR_H

#include <ContainerItem.h>
#include "InventoryItem.h"

class Avatar
{
private:
	/** A unique int identifying the character*/
	int userID; //this will eventually be a User type object

	/**
	 * Adds an InventoryItem to characterInventory.
	 * @param inventoryItem item to add to inventory
	 */
	void takeObject(InventoryItem inventoryItem);

	/**
	 * Puts an object into a ContainerItem
	 * @param inventoryItem item to put into ContainerItem
	 * @param containerObject container to place object in
	 */
	void putObject(InventoryItem inventoryItem, ContainerItem containerObject);

	/**
	 * Removes object from characterInventory and places it in currentRoom's inventory
	 * @param inventoryItem item to remove from inventory
	 */
	void dropObject(InventoryItem inventoryItem);

	/**
	 * Removes an object from the character's inventory and returns it
	 * @param inventoryItem item to remove
	 */
	InventoryItem giveObject(InventoryItem inventoryItem);


	int wearObject(InventoryItem inventoryItem);
	int removeObject(InventoryItem inventoryItem);
	void attack(Avatar characterToAttack);
	void kill(Avatar characterToKill);
	void flee();
};


#endif //WEBSOCKETNETWORKING_AVATAR_H
