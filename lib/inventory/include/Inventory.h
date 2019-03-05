#ifndef PROJECT_INVENTORY_H
#define PROJECT_INVENTORY_H

#include <unordered_map>

#include "SingleItem.h"
#include "ID.h"

class Inventory {
public:
    explicit Inventory(ID playerId);

    /**
     * Get all items the inventory contains
     */
    const std::unordered_map<ID, InventoryItem>& getAllItems() const;

    /**
     * Get the number of items in inventory
     */
    std::size_t getSize() const;

    /**
     * Check if inventory contains the specified item
     * @param itemId: the item to search in inventory
     */
    bool hasItem(const ID& itemId) const;

    const ID& getPlayerId() const;

    /**
     * Add an item to inventory with a given ID
     * @param itemToAdd: the item to be added into inventory
     */
    bool addItem(const ID& id, InventoryItem itemToAdd);

    /**
     * Add an item to inventory with a newly generated ID
     * @param itemToAdd: the item to be added into inventory
     */
    bool addItem(InventoryItem itemToAdd);

    /**
     * Remove an item from inventory and return the removed item.
     * @param itemToRemove: the id of the item to be removed from inventory
     */
    std::unique_ptr<InventoryItem> removeItem(const ID& idToRemove);

private:
    ID _playerId;

    std::unordered_map<ID, InventoryItem> _inventoryItems;
};

#endif //PROJECT_INVENTORY_H
