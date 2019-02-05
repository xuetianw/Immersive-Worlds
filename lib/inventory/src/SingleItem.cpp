

#include <SingleItem.h>

#include "SingleItem.h"

	SingleItem::SingleItem() : _keyword(""), _shortdesc(""),
							   _longdesc("") { _id = 0; } //TODO: Is there better way to initialize _id


	SingleItem::SingleItem(int anId, std::string aKeyword, std::string aShortdesc, std::string aLongdesc,
					   std::string aDescription) :
					   _keyword(aKeyword),
					   _shortdesc(aShortdesc),
					   _description(aDescription) {
		//TODO Fix: Is there better way to initialize _id
		_id = anId;
	}
	std::string SingleItem::getKeyword() const { return _keyword; }

	std::string SingleItem::getShortdesc() const { return _shortdesc; }

	std::string SingleItem::getLongdesc() const { return _longdesc; }

	std::string SingleItem::getDescription() const { return _description; }

	SingleItem::ItemType SingleItem::getItemType() const { return _itemType; }



