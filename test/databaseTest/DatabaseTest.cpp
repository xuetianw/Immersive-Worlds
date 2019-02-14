//
// Created by Nirag Mehta on 2019-02-13.
//

#include <gtest/gtest.h>
#include "DBUtil.h"


struct DatabaseTests : testing:: Test {

    DBUtil dbUtil{};

};

TEST_F(DatabaseTests ,connectionTest){
    EXPECT_EQ(true, DBUtil::openConnection());

}