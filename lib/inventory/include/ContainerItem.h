//
// Created by Lucy on 2019-01-25.
//

#ifndef WEBSOCKETNETWORKING_CONTAINERITEM_H
#define WEBSOCKETNETWORKING_CONTAINERITEM_H

#include <vector>
#include "SingleItem.h"

class ContainerItem : public InventoryItem {

    public:

        ContainerItem();

        /**
        * Get the item at index from containerItem.
        * @param index: the index in which the InventoryItem is located in the containerItem
        */
        SingleItem getItemInContainer(int index) const;

        /**
        * Get all items in containerItem.
        */
        std::vector<SingleItem> getItemsInContainer() const;


    private:
        std::vector<SingleItem> _singleItems;

};


#endif //WEBSOCKETNETWORKING_CONTAINERITEM_H
