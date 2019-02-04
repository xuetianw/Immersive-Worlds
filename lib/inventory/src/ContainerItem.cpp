

#include "ContainerItem.h"


ContainerItem::ContainerItem() : _singleItems({}){};

const std::unordered_map<int, SingleItem>& ContainerItem::getItemsInContainer() const { return _singleItems; }
