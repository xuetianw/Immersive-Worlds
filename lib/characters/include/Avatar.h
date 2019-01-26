//
// Created by Owner on 1/18/2019.
//

#ifndef WEBSOCKETNETWORKING_AVATAR_H
#define WEBSOCKETNETWORKING_AVATAR_H

#include <ContainerItem.h>
#include "NonUserCharacter.h"
#include "character.h"
#include "InventoryItem.h"

class Avatar : public Character
{
private:
	/** A unique int identifying the character
	 *
	 */
	int userID; //this will eventually be a User type object
	void takeObject(InventoryItem inventoryItem); //adds Object object to Inventory
	void putObject(InventoryItem object, ContainerItem containerObject) ;
	void dropObject(InventoryItem inventoryItem);
	void giveObject(InventoryItem inventoryItem, Character receivingCharacter);
	int wearObject(InventoryItem inventoryItem);
	int removeObject(InventoryItem inventoryItem);
	void attack(NonUserCharacter characterToAttack);
	void kill(NonUserCharacter characterToKill);
	void flee();
};


#endif //WEBSOCKETNETWORKING_AVATAR_H
