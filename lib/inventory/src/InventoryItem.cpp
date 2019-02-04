
#include <InventoryItem.h>

#include "SingleItem.h"
#include "InventoryItem.h"

int InventoryItem::getId() const { return _id; }
void operator=(const InventoryItem inventoryItem, const SingleItem singleItem);
void operator=(const InventoryItem inventoryItem, const SingleItem singleItem){
	return;
}

