//
// Created by Owner on 1/18/2019.
//

#ifndef WEBSOCKETNETWORKING_AVATAR_H
#define WEBSOCKETNETWORKING_AVATAR_H


class Avatar : public Character {
public:
	int userID //this will eventually be a User type object
	void takeObject(int objectID); //adds Object object to Inventory
	void putObject(int objectID);
	void dropObject(int objectID);
	void giveObject(int objectID, Character receivingCharacter);
	int wearObject(int objectID);
	int removeObject(int objectID);
	void attack(NonUserCharacter characterToAttack);
	void kill(NonUserCharacter characterToKill);
	void flee();
};


#endif //WEBSOCKETNETWORKING_AVATAR_H
