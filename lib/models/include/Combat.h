//
// Created by Nirag Mehta on 2019-03-19.
//

#ifndef WEBSOCKETNETWORKING_COMBAT_H
#define WEBSOCKETNETWORKING_COMBAT_H

#include "Avatar.h"
#include "Room.h"

using namespace models;

class Combat {

private:

    ID combatId;
    Avatar& _player;
    Avatar& _NPC;
    int roundCount = 0;
    bool combatInProgress = true;

    /*
    * function to determine if the combat state is still valid
    * i.e checks if either player is dead or if they decided to flee
    */
    bool isCombatActive();

public:

    Combat(Avatar& player, Avatar& NPC) :
            combatId(ID{}),
            _player(player),
            _NPC(NPC) {}

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
     * function which returns a string of information about the combat state such as
     * -health of both players
     * -number of in-game combat rounds
     * -number of elapsed heartbeats
     */
    std::string getCombatInfo();

    void updateRoundCount();

    int getRoundCount() const;

    void setRoundCount(int roundCount);

};

#endif //WEBSOCKETNETWORKING_COMBAT_H
