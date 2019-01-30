
#include "Inventory.h"
#include "SingleItem.h"
#include "ContainerItem.h"

Inventory::Inventory(): _inventoryItems({}) {}
Inventory::Inventory(std::vector<InventoryItem> setOfItems): _inventoryItems(setOfItems) {}

std::vector<InventoryItem> Inventory::getItems() const { return _inventoryItems; }

//TODO: look into differentiating derived class and finish this
void Inventory::addItems(std::vector<InventoryItem> itemsToAdd){
//    //add items until vector is empty
//    while( !itemsToAdd.empty()){
//
//        //retrieve last item in itemsToAdd
//        InventoryItem newItem = itemsToAdd.back();
//        itemsToAdd.pop_back();
//
//        for (std::vector<InventoryItem>::iterator it = _inventoryItems.begin(); it != _inventoryItems.end(); ++it){
//            InventoryItem itemInInventory = *it;
//
//
//            if(newItem.object.getId() == itemInInventory.object.getId()){
//                //add item that already exists in inventory
//                itemInInventory.quantity += newItem.quantity;
//            } else {
//                //add new item
//                _inventoryItems.push_back(newItem);
//            }
//        }
//    }
}

//TODO: look into differentiating derived class and finish this
bool Inventory::removeItems(std::vector<InventoryItem> itemsToRemove){
//    //remove items until vector is empty
//    while( !itemsToRemove.empty()){
//
//        //retrieve last item in itemsToRemove
//        InventoryItem newItem = itemsToRemove.back();
//        itemsToRemove.pop_back();
//
//        //assumes that the item requested to be removed must exist in inventory
//        for (std::vector<InventoryItem>::iterator it = _inventoryItems.begin(); it != _inventoryItems.end(); ++it){
//            InventoryItem item = *it;
//
//            if(newItem.object.getId() == item.object.getId()){
//                if(item.quantity >= newItem.quantity){
//                    //remove item
//                    item.quantity -= newItem.quantity;
//                } else{
//                    //item in inventory is less than amount requested to remove
                    return false;
//                }
//
//            }
//        }
//    }
//    return true;
}