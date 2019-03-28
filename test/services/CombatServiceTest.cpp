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
    Combat combat{player, NPC};
};

TEST_F(CombatServiceTest, combatTest){


    combat.fightRound();
    combat.fightRound();
    combat.fightRound();

    EXPECT_TRUE(combat.isCombatActive());
    combat.fightRound();
    EXPECT_FALSE(combat.isCombatActive());

}