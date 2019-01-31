//
// Created by Lucy on 2019-01-25.
//

#include "ContainerItem.h"


ContainerItem::ContainerItem() : _singleItems({}){};

std::vector<SingleItem> ContainerItem::getItemsInContainer() const { return _singleItems; }

SingleItem ContainerItem::getItemInContainer(int index) const {
    return _singleItems[index];
}