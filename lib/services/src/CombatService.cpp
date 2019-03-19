//
// Created by Nirag Mehta on 2019-03-12.
//

#include <CombatService.h>

#include "CombatService.h"

void CombatService::createCombat(Avatar& player, Avatar& NPC) {

    if(combatMap.find(player.getAvatarId()) == combatMap.end()){

        //create Combat
        Combat combat{player, NPC};

        combat.enterCombat();
        combatMap.insert(std::pair<ID ,Combat&>(player.getAvatarId(), combat));
    }

    ++fightsInitialized;
}

void CombatService::destroyCombat(Avatar &player) {
    //removes combat object from map
    combatMap.erase(player.getAvatarId());
}

#include "CombatService.h"

static int fightsInitialized = 0;

//getters and setters

 Avatar &CombatLogic::getPlayer(){
    return player;
}

void CombatLogic::setPlayer(const Avatar &player) {
    CombatLogic::player = player;
}

Avatar &CombatLogic::getNPC(){
    return NPC;
}

void CombatLogic::setNPC(const Avatar &NPC) {
    CombatLogic::NPC = NPC;
}
