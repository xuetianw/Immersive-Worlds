//
// Created by vinshit on 20/01/19.
//

#include "networkTests.h"
#include "Area.h"
#include "Client.h"
#include "Room.h"
#include "Server.h"
#include "World.h"
#include "gtest/gtest.h"

using channel::Area;
using channel::Room;
using channel::World;

// this just a sample test
class BasicTest : public ::testing::Test {
protected:
  virtual void SetUp() {}

  virtual void TearDown() {}
};

TEST_F(BasicTest, Test_Nothing) {
  const int one = 1;
  const int two = 2;
  EXPECT_NE(one, two);
}

/**
 * Channel Tests: Area
 */

struct AreaTests : testing:: Test {
    std::unique_ptr<Area> area = std :: make_unique<Area>(1);
    std::unique_ptr<Room> room = std :: make_unique<Room>("room_name", "description");
};

TEST_F(AreaTests, Test_Area_GetId) {
  EXPECT_EQ(1, area->getId());
  EXPECT_NE(3, area->getId()); // this part might be redundant
}


TEST_F(AreaTests, Test_Area_Add_Room) {
  bool result = area->addRoom(*room);
  EXPECT_EQ(true, result);
  result = area->addRoom(*room);
  EXPECT_EQ(false, result);
}


struct WorldTests : testing:: Test {
    std::unique_ptr<World> world = std :: make_unique<World>(1);
    std::unique_ptr<Area> area = std :: make_unique<Area>(1);
};

TEST_F(WorldTests, Test_World_GetId) {
  EXPECT_EQ(1, world->getId());
  EXPECT_NE(3, world->getId());
}


TEST_F(WorldTests, Test_World_Add_Area) {
  bool result = world->addArea(*area);
  EXPECT_EQ(true, result);
  result = world->addArea(*area);
  EXPECT_EQ(false, result);
}

