//
// Created by Nirag Mehta on 2019-02-13.
//

#include <stdio.h>
#include <gtest/gtest.h>
#include <algorithm>

#include "DBUtil.h"

//TODO setup: openConnection
//TODO teardown: close connection and delete database
struct DatabaseTests : testing::Test {
    DBUtil dbUtil{};
};

TEST_F(DatabaseTests, databaseTest) {

    remove("testAdventure.db");

    EXPECT_EQ(true, DBUtil::openConnection("testAdventure.db"));
    EXPECT_EQ(true, DBUtil::registerUser("Josh", "abcdefg"));
    EXPECT_EQ(true, DBUtil::registerUser("Karan", "hijklmn"));
    EXPECT_EQ(true, DBUtil::registerUser("Melody", "bafhsbsa"));
    EXPECT_EQ(true, DBUtil::registerUser("Link", "masterSword"));
    EXPECT_EQ(true, DBUtil::registerUser("abc", "abc"));

    string testUsername = "abc";
    string testPaassword = "abc";
    EXPECT_TRUE(DBUtil::isValidCredential(testUsername, testPaassword));

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