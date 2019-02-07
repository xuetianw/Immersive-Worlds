
#ifndef PROJECT_SINGLEITEM_H
#define PROJECT_SINGLEITEM_H

#include <string>
#include "InventoryItem.h"


class SingleItem : public InventoryItem {

public:
    enum class ItemType {
        CLOTHING,
        WEAPON,
        CONSUMABLE
    };

    SingleItem();
    SingleItem(int anId,
                  std::string aKeyword,
                  std::string aShortdesc,
                  std::string aLongdesc,
                  std::string aDescription);
    std::string getKeyword() const;
    std::string getShortdesc() const;
    std::string getLongdesc() const;
    std::string getDescription() const;
	ItemType getItemType() const;

private:
    ItemType _itemType;
    std::string _keyword, _shortdesc, _longdesc, _description;

};


#endif //PROJECT_SINGLEITEM_H
