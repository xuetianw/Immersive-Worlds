#include "InventoryItem.h"

const ID& InventoryItem::getId() const { return _id; }

ItemType InventoryItem::getItemType() const { return _itemType; }
