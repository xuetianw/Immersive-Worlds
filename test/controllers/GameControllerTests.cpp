#include "GameController.h"
#include "Server.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::Return;

constexpr char LEXIE_SHOP[] = "Lexie's Scuba Shop";

struct GameControllerTests : testing::Test {
    std::unique_ptr<GameController> gameController = std::make_unique<GameController>();
    networking::Connection connection{1};
    User user{connection};
};


TEST_F(GameControllerTests, SpawnUserInStartRoomTest) {
    // Assumption: Starting room is Lexie's shop
    std::string response = gameController->spawnAvatarInStartingRoom(user.getAccount().avatarId);

    EXPECT_EQ(INITIAL_ROOM_START_MESSAGE, response);
}
//TODO fix this test
TEST_F(GameControllerTests, OutputCurrentLocationInfoTest) {
    Message emptyMessage = Message{user, ""};

    // Assumption: Starting room is Lexie's shop
    gameController->spawnAvatarInStartingRoom(user.getAccount().avatarId);
    Message response = gameController->outputCurrentLocationInfo(emptyMessage)[0];

    EXPECT_EQ(string(USER_CURRENTLY_LOCATED_MESSAGE)
                  +string(LEXIE_SHOP), response.text);
}

//TODO add more unit tests involving moving avatars to different rooms.
