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
private:
    int playerId;
    vector<Item> items;     //all items in inventory
public:
    Inventory(vector<Item> setOfItems);

    /**
     * Get details of what the inventory contains
     */
    vector<Item> getItems() const;

    /**
     * Add items to inventory
     * @param itemsToAdd: list of items to be added into inventory
     */
    void addItems(vector<Item> itemsToAdd);

    /**
     * Remove items from inventory. Return true if successful, false if item carried is less than amount removed
     * @param itemsToRemove: list of items to be removed from inventory
     */
    bool removeItems(vector<Item> itemsToRemove);


};


#endif //PROJECT_INVENTORY_H
