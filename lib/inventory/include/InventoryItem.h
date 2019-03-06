#ifndef WEBSOCKETNETWORKING_INVENTORYITEM_H
#define WEBSOCKETNETWORKING_INVENTORYITEM_H

#include "ID.h"

enum class ItemType {
    CLOTHING,
    WEAPON,
    CONSUMABLE
};

// base class which SingleItem and ContainerItem inherits from
class InventoryItem {
public:
    ItemType getItemType() const;

    const ID& getId() const;

private:
    ItemType _itemType;

protected:
    ID _id;
};

#endif
