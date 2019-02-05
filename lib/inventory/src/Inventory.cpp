
#include "Inventory.h"
#include "ContainerItem.h"
#include <utility>
#include <iostream>

Inventory::Inventory(int playerId): _playerId(playerId), _inventoryItems({}) {}

const std::unordered_map<int, InventoryItem>& Inventory::getAllItems() const { return _inventoryItems; }

std::size_t Inventory::getSize() const { return _inventoryItems.size(); }

bool Inventory::hasItem (int itemId) const {
    return _inventoryItems.find(itemId) != _inventoryItems.end();
}

int Inventory::getPlayerId() const { return _playerId; }

//Some business logic above should already have checked there's space to add item
bool Inventory::addItem(InventoryItem itemToAdd) {
    //itemIt is the iterator to the newly inserted element
    auto [itemIt, success] = _inventoryItems.insert({itemToAdd.getId(), itemToAdd});
    return success;
}

SingleItem
InventoryItem Inventory::removeItem(int idToRemove) {

    auto itemFound = _inventoryItems.find(idToRemove);
    if(itemFound != _inventoryItems.end()){
        //need to store item before erase to return the removed item
        InventoryItem item = itemFound->second;
        _inventoryItems.erase(idToRemove);
        return item;
    } else {
        //TODO: return an empty or null object?
//        std::cout << "item not found";
    }

}