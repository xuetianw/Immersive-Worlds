//
// Created by Nirag Mehta on 2019-03-12.
//
#include "../include/CombatActions.h"

bool CombatActions::performCombatRound(ID& playerID) {

    Combat& combat = _combatMap.at(playerID);

    //commented out for now because fake NPC does not have a room ID
//    if(!isAttackValid(combat.get_player(), combat.get_NPC()))
//        return false;


    //if all goes well then fight round
    combat.fightRound();

    return true;
}

bool CombatActions::isAttackValid(Avatar& player, Avatar& NPC) {

    //compares room ID pointers
    if(player.getRoomId() != NPC.getRoomId())
        return false;

    return true;
}

std::string CombatActions::displayCombatDetails(ID& playerID) {

    Combat& combat = _combatMap.at(playerID);
    return combat.getCombatInfo();
}

bool CombatActions::isCombatActive(ID& playerID) {

    Combat& combat = _combatMap.at(playerID);
    return (combat.isCombatInProgress());
}

bool CombatActions::checkAndCreateCombat(ID& playerId, ID& NPCId) {
    if(_combatMap.find(playerId) != _combatMap.end()){
        //combat already exists for User Avatar
        return true;
    }

    auto playerOptional = _avatarService.getAvatarFromAvatarId(playerId);
    auto NPCOptional = _avatarService.getAvatarFromAvatarId(NPCId);

    if(!playerOptional.has_value() || !NPCOptional.has_value()){
        //user or NPC does not exist
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

bool CombatActions::destroyCombat(ID& playerId) {
    //removes combat object from map
    if(_combatMap.find(playerId) == _combatMap.end()){
        return false;
    }
    _combatMap.erase(playerId);

    return true;
}

const ID& CombatActions::getNPCID() const {
    return NPCID;
}


