//
// Created by Nirag Mehta on 2019-03-08.
//

#ifndef WEBSOCKETNETWORKING_COMBATSERVICE_H
#define WEBSOCKETNETWORKING_COMBATSERVICE_H

#include <vector>


using namespace std;

struct combatRound{
    int roundNumber;
    int damageDealt;

};


/*
 * class for combat logic
 */
class CombatLogic{

private:

    vector<combatRound> rounds;


    //obtain value from global config file
    constexpr static int heartBeatCount = 100;
    int roundCounts;

public:

    /*
     * attacks a Character (User or NPC)
     */
    bool attack();

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
    bool validateCombatState();


};

#endif //WEBSOCKETNETWORKING_COMBATSERVICE_H


