#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "RoomConnectionService.h"
#include "DataStorageStub.h"

using ::testing::InSequence;
using testing::Return;

struct RoomConnectionServiceTests : testing::Test {
    void SetUp() override {

    }

    void TearDown() override {

    }
};

TEST_F(RoomConnectionServiceTests, RoomConnectionServiceTestsOne) {
    DataStorageStub dataStorageStub{};

    EXPECT_CALL(dataStorageStub, getRoomIdToRoomMapCopy())
        .WillOnce(Return(std::unordered_map<ID, models::Room>{}));

    EXPECT_CALL(dataStorageStub, getRoomIdToNeighboursMapCopy())
        .WillOnce(Return(std::unordered_map<ID, std::vector<models::NeighbourInfo>>()));

    RoomConnectionService roomConnectionService(dataStorageStub);

    EXPECT_TRUE(1 == 1);

}

int main(int argc, char** argv) {
    // The following line must be executed to initialize Google Mock
    // (and Google Test) before running the tests.
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}