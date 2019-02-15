//
// Created by Nirag Mehta on 2019-02-13.
//

#include <gtest/gtest.h>
#include "DBUtil.h"


struct DatabaseTests : testing:: Test {

    DBUtil dbUtil{};

};

TEST_F(DatabaseTests ,databaseTest){
    EXPECT_EQ(true, DBUtil::openConnection());
    EXPECT_EQ(true, DBUtil::createTables());

}