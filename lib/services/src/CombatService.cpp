//
// Created by Nirag Mehta on 2019-03-12.
//

#include "CombatService.h"

int fightsInitialized = 0;

bool CombatLogic::attackNpc() {
    int updatedNpcHealth = NPC.get_hp();
    int playerDamage = player.getDamageOutput();
    updatedNpcHealth = updatedNpcHealth - playerDamage;

    if(updatedNpcHealth < 0)
        NPC.set_hp(0);
    else
        NPC.set_hp(updatedNpcHealth);

}

bool CombatLogic::receiveDamage() {
    int updatedPlayerHealth = player.get_hp();
    int NpcDamage = NPC.getDamageOutput();
    updatedPlayerHealth = updatedPlayerHealth - NpcDamage;

    if(updatedPlayerHealth < 0)
        player.set_hp(0);
    else
        player.set_hp(updatedPlayerHealth);
}

void CombatLogic::displayCombatInfo() {

}

bool CombatLogic::isCombatActive() {

    if(player.get_hp() == 0 || NPC.get_hp() == 0)
        return false;
}


CombatLogic::CombatLogic(const Avatar &player, const Avatar &NPC) : player(player), NPC(NPC) {}
