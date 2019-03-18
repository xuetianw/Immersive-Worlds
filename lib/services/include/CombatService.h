//
// Created by Nirag Mehta on 2019-03-08.
//

#ifndef WEBSOCKETNETWORKING_COMBATSERVICE_H
#define WEBSOCKETNETWORKING_COMBATSERVICE_H

#include <vector>

#include "Room.h"
#include "Avatar.h"

using namespace std;
using namespace models;

struct combatRound{
    int roundNumber;
    int damageDealtByPlayer;
    int damageDealtByNPC;
};


/*
 * class for combat logic
 */
class CombatLogic{

private:

    static int fightsInitialized;

    vector<combatRound> rounds;
    Avatar& player;
    Avatar& NPC;
    Room battleRoom;

    //obtain value from global config file
    constexpr static int heartBeatCount = 100;
    int roundCount;

public:

    CombatLogic(Avatar &player, Avatar &NPC);

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

    vector<combatRound> &getRounds();

    void setRounds(const vector<combatRound> &rounds);

    Avatar &getPlayer();

    void setPlayer(const Avatar &player);

    Avatar &getNPC();

    void setNPC(const Avatar &NPC);

};

#endif //WEBSOCKETNETWORKING_COMBATSERVICE_H


