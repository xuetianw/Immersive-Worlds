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
TEST(AreaTest, Test_Area_GetId) {
  int id = 1;

  Area area = Area(id);
  EXPECT_EQ(id, area.getId());
}

TEST(AreaTest, Test_Area_GetId_Fail) {
  int id = 1;
  int failId = 3;

  Area area = Area(id);
  EXPECT_NE(failId, area.getId());
}

TEST(AreaTest, Test_Area_Add_Room) {
  std::string name = "room_name";
  std::string desc = "description";

  Room room = Room(name, desc);

  int id = 1;
  Area area = Area(id);

  bool result = area.addRoom(room);
  EXPECT_EQ(true, result);
}

TEST(AreaTest, Test_Area_Add_Room_Fail) {
  std::string name = "room_name";
  std::string desc = "description";

  Room room = Room(name, desc);

  int id = 1;
  Area area = Area(id);

  area.addRoom(room);

  bool result = area.addRoom(room);
  EXPECT_EQ(false, result);
}

TEST(World, Test_World_GetId) {
  int id = 1;

  World world = World(id);
  EXPECT_EQ(id, world.getId());
}

TEST(AreaTest, Test_World_GetId_Fail) {
  int id = 1;
  int failId = 3;

  World world = World(id);
  EXPECT_NE(failId, world.getId());
}

TEST(AreaTest, Test_World_Add_Area) {
  int area_id = 1;

  Area area = Area(area_id);

  int world_id = 1;
  World world = World(world_id);

  bool result = world.addArea(area);
  EXPECT_EQ(true, result);
}

TEST(AreaTest, Test_World_Add_Area_Fail) {
  int area_id = 1;
  Area area = Area(area_id);

  int world_id = 1;
  World world = World(world_id);

  world.addArea(area);
  bool result = world.addArea(area);

  EXPECT_EQ(false, result);
}
