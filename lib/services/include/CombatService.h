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

using namespace std;
using namespace models;


/*
 * class for combat logic
 */
class CombatLogic{

private:

    static int fightsInitialized;

    //obtain value from global config file
    const static int heartBeatCount = 100;

    //data structure to map an Avatar (user) to hiss/her own combat
    static map<Avatar, Combat> combatMap;

public:



};

#endif //WEBSOCKETNETWORKING_COMBATSERVICE_H


