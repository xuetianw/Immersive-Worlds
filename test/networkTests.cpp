//
// Created by vinshit on 20/01/19.
//

#include "networkTests.h"
#include "gtest/gtest.h"

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