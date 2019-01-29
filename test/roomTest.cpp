//
// Created by vinshit on 20/01/19.
//

#include "networkTests.h"
#include "gtest/gtest.h"
#include "Room.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class RoomTest : public::testing::Test{
  protected:
    virtual void SetUp(){

    }

    virtual void TearDown(){

    }
};

TEST_F(RoomTest,Test_Nothing){
  channel::Room testRoom {"test name", 1234};
  json roomJson = testRoom;
  EXPECT_EQ(roomJson.at("name"), "test name");
  EXPECT_EQ(roomJson.at("id"), 1234);
  auto roomFromJson = roomJson.get<channel::Room>();
  EXPECT_EQ(roomFromJson.getId(), 1234);
  EXPECT_EQ(roomFromJson.getName(), "test name");
}