//
// Created by Lucy on 2019-01-18.
//

#include "SingleItem.h"


SingleItem::SingleItem() : _id(0), _keyword(""), _shortdesc(""), _longdesc("") {}
SingleItem::SingleItem(int anId, std::string aKeyword, std::string aShortdesc, std::string aLongdesc, std::string aDescription)
        : _id(anId), _keyword(aKeyword), _shortdesc(aShortdesc), _description(aDescription){}

int SingleItem::getId() const { return _id; }
std::string SingleItem::getKeyword() const { return _keyword; }
std::string SingleItem::getShortdesc() const { return _shortdesc; }
std::string SingleItem::getLongdesc() const { return _longdesc; }
std::string SingleItem::getDescription() const { return _description; }
SingleItem::ItemType SingleItem::getType() const { return _itemType; }

