#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "RoomConnectionService.h"
#include "DataStorageStub.h"

using ::testing::InSequence;
using testing::Return;

using Room = models::Room;
using Direction = models::Direction;
using NeighbourInfo = models::NeighbourInfo;

/**
 * Adjacency List of Room Connections
 *
 *    1    2    3    4    5
 *   ----------
 * 1| 0    N    E    0    S
 *  |
 * 2| S    0    0    W    0
 *  |
 * 3| W    0    0    S    E
 *  |
 * 4| 0    E    N    0    0
 *  |
 * 5| N    0    W    0    0
 *
 */
constexpr char NORTH_STR[] = "north";
constexpr char SOUTH_STR[] = "south";
constexpr char EAST_STR[] = "east";
constexpr char WEST_STR[] = "west";

struct RoomConnectionServiceTests : testing::Test {
    DataStorageStub dataStorageStub{};
    std::unique_ptr<RoomConnectionService> roomConnectionService;
    ID startingRoomId{};

    void SetUp() override {
        std::unordered_map<ID, models::Room> rooms{};
        std::unordered_map<ID, std::vector<models::NeighbourInfo>> neighbours{};

        buildRoomConnections(startingRoomId, rooms, neighbours);

        EXPECT_CALL(dataStorageStub, getRoomIdToRoomMapCopy())
            .WillOnce(Return(rooms));

        EXPECT_CALL(dataStorageStub, getRoomIdToNeighboursMapCopy())
            .WillOnce(Return(neighbours));

        EXPECT_CALL(dataStorageStub, resetObjectsToWorld(::testing::_));

        roomConnectionService = std::make_unique<RoomConnectionService>(dataStorageStub);
    }

    void TearDown() override {

    }

    void buildRoomConnections(const ID& startingRoomId, std::unordered_map<ID, models::Room>& rooms,
                              std::unordered_map<ID, std::vector<models::NeighbourInfo>>& neighbours) {

        Room room1(startingRoomId, "Room One", std::vector<string>{"This is Room One"});
        Room room2(ID{}, "Room Two", std::vector<string>{"This is Room Two"});
        Room room3(ID{}, "Room Three", std::vector<string>{"This is Room Three"});
        Room room4(ID{}, "Room Four", std::vector<string>{"This is Room Four"});
        Room room5(ID{}, "Room Five", std::vector<string>{"This is Room Five"});

        std::vector<NeighbourInfo> room1neighbours{
            NeighbourInfo{Direction::NORTH, room2.getId(), std::vector<string>{}},
            NeighbourInfo{Direction::EAST, room3.getId(), std::vector<string>{}},
            NeighbourInfo{Direction::SOUTH, room5.getId(), std::vector<string>{}}

        };

        std::vector<NeighbourInfo> room2neighbours{
            NeighbourInfo{Direction::SOUTH, room1.getId(), std::vector<string>{}},
            NeighbourInfo{Direction::WEST, room4.getId(), std::vector<string>{}}

        };

        std::vector<NeighbourInfo> room3neighbours{
            NeighbourInfo{Direction::WEST, room1.getId(), std::vector<string>{}},
            NeighbourInfo{Direction::SOUTH, room4.getId(), std::vector<string>{}},
            NeighbourInfo{Direction::EAST, room5.getId(), std::vector<string>{}}
        };

        std::vector<NeighbourInfo> room4neighbours{
            NeighbourInfo{Direction::EAST, room2.getId(), std::vector<string>{}},
            NeighbourInfo{Direction::NORTH, room3.getId(), std::vector<string>{}}
        };

        std::vector<NeighbourInfo> room5neighbours{
            NeighbourInfo{Direction::NORTH, room1.getId(), std::vector<string>{}},
            NeighbourInfo{Direction::WEST, room3.getId(), std::vector<string>{}}
        };

        std::unordered_map<ID, models::Room> roomsMap = {
            {room1.getId(), room1},
            {room2.getId(), room2},
            {room3.getId(), room3},
            {room4.getId(), room4},
            {room5.getId(), room5}
        };

        std::unordered_map<ID, std::vector<models::NeighbourInfo>> neighbourMap = {
            {room1.getId(), room1neighbours},
            {room2.getId(), room2neighbours},
            {room3.getId(), room3neighbours},
            {room4.getId(), room4neighbours},
            {room5.getId(), room5neighbours}
        };

        rooms = std::move(roomsMap);
        neighbours = std::move(neighbourMap);
    }
};

TEST_F(RoomConnectionServiceTests, StartingRoom) {
    string startingRoomName = (roomConnectionService->getRoomName(startingRoomId)).value_or("");
    std::vector<std::string> directionStrings = roomConnectionService->getAvailableRoomDirections(startingRoomId);

    EXPECT_EQ("Room One", startingRoomName);

    EXPECT_TRUE(std::find(directionStrings.begin(), directionStrings.end(), NORTH_STR) != directionStrings.end());
    EXPECT_TRUE(std::find(directionStrings.begin(), directionStrings.end(), SOUTH_STR) != directionStrings.end());
    EXPECT_TRUE(std::find(directionStrings.begin(), directionStrings.end(), EAST_STR) != directionStrings.end());

    EXPECT_FALSE(std::find(directionStrings.begin(), directionStrings.end(), WEST_STR) != directionStrings.end());
}

TEST_F(RoomConnectionServiceTests, NonexistentRoom) {
    ID nonexistentRoomId{};
    string nonexistentRoomName = (roomConnectionService->getRoomName(nonexistentRoomId)).value_or("");

    EXPECT_EQ("", nonexistentRoomName);
    EXPECT_FALSE(roomConnectionService->doesRoomExist(nonexistentRoomId));
}

TEST_F(RoomConnectionServiceTests, ValidDirections) {
    EXPECT_TRUE(roomConnectionService->isValidDirectionString(NORTH_STR));
    EXPECT_TRUE(roomConnectionService->isValidDirectionString(EAST_STR));
    EXPECT_TRUE(roomConnectionService->isValidDirectionString(SOUTH_STR));
    EXPECT_TRUE(roomConnectionService->isValidDirectionString(WEST_STR));
}

TEST_F(RoomConnectionServiceTests, InvalidDirections) {
    EXPECT_FALSE(roomConnectionService->isValidDirectionString("down and around"));
    EXPECT_FALSE(roomConnectionService->isValidDirectionString("upside down"));
}

TEST_F(RoomConnectionServiceTests, TraverseFromRoom1ToRoom4) {
    //Room 1
    std::vector<std::string> availableDirectionsRoom1 = roomConnectionService->getAvailableRoomDirections(
        startingRoomId);

    ASSERT_TRUE(std::find(availableDirectionsRoom1.begin(), availableDirectionsRoom1.end(), NORTH_STR) !=
                availableDirectionsRoom1.end());

    //Room 2
    const ID& room2Id = roomConnectionService->getNeighbourId(startingRoomId, NORTH_STR)->get();
    std::vector<std::string> availableDirectionsRoom2 = roomConnectionService->getAvailableRoomDirections(room2Id);

    EXPECT_EQ("Room Two", roomConnectionService->getRoomName(room2Id));

    EXPECT_TRUE(std::find(availableDirectionsRoom2.begin(), availableDirectionsRoom2.end(), WEST_STR) !=
                availableDirectionsRoom2.end());
    EXPECT_TRUE(std::find(availableDirectionsRoom2.begin(), availableDirectionsRoom2.end(), SOUTH_STR) !=
                availableDirectionsRoom2.end());
}

int main(int argc, char** argv) {
    // The following line must be executed to initialize Google Mock
    // (and Google Test) before running the tests.
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}