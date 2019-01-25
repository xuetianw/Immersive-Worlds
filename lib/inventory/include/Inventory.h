//
// Created by Lucy on 2019-01-18.
//

#ifndef PROJECT_INVENTORY_H
#define PROJECT_INVENTORY_H


#include <vector>
#include "SingleItem.h"


class Inventory {

public:
    Inventory();
    Inventory(std::vector<InventoryItem> setOfItems);

    /**
     * Get details of what the inventory contains
     */
    std::vector<InventoryItem> getItems() const;

    /**
     * Add an item to inventory
     * @param itemToAdd: the item to be added into inventory
     */
    void addItem(InventoryItem itemToAdd);

    /**
     * Add items to inventory
     * @param itemsToAdd: list of items to be added into inventory
     */
    void addItems(std::vector<InventoryItem> itemsToAdd);

    /**
     * Remove an item from inventory. Return true if successful, false if item does not exist in inventory
     * @param itemToRemove: the item to be removed from inventory
     */
    bool removeItem(InventoryItem itemToRemove);

    /**
     * Remove items from inventory. Return true if successful, false if item carried is less than amount removed
     * @param itemsToRemove: list of items to be removed from inventory
     */
    bool removeItems(std::vector<InventoryItem> itemsToRemove);

private:
    int _playerId;
    std::vector<InventoryItem> _inventoryItems;     //all items in inventory
};


#endif //PROJECT_INVENTORY_H
