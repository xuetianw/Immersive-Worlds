//
// Created by Nirag Mehta on 2019-03-19.
//

#include "Combat.h"

void Combat::attackNpc() {
    int updatedNpcHealth = NPC.get_hp();
    updatedNpcHealth = updatedNpcHealth - player.getDamageOutput();

    if(updatedNpcHealth <= 0)
        NPC.set_hp(0);
    else
        NPC.set_hp(updatedNpcHealth);

}

void Combat::receiveDamage() {
    int updatedPlayerHealth = player.get_hp();
    updatedPlayerHealth = updatedPlayerHealth - NPC.getDamageOutput();

    if(updatedPlayerHealth <= 0)
        player.set_hp(0);
    else
        player.set_hp(updatedPlayerHealth);
}

void Combat::fightRound() {

    attackNpc();
    if(!isCombatActive()){
        //NPC is dead, cannot attack dead Avatar

    }
    receiveDamage();

    if(!isCombatActive()){
        //Player Avatar is dead

    }
}

void Combat::displayCombatInfo() {

}

bool Combat::isCombatActive() {
    return (player.get_hp() > 0 && NPC.get_hp() > 0);
}
