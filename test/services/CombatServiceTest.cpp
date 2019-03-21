//
// Created by Nirag Mehta on 2019-03-12.
//

#include <gtest/gtest.h>
#include "CombatService.h"
#include "Avatar.h"

using namespace models;
struct CombatServiceTest : testing::Test{


    Avatar player{ ID(1), "John"};
    Avatar NPC{ ID(2), "Kevin"};

    CombatLogic combatLogic{player, NPC};
};

TEST_F(CombatServiceTest, combatTest){

    combatLogic.getPlayer().set_hp(100);
    combatLogic.getPlayer().setDamageOutput(30);
    combatLogic.getNPC().set_hp(100);
    combatLogic.getNPC().setDamageOutput(20);

    combatLogic.fightRound();
    combatLogic.fightRound();
    combatLogic.fightRound();

    EXPECT_TRUE(combatLogic.isCombatActive());
    combatLogic.fightRound();
    EXPECT_FALSE(combatLogic.isCombatActive());

}