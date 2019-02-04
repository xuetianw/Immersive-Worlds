
#ifndef PROJECT_INVENTORY_H
#define PROJECT_INVENTORY_H


#include <unordered_map>
#include "SingleItem.h"


class Inventory {

public:
    Inventory(int playerId);

    /**
     * Get all items the inventory contains
     */
    const std::unordered_map<int, InventoryItem>& getAllItems() const;

    /**
     * Get the number of items in inventory
     */
    std::size_t getSize() const;

    /**
     * Check if inventory contains the specified item
     * @param itemId: the item to search in inventory
     */
    bool hasItem(int itemId) const;

    int getPlayerId() const;

    /**
     * Add an item to inventory
     * @param itemToAdd: the item to be added into inventory
     */
    bool addItem(InventoryItem itemToAdd);


    /**
     * Remove an item from inventory and return the removed item.
     * @param itemToRemove: the id of the item to be removed from inventory
     */
    InventoryItem removeItem(int idToRemove);


private:
    //TODO: change to UUID after handler is setup
    int _playerId;
    std::unordered_map<int, InventoryItem> _inventoryItems;
};


#endif //PROJECT_INVENTORY_H
