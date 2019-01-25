//
// Created by Owner on 1/18/2019.
//

#ifndef WEBSOCKETNETWORKING_CHARACTER_H
#define WEBSOCKETNETWORKING_CHARACTER_H

#include <string>
#include "../../channel/include/Room.h"
#include "../../inventory/include/Inventory.h"

class Character {
protected:
	int id;
	std::string name;
	channel::Room currentRoom;
	char* shortDesc;
	char* longDesc;
	Inventory characterInventory;
	char* tellCommandMessages; //eventually should be a buffer of Message objects for character-to-character messaging
};


#endif //WEBSOCKETNETWORKING_CHARACTER_H
