//
// Created by vinshit on 20/01/19.
//

#include "modelsTest.h"
#include "Area.h"
#include "Client.h"
#include "Room.h"
#include "Server.h"
#include "World.h"
#include "gtest/gtest.h"

using models::Area;
using models::Room;
using models::World;

// this just a sample test
class BasicTest : public ::testing::Test {
public:
    std::vector<int> vectorTest;
protected:
  virtual void SetUp() override{
    vectorTest.push_back(1);
    vectorTest.push_back(2);
  }

  //TearDown() is not needed since we
  // don't have to clean up after each test
  virtual void TearDown() override{}
};

TEST_F(BasicTest, Test_Nothing) {
  auto one = vectorTest.back();
  vectorTest.pop_back();
  auto two = vectorTest.back();
  EXPECT_NE(one, two);
}

/**
 * Models Tests: Area
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

