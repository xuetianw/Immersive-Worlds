#include "Server.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using networking::Connection;
using networking::ConnectionHash;
using std::string;
using std::unordered_map;

class ConnectionHashingTest : public ::testing::Test {
public:
    unordered_map<Connection, string, ConnectionHash> map;
    Connection keyOne{0};
    Connection keyTwo{1};

protected:
    virtual void SetUp() override {}

    virtual void TearDown() override {}
};

/*
 * Test the ConnectionHasher for using Connection as a key in an unordered map
 */

TEST_F(ConnectionHashingTest, TestHashMapSizeWithOneConnectionKey) {
    map.insert(std::make_pair(keyOne, "val1"));
    map.insert(std::make_pair(keyOne, "val2"));

    EXPECT_EQ(1, map.size());
}

TEST_F(ConnectionHashingTest, TestHashMapSizeWithTwoConnectionKeys) {
    map.insert(std::make_pair(keyOne, "val1"));
    map.insert(std::make_pair(keyTwo, "val2"));

    EXPECT_EQ(2, map.size());
}

TEST_F(ConnectionHashingTest, TestHashMapValues) {
    map.insert(std::make_pair(keyOne, "val1"));
    map.insert(std::make_pair(keyTwo, "val2"));

    EXPECT_EQ("val1", map.find(keyOne)->second);
    EXPECT_EQ("val2", map.find(keyTwo)->second);
}

TEST_F(ConnectionHashingTest, TestHashMapEmptyAfterAddAndRemoveByKey) {
    map.insert(std::make_pair(keyOne, "val1"));
    map.erase(keyOne);

    EXPECT_TRUE(map.empty());
}

TEST_F(ConnectionHashingTest, TestHashMapNotEmptyAfterInsertion) {
    map.insert(std::make_pair(keyOne, "val1"));

    EXPECT_FALSE(map.empty());
}