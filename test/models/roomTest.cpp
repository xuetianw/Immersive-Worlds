//
// Created by vinshit on 20/01/19.
//

#include "gtest/gtest.h"
#include "Room.h"
#include <nlohmann/json.hpp>
#include <nlohmann/json.hpp>


class RoomTest : public :: testing::Test {
public:
    std::vector<std::string> desc = {"description1", "description2"};
    std::string name = "room1";
    int id = 5;
    models::RoomId roomId = models::RoomId(id);
    models::Room room = models::Room(roomId, name, desc);
};

TEST_F(RoomTest, constructor_test) {
    EXPECT_EQ(id, roomId.getId());
    EXPECT_EQ(name, room.getName());
    EXPECT_EQ(desc, room.get_description());
}