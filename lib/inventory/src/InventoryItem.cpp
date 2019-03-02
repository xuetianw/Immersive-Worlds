#include <iostream>

#include "InventoryItem.h"

int InventoryItem::getId() const { return _id; }

ItemType InventoryItem::getItemType() const { return _itemType; }
