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

}