//
// Created by Nirag Mehta on 2019-03-12.
//

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
