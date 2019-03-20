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
using namespace models;

using namespace std;
using namespace models;


/*
 * class for combat logic
 */
class CombatService{

private:

    int fightsInitialized;

    //obtain value from global config file
    const static int heartBeatCount = 100;

    //data structure to map user Avatar to his/her own combat

    map<ID, Combat> combatMap;

public:

    void createCombat(Avatar &player, Avatar& NPC);
    void destroyCombat(Avatar &player);
};

#endif //WEBSOCKETNETWORKING_COMBATSERVICE_H


