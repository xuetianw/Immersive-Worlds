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
  channel::Room testRoom {"test name", 0001};
  json j = testRoom;
  EXPECT_EQ(j.at("name"), "test name");
}