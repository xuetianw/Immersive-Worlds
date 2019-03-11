//
// Created by Lucy on 2019-01-25.
//

#ifndef WEBSOCKETNETWORKING_CONTAINERITEM_H
#define WEBSOCKETNETWORKING_CONTAINERITEM_H

#include <unordered_map>

#include "SingleItem.h"
#include "ID.h"

class ContainerItem : public InventoryItem {
    public:
        ContainerItem() : _id(ID()), _singleItems({}) {}

        /**
        * Get all items in containerItem.
        */
        const std::unordered_map<ID, SingleItem>& getItemsInContainer() const {
            return _singleItems;
        }

    private:
        ID _id;

        std::unordered_map<ID, SingleItem> _singleItems;
};

#endif //WEBSOCKETNETWORKING_CONTAINERITEM_H
