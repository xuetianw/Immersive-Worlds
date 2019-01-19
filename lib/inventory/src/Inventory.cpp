//
// Created by Lucy on 2019-01-18.
//

#include "../include/Inventory.h"

Inventory::Inventory(): items({}) {}
Inventory::Inventory(vector<Item> setOfItems): items(setOfItems) {}

void Inventory::getItems() const { return items }

void Inventory::addItems(vector<Item> itemsToAdd){
    //add items until vector is empty
    while( !itemsToAdd.empty()){

        //retrieve last item in itemsToAdd
        newItem = itemsToAdd.back();
        itemsToAdd.pop_back();

        for (vector<Item>::iterator it = items.begin(); it != items.end(); ++it){
            item = *it;
            if(newItem.object == item.object){
                //add item
                item.quantity += newItem.quantity;
            } else {
                //add new item
                items.push_back(newItem)
            }
        }
    }
}


bool Inventory::removeItems(vector<Item> itemsToRemove){
    //remove items until vector is empty
    while( !itemsToRemove.empty()){

        //retrieve last item in itemsToRemove
        newItem = itemsToRemove.back();
        itemsToRemove.pop_back();

        //assumes that the item requested to be removed must exist in inventory
        for (vector<Item>::iterator it = items.begin(); it != items.end(); ++it){
            item = *it;
            if(newItem.object == item.object){
                if(item.quantity >= newItem.quantity){
                    //remove item
                    item.quantity -= newItem.quantity;
                    return true;
                } else{
                    //item in inventory is less than amount requested to remove
                    return false;
                }

            }
        }
    }
}