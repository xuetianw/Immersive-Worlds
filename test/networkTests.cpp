//
// Created by vinshit on 20/01/19.
//

#include "networkTests.h"
#include "gtest/gtest.h"
#include "Server.h"
#include "Client.h"
#include "Area.h"
#include "Room.h"
#include "World.h"

class BasicTest : public::testing::Test{
  protected:
    virtual void SetUp(){

    }

    virtual void TearDown(){

    }
};

TEST_F(BasicTest,Test_Nothing){
  const int one = 1;
  const int two = 2;
  EXPECT_NE(one,two);
}

/**
 * Channel Tests: Area
 */  
TEST(AreaTest, Test_Area_GetId) {
  int id = 1;
  
  channel::Area *area = new channel::Area(id);
  EXPECT_EQ(id, area->getId());
}

TEST(AreaTest, Test_Area_GetId_Fail) {
  int id = 1;
  int failId = 3;
  
  channel::Area *area = new channel::Area(id);
  EXPECT_NE(failId, area->getId());
}

TEST(AreaTest, Test_Area_Add_Room) {
  std::string name = "room_name";
  std::string desc = "description";
  
  channel::Room *room = new channel::Room(name, desc);

  int id = 1;
  channel::Area *area = new channel::Area(id);

  auto result = area->addRoom(*room);
  EXPECT_EQ(true, result);
}

TEST(AreaTest, Test_Area_Add_Room_Fail) {
  std::string name = "room_name";
  std::string desc = "description";
  
  channel::Room *room = new channel::Room(name, desc);

  int id = 1;
  channel::Area *area = new channel::Area(id);

  area->addRoom(*room);

  auto result = area->addRoom(*room);
  EXPECT_EQ(false, result);
}

TEST(World, Test_World_GetId) {
  int id = 1;
  
  channel::World *world = new channel::World(id);
  EXPECT_EQ(id, world->getId());
}

TEST(AreaTest, Test_World_GetId_Fail) {
  int id = 1;
  int failId = 3;
  
  channel::World *world = new channel::World(id);
  EXPECT_NE(failId, world->getId());
}

TEST(AreaTest, Test_World_Add_Area) {
  int area_id = 1;
  
  channel::Area *area = new channel::Area(area_id);

  int world_id = 1;
  channel::World *world = new channel::World(world_id);

  auto result = world->addArea(*area);
  EXPECT_EQ(true, result);
}

TEST(AreaTest, Test_World_Add_Area_Fail) {
  int area_id = 1;
  channel::Area *area = new channel::Area(area_id);

  int world_id = 1;
  channel::World *world = new channel::World(world_id);

  world->addArea(*area);
  auto result = world->addArea(*area);

  EXPECT_EQ(false, result);
}