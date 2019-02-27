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
    EXPECT_EQ(true, DBUtil::registerUser("Josh","abcdefg"));
    EXPECT_EQ(true, DBUtil::registerUser("Karan","hijklmn"));
    EXPECT_EQ(true, DBUtil::registerUser("Melody","bafhsbsa"));
    EXPECT_EQ(true, DBUtil::deleteUser("Josh"));
    EXPECT_EQ(true, DBUtil::userExists("Melody"));

    EXPECT_EQ(true, DBUtil::closeConnection());
}