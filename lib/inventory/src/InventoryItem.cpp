

#include "InventoryItem.h"
#include <iostream>

	int InventoryItem::getId() const { return _id; }

	void operator=(const InventoryItem inventoryItem, const SingleItem singleItem);

	void operator=(const InventoryItem inventoryItem, const SingleItem singleItem) {
		return;
	}
