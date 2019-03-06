//
// Created by Nirag Mehta on 2019-02-13.
//

#include <gtest/gtest.h>
#include <algorithm>

#include "DBUtil.h"

//TODO setup: openConnection
//TODO teardown: close connection and delete database
struct DatabaseTests : testing::Test {
    DBUtil dbUtil{};
};

TEST_F(DatabaseTests, databaseTest) {
    EXPECT_EQ(true, DBUtil::openConnection("adventure.db"));
    EXPECT_EQ(true, DBUtil::testDropTables());
    EXPECT_EQ(true, DBUtil::closeConnection());
    EXPECT_EQ(true, DBUtil::openConnection("adventure.db"));
    EXPECT_EQ(true, DBUtil::registerUser("Josh", "abcdefg"));
    EXPECT_EQ(true, DBUtil::registerUser("Karan", "hijklmn"));
    EXPECT_EQ(true, DBUtil::registerUser("Melody", "bafhsbsa"));
    EXPECT_EQ(true, DBUtil::registerUser("Link", "masterSword"));
    EXPECT_EQ(true, DBUtil::registerUser("abc", "abc"));

    string temp1 = "abc";
    string temp2 = "abc";
    EXPECT_TRUE(DBUtil::findUserExistence(temp1,temp2));

    QueryResults results = DBUtil::getAllUsers();
    std::vector<string> usernames;

    for (RowResult& row : results) {
        usernames.emplace_back(row["username"]);
    }

    EXPECT_TRUE(std::find(usernames.begin(), usernames.end(), "Josh") != usernames.end());
    EXPECT_TRUE(std::find(usernames.begin(), usernames.end(), "Karan") != usernames.end());
    EXPECT_TRUE(std::find(usernames.begin(), usernames.end(), "Link") != usernames.end());
    EXPECT_FALSE(std::find(usernames.begin(), usernames.end(), "Bob") != usernames.end());

    EXPECT_EQ(true, DBUtil::deleteUser("Josh"));
    EXPECT_EQ(true, DBUtil::userExists("Melody"));

    EXPECT_EQ(true, DBUtil::closeConnection());
}

//TODO add more unit tests