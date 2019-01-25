//
// Created by vinshit on 20/01/19.
//

#include "networkTests.h"
#include "gtest/gtest.h"
#include "Server.h"
#include "Client.h"
#include "Area.h"

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

TEST(AreaTest, Test_GetID) {
  int id = 1;
  
  channel::Area *area = new channel::Area(id);
  EXPECT_EQ(id, area->getId());
}