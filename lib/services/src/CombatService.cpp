//
// Created by Nirag Mehta on 2019-03-12.
//

#include "CombatService.h"

static int fightsInitialized = 0;

void CombatLogic::attackNpc() {
    int updatedNpcHealth = NPC.get_hp();
    updatedNpcHealth = updatedNpcHealth - player.getDamageOutput();

    if(updatedNpcHealth <= 0)
        NPC.set_hp(0);
    else
        NPC.set_hp(updatedNpcHealth);

}

void CombatLogic::receiveDamage() {
    int updatedPlayerHealth = player.get_hp();
    updatedPlayerHealth = updatedPlayerHealth - NPC.getDamageOutput();

    if(updatedPlayerHealth <= 0)
        player.set_hp(0);
    else
        player.set_hp(updatedPlayerHealth);
}

void CombatLogic::fightRound() {

    attackNpc();
    if(!isCombatActive()){
        //NPC is dead, cannot attack dead Avatar

    }
    receiveDamage();

    if(!isCombatActive()){
        //Player Avatar is dead

    }
}

void CombatLogic::displayCombatInfo() {

}

bool CombatLogic::isCombatActive() {
    return (player.get_hp() > 0 && NPC.get_hp() > 0);
}


CombatLogic::CombatLogic(Avatar &player, Avatar &NPC) : player(player), NPC(NPC) {}


//getters and setters
vector<combatRound> &CombatLogic::getRounds() {
    return rounds;
}

void CombatLogic::setRounds(const vector<combatRound> &rounds) {
    CombatLogic::rounds = rounds;
}

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
