

#ifndef WEBSOCKETNETWORKING_INVENTORYITEM_H
#define WEBSOCKETNETWORKING_INVENTORYITEM_H


// base class which SingleItem and ContainerItem inherits from
class InventoryItem {

public:
	enum class ItemType {
		CLOTHING,
		WEAPON,
		CONSUMABLE,
		MISC
	};
	ItemType getItemType() const;

	int getId() const;

private:
	ItemType _itemType;
protected:
    int _id; //TODO: change to UUID after handler is setup

};


#endif
