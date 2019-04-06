//
// Created by Jan Ycasas on 2019-03-28.
//

#include <gtest/gtest.h>
#include "MiniGameActions.h"

using namespace models;
struct MiniGameActionsTest : testing::Test{
    DataStorageService storage;
    RoomConnectionService roomConnection{storage};
    MiniGameActions minigameActions{storage, roomConnection};

    std::unordered_map<int, ID> jsonIdToRoomId = storage.getJsonIdToRoomIdCopy();
};

TEST_F(MiniGameActionsTest, miniGameStart){
    int startingRoomId = 10609;
    auto roomId = jsonIdToRoomId.find(startingRoomId);

    EXPECT_TRUE(minigameActions.roomHaveMiniGame(roomId->second));
    EXPECT_FALSE(minigameActions.verifyAnswer(roomId->second, 0));

    minigameActions.nextRound(roomId->second);
    EXPECT_TRUE(minigameActions.hasMoreRounds(roomId->second));

    EXPECT_TRUE(minigameActions.verifyAnswer(roomId->second, 2));

    minigameActions.nextRound(roomId->second);
    EXPECT_FALSE(minigameActions.hasMoreRounds(roomId->second));
}