//
// Created by Nirag Mehta on 2019-03-12.
//

#include "../include/CombatActions.h"

bool CombatActions::createCombat(ID playerId, ID NPCId) {
    if(_combatMap.find(playerId) != _combatMap.end()){
        return false;
    }

    auto playerOptional = _avatarService.getAvatarFromAvatarId(playerId);
    auto NPCOptional = _avatarService.getAvatarFromAvatarId(NPCId);

    if(!playerOptional.has_value() || !NPCOptional.has_value()){
        return false;
    }
    Avatar& player = playerOptional->get();
    Avatar& NPC = NPCOptional->get();

    //create Combat
    Combat combat{player, NPC};
    _combatMap.insert(std::pair<ID, Combat>(playerId, combat));

    ++fightsInitialized;

    return true;
}

bool CombatActions::destroyCombat(ID playerId) {
    //removes combat object from map
    if(_combatMap.find(playerId) != _combatMap.end()){
        return false;
    }
    _combatMap.erase(playerId);

    return true;
}


