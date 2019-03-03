//
// Created by Lucy on 2019-01-25.
//

#ifndef WEBSOCKETNETWORKING_CONTAINERITEM_H
#define WEBSOCKETNETWORKING_CONTAINERITEM_H

#include <unordered_map>

#include "SingleItem.h"

class ContainerItem : public InventoryItem {
    public:
        ContainerItem();

        /**
        * Get all items in containerItem.
        */
        const std::unordered_map<int, SingleItem>& getItemsInContainer() const;

    private:
        std::unordered_map<int, SingleItem> _singleItems;
};

#endif //WEBSOCKETNETWORKING_CONTAINERITEM_H
