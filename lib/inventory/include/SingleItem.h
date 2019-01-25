//
// Created by Lucy on 2019-01-18.
//

#ifndef PROJECT_SINGLEITEM_H
#define PROJECT_SINGLEITEM_H

#include <string>
#include "InventoryItem.h"


class SingleItem : public InventoryItem {

public:
    enum class ItemType {
        CLOTHING,
        WEAPON
    };

    SingleItem();
    SingleItem(int anId,
                  std::string aKeyword,
                  std::string aShortdesc,
                  std::string aLongdesc,
                  std::string aDescription);
    int getId() const;
    std::string getKeyword() const;
    std::string getShortdesc() const;
    std::string getLongdesc() const;
    std::string getDescription() const;

private:
    int _id;
    ItemType _itemType;
    std::string _keyword, _shortdesc, _longdesc, _description;

};


#endif //PROJECT_SINGLEITEM_H
