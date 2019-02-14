//
// Created by Owner on 1/18/2019.
//

#ifndef WEBSOCKETNETWORKING_CHARACTER_H
#define WEBSOCKETNETWORKING_CHARACTER_H

const int MAX_HP = 200;
const int MAX_MANA = 150;

#include <string>
#include "Room.h"
#include "Inventory.h"

class Character {
protected:
	int id;
	std::string name;
	unsigned int hp = MAX_HP;
	unsigned int mana = MAX_MANA;

	channel::Room currentRoom;
	char* shortDesc;
	char* longDesc;
	Inventory characterInventory;
	char* tellCommandMessages; //eventually should be a buffer of Message objects for character-to-character messaging

};


#endif //WEBSOCKETNETWORKING_CHARACTER_H
