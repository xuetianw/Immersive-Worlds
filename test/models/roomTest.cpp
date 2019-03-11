//
// Created by vinshit on 20/01/19.
//

#include <nlohmann/json.hpp>
#include <nlohmann/json.hpp>
#include <gtest/gtest.h>

#include "Room.h"

class RoomTest : public :: testing::Test {
public:
    std::vector<std::string> desc = {"description1", "description2"};
    std::string name = "room1";
    ID id;
    models::Room room = models::Room(id, name, desc);
};

TEST_F(RoomTest, constructor_test) {
    EXPECT_EQ(id, room.getId());
    EXPECT_EQ(name, room.getName());
    EXPECT_EQ(desc, room.getDescription());
}