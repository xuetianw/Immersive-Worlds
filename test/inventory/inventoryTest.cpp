#include "Inventory.h"
#include "gtest/gtest.h"

struct InventoryTests : testing:: Test {
    ID testPlayerID;
    ID testItemID;
    std::unique_ptr<Inventory> inventory = std::make_unique<Inventory>(testPlayerID);
    std::unique_ptr<InventoryItem> item = std::make_unique<SingleItem>(testItemID, "keyword", "shortDesc", "longDesc", "Description");
};

TEST_F(InventoryTests, Test_Inventory_GetPlayerId){
    EXPECT_EQ(testPlayerID, inventory->getPlayerId());
}

TEST_F(InventoryTests, Test_Inventory_hasItem){
    ASSERT_FALSE(inventory->hasItem(testItemID));
    bool successInsert = inventory->addItem(*item);
    ASSERT_TRUE(successInsert);
    ASSERT_TRUE(inventory->hasItem(testItemID));
}

TEST_F(InventoryTests, Test_Inventory_Size_and_Insert){
    ASSERT_EQ(0, inventory->getSize());
    bool successInsert = inventory->addItem(*item);
    ASSERT_TRUE(successInsert);
    ASSERT_EQ(1, inventory->getSize());
}

TEST_F(InventoryTests, Test_Inventory_Remove){
    ASSERT_EQ(0, inventory->getSize());
    bool successInsert = inventory->addItem(*item);
    ASSERT_TRUE(successInsert);
    ASSERT_EQ(1, inventory->getSize());

    auto deletedItem = inventory->removeItem(testItemID);
    ASSERT_EQ(deletedItem.getId(), item->getId());
    // remove item that doesn't exist...TODO
    // auto deletedSameItem = inventory->removeItem(testItemID);
    // EXPECT_TRUE(deletedItem2 == NULL);
}


