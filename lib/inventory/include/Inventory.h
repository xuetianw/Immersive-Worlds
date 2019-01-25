//
// Created by Lucy on 2019-01-18.
//

#ifndef PROJECT_INVENTORY_H
#define PROJECT_INVENTORY_H


#include <vector>
#include "Object.h"

struct Item {
    Object object;          // an object in game
    int quantity;           //quantity of this object in inventory
};

class Inventory {

public:
    Inventory();
    Inventory(std::vector<Item> setOfItems);

    /**
     * Get details of what the inventory contains
     */
    std::vector<Item> getItems() const;

    /**
     * Add items to inventory
     * @param itemsToAdd: list of items to be added into inventory
     */
    void addItems(std::vector<Item> itemsToAdd);

    /**
     * Remove items from inventory. Return true if successful, false if item carried is less than amount removed
     * @param itemsToRemove: list of items to be removed from inventory
     */
    bool removeItems(std::vector<Item> itemsToRemove);

private:
    int _playerId;
    std::vector<Item> _items;     //all items in inventory
};


#endif //PROJECT_INVENTORY_H
