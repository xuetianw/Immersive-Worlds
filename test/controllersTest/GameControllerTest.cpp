#include "GameController.h"
#include "Server.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::Return;

constexpr char LEXIE_SHOP[] = "Lexie's Scuba Shop";

struct GameControllerTest : testing::Test {
    std::unique_ptr<GameController> gameController = std::make_unique<GameController>();
    networking::Connection connection{1};
    User user{connection};
};


TEST_F(GameControllerTest, SpawnUserInStartRoomTest) {
    // Assumption: Starting room is Lexie's shop
    Message response = gameController->spawnUserInRoomOnLogin(user);

    EXPECT_EQ(INITIAL_ROOM_START_MESSAGE, response.text);
}

TEST_F(GameControllerTest, OutputCurrentLocationInfoTest) {
    Message emptyMessage = Message{user, ""};

    // Assumption: Starting room is Lexie's shop
    gameController->spawnUserInRoomOnLogin(user);
    Message response = gameController->outputCurrentLocationInfo(emptyMessage);

    EXPECT_EQ(string(USER_CURRENTLY_LOCATED_MESSAGE) + string(LEXIE_SHOP), response.text);
}

//TODO add more unit tests involving moving avatars to different rooms.
