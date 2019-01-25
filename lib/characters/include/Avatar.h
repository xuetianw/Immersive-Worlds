//
// Created by Owner on 1/18/2019.
//

#ifndef WEBSOCKETNETWORKING_AVATAR_H
#define WEBSOCKETNETWORKING_AVATAR_H

#include "NonUserCharacter.h"
#include "character.h"

class Avatar : public Character
{
private:
	/** A unique int identifying the character
	 *
	 */
	int userID; //this will eventually be a User type object
	void takeObject(Object object);
	void putObject(Object object, Object containerObject);
	void dropObject(Object object);
	void giveObject(Object object, Character receivingCharacter);
	int wearObject(Object object);
	int removeObject(Object object);
	void attack(NonUserCharacter characterToAttack); //eventually make this a character, not necessarily an npc >:)
	void kill(NonUserCharacter characterToKill);
	void flee();
};


#endif //WEBSOCKETNETWORKING_AVATAR_H
