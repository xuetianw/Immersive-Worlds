//
// Created by Lucy on 2019-01-18.
//

#include "Inventory.h"

Inventory::Inventory(): _items({}) {}
Inventory::Inventory(std::vector<Item> setOfItems): _items(setOfItems) {}

std::vector<Item> Inventory::getItems() const { return _items; }

void Inventory::addItems(std::vector<Item> itemsToAdd){
    //add items until vector is empty
    while( !itemsToAdd.empty()){

        //retrieve last item in itemsToAdd
        Item newItem = itemsToAdd.back();
        itemsToAdd.pop_back();

        for (std::vector<Item>::iterator it = _items.begin(); it != _items.end(); ++it){
            Item item = *it;
            if(newItem.object.getId() == item.object.getId()){
                //add item
                item.quantity += newItem.quantity;
            } else {
                //add new item
                _items.push_back(newItem);
            }
        }
    }
}


bool Inventory::removeItems(std::vector<Item> itemsToRemove){
    //remove items until vector is empty
    while( !itemsToRemove.empty()){

        //retrieve last item in itemsToRemove
        Item newItem = itemsToRemove.back();
        itemsToRemove.pop_back();

        //assumes that the item requested to be removed must exist in inventory
        for (std::vector<Item>::iterator it = _items.begin(); it != _items.end(); ++it){
            Item item = *it;
            if(newItem.object.getId() == item.object.getId()){
                if(item.quantity >= newItem.quantity){
                    //remove item
                    item.quantity -= newItem.quantity;
                } else{
                    //item in inventory is less than amount requested to remove
                    return false;
                }

            }
        }
    }
    return true;
}