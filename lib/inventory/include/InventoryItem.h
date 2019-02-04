

#ifndef WEBSOCKETNETWORKING_INVENTORYITEM_H
#define WEBSOCKETNETWORKING_INVENTORYITEM_H


#include "SingleItem.h"

// base class which SingleItem and ContainerItem inherits from
class InventoryItem {

public:
    int getId() const;

protected:
    int _id; //TODO: change to UUID after handler is setup

};


#endif //WEBSOCKETNETWORKING_INVENTORYITEM_H
