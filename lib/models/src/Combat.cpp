//
// Created by Nirag Mehta on 2019-03-19.
//
#include <Combat.h>

#include "Combat.h"

void Combat::attackNpc() {
    int updated_NPCHealth = _NPC.get_hp();
    updated_NPCHealth = updated_NPCHealth - _player.getDamageOutput();

    if(updated_NPCHealth <= 0) {
        _NPC.set_hp(0);
    }
    else {
        _NPC.set_hp(updated_NPCHealth);
    }
}

void Combat::receiveDamage() {
    int updatedPlayerHealth = _player.get_hp();
    updatedPlayerHealth = updatedPlayerHealth - _NPC.getDamageOutput();

    if(updatedPlayerHealth <= 0) {
        _player.set_hp(0);
    }
    else {
        _player.set_hp(updatedPlayerHealth);
    }
}

/*
 * structured this way because we attack first
 * and only if the _NPC is alive do we receive damage
 */
void Combat::fightRound() {

    attackNpc();
    if(!isCombatActive()){
        //_NPC is dead, cannot attack dead Avatar
        _combatInProgress = false;
        ++_roundCount;
        return;
    }
    receiveDamage();

    if(!isCombatActive()){
        //Player Avatar is dead
        _combatInProgress = false;
    }
    ++_roundCount;
}

std::string Combat::getCombatInfo() {

    std::string combatDetails;
    string playerHp = std::to_string(_player.get_hp());
    string NPCHp = std::to_string(_NPC.get_hp());
    combatDetails = "Your current hp is" + playerHp +
            "\nNPC's current hp is" + NPCHp + "\n";

    return combatDetails;
}

bool Combat::isCombatActive() {
    return (_player.get_hp() > 0 && _NPC.get_hp() > 0);
}

//getters and setters

int Combat::getRoundCount() const {
    return _roundCount;
}

void Combat::setRoundCount(int roundCount) {
    Combat::_roundCount = roundCount;
}

bool Combat::isCombatInProgress() const {
    return _combatInProgress;
}

const ID& Combat::get_combatId() const {
    return _combatId;
}

Avatar& Combat::get_player() const {
    return _player;
}

Avatar& Combat::get_NPC() const {
    return _NPC;
}
