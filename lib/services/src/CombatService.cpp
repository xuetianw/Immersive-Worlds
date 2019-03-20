//
// Created by Nirag Mehta on 2019-03-12.
//

#include <CombatService.h>

#include "CombatService.h"

void CombatService::createCombat(Avatar& player, Avatar& NPC) {

    if(combatMap.find(player.getAvatarId()) == combatMap.end()){

        //create Combat
        Combat combat{player, NPC};
        combatMap.insert(std::pair<ID ,Combat>(player.getAvatarId(), combat));
    }

    ++fightsInitialized;
}

void CombatService::destroyCombat(Avatar &player) {
    //removes combat object from map
    combatMap.erase(player.getAvatarId());
}
