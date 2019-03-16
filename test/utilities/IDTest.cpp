#include "ID.h"
#include "gtest/gtest.h"

TEST(idTests, differentIDTest){

    UUIDGen generator;
    ID id1 = ID(generator);
    ID id2 = ID(generator);
    ID id3 = ID(generator);
    EXPECT_TRUE(id1.getID() != id2.getID());
    EXPECT_TRUE(id2.getID() != id3.getID());
    EXPECT_TRUE(id1.getID() != id3.getID());

    ID id4 = ID();
    ID id5 = ID();
    ID id6 = ID();
    EXPECT_TRUE(id4.getID() != id5.getID());
    EXPECT_TRUE(id5.getID() != id6.getID());
    EXPECT_TRUE(id4.getID() != id6.getID());

}