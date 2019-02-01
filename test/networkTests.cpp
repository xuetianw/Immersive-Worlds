//
// Created by vinshit on 20/01/19.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Server.h"
#include "Client.h"
#include "ClientManager.h"


TEST(ClientManagerTests, test_BuildOuting){
  const int one = 1;
  const int two = 2;
  EXPECT_NE(one,two);
}