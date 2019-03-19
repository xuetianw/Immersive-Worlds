//
// Created by Nirag Mehta on 2019-03-08.
//

#ifndef WEBSOCKETNETWORKING_COMBATSERVICE_H
#define WEBSOCKETNETWORKING_COMBATSERVICE_H

#include <vector>
#include <map>

#include "Room.h"
#include "Avatar.h"
#include "Combat.h"
<<<<<<< HEAD
using namespace models;
=======
>>>>>>> laid out basic combat framework

using namespace std;
using namespace models;


/*
 * class for combat logic
 */
class CombatService{

private:

<<<<<<< HEAD
    int fightsInitialized;
=======
    static int fightsInitialized;
>>>>>>> laid out basic combat framework

    //obtain value from global config file
    const static int heartBeatCount = 100;

<<<<<<< HEAD
    //data structure to map user Avatar to his/her own combat

    map<ID, Combat&> combatMap;

public:
=======
    //data structure to map an Avatar (user) to hiss/her own combat
    static map<Avatar, Combat> combatMap;

public:


>>>>>>> laid out basic combat framework

    void createCombat(Avatar &player, Avatar& NPC);
    void destroyCombat(Avatar &player);
};

#endif //WEBSOCKETNETWORKING_COMBATSERVICE_H


