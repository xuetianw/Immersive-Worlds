//
// Created by Nirag Mehta on 2019-03-12.
//

#include "CombatService.h"

bool CombatService::createCombat(Avatar& player, Avatar& NPC) {
    if(_combatMap.find(player.getAvatarId()) != _combatMap.end()){
        return false;
    }

    //create Combat
    Combat combat{player, NPC};
    _combatMap.insert(std::pair<ID, Combat>(player.getAvatarId(), combat));

    ++fightsInitialized;

    return true;
}

void CombatService::destroyCombat(Avatar &player) {
    //removes combat object from map
    _combatMap.erase(player.getAvatarId());
}


