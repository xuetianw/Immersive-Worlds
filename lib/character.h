//
// Created by Owner on 1/18/2019.
//

#ifndef WEBSOCKETNETWORKING_CHARACTER_H
#define WEBSOCKETNETWORKING_CHARACTER_H


class Character {
public:
	int id;
	char* shortDesc;
	char* longDesc;
	int[] inventory;
	char* tellCommandMessages //eventually should be a buffer of Message objects for character-to-character messaging
};


#endif //WEBSOCKETNETWORKING_CHARACTER_H
