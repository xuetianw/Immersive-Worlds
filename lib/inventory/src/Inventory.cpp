#include <utility>
#include <iostream>

#include "Inventory.h"
#include "ContainerItem.h"

Inventory::Inventory(ID playerId): _playerId(playerId), _inventoryItems({}) {}

const std::unordered_map<ID, InventoryItem>& Inventory::getAllItems() const { return _inventoryItems; }

std::size_t Inventory::getSize() const { return _inventoryItems.size(); }

bool Inventory::hasItem (const ID& itemId) const {
    return _inventoryItems.find(itemId) != _inventoryItems.end();
}

const ID& Inventory::getPlayerId() const { return _playerId; }

// Some business logic above should already have checked there's space to add item
bool Inventory::addItem(const ID& id, InventoryItem itemToAdd) {
    // itemIt is the iterator to the newly inserted element
    auto [itemIt, success] = _inventoryItems.insert_or_assign(id, itemToAdd);
    return itemIt != _inventoryItems.end() || success;
}

bool Inventory::addItem(InventoryItem itemToAdd) {
    return addItem(ID(), itemToAdd);
}

std::unique_ptr<InventoryItem> Inventory::removeItem(const ID& idToRemove) {
    std::unique_ptr<InventoryItem> returnItem;
    auto itemFound = _inventoryItems.find(idToRemove);
    if(itemFound != _inventoryItems.end()) {
        // return a unique_ptr to the removed Item indicating transfer of ownership after removal
        returnItem = std::make_unique<InventoryItem>(itemFound->second);
        _inventoryItems.erase(itemFound);
    }

    return returnItem;
}