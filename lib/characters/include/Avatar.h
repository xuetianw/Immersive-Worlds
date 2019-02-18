//
// Created by Owner on 1/18/2019.
//

#ifndef WEBSOCKETNETWORKING_AVATAR_H
#define WEBSOCKETNETWORKING_AVATAR_H

#include <ContainerItem.h>
#include <Inventory.h>
#include "InventoryItem.h"

class Avatar
{
private:
	enum class AvatarType{
		NON_PLAYABLE,
		PLAYABLE
	};
	AvatarType _avatarType;
	/** A unique int identifying the character*/
	int _userID; //this will eventually be a User type object
	/**
	 * Clothing item that the Avatar is currently wearing
	 */
	InventoryItem _currentClothing;
	Inventory _inventory;
	/**
	 * Adds an InventoryItem to characterInventory.
	 * @param inventoryItem item to add to inventory
	 */
	void takeItem(InventoryItem inventoryItem);

	/**
	 * Puts an object into a ContainerItem
	 * @param inventoryItem item to put into ContainerItem
	 * @param containerObject container to place object in
	 */
	void putItem(InventoryItem inventoryItem, ContainerItem containerObject);

	/**
	 * Removes object from characterInventory and places it in currentRoom's inventory
	 * @param inventoryItem item to remove from inventory
	 */
	void dropItem(InventoryItem inventoryItem);

	//TODO move "giving" an item up higher as it requires knowledge of another avatar

	bool wearItem(InventoryItem inventoryItem);
	InventoryItem removeItem(InventoryItem inventoryItem);
	void attack(Avatar characterToAttack);
	void kill(Avatar characterToKill);
	void flee();

public:
	Avatar(const AvatarType avatarType, int userId);
	bool isPlayable();
};


#endif //WEBSOCKETNETWORKING_AVATAR_H
