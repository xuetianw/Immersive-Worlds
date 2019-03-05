#include <utility>
#include <iostream>

#include "Inventory.h"
#include "ContainerItem.h"

Inventory::Inventory(ID playerId): _playerId(playerId), _inventoryItems({}) {}

const std::unordered_map<ID, InventoryItem>& Inventory::getAllItems() const { return _inventoryItems; }

std::size_t Inventory::getSize() const { return _inventoryItems.size(); }

bool Inventory::hasItem (ID itemId) const {
    return _inventoryItems.find(itemId) != _inventoryItems.end();
}

const ID& Inventory::getPlayerId() const { return _playerId; }

// Some business logic above should already have checked there's space to add item
bool Inventory::addItem(InventoryItem itemToAdd) {
    // itemIt is the iterator to the newly inserted element
    auto [itemIt, success] = _inventoryItems.insert({itemToAdd.getId(), itemToAdd});
    return success;
}

InventoryItem Inventory::removeItem(ID idToRemove) {

    auto itemFound = _inventoryItems.find(idToRemove);
    if(itemFound != _inventoryItems.end()){
        // need to store item before erase to return the removed item
        InventoryItem item = itemFound->second;
        _inventoryItems.erase(idToRemove);
        return item;
    } else {
        // TODO: return an empty or null object?
        // std::cout << "item not found";
    }
}