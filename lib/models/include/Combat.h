//
// Created by Nirag Mehta on 2019-03-19.
//

#ifndef WEBSOCKETNETWORKING_COMBAT_H
#define WEBSOCKETNETWORKING_COMBAT_H

#include "Avatar.h"
#include "Room.h"

using namespace models;

struct combatRound{
    int roundNumber;
    int damageDealtByPlayer;
    int damageDealtByNPC;
};

class Combat{

private:

    Avatar& player;
    Avatar& NPC;
    Room battleRoom;
    int roundCount;

public:

    Combat(Avatar &player, Avatar &NPC);

    /*
     * attacks an NPC
     */
    void attackNpc();

    /*
     * User takes damage from NPC
     */
    void receiveDamage();

    /*
     * attacks NPC and automatically receives damage from it
     */
    void fightRound();

    /*
     * function which outputs information of the combat state such as
     * -health of both players
     * -number of ingame combat rounds
     * -number of elapsed heartbeats
     */
    void displayCombatInfo();

    /*
     * function to determine if the combat state is still valid
     * i.e checks if either player is dead or if they decided to flee
     */
    bool isCombatActive();

    void updateRoundCount();

};

#endif //WEBSOCKETNETWORKING_COMBAT_H
