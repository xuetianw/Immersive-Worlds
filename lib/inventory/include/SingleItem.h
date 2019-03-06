#ifndef PROJECT_SINGLEITEM_H
#define PROJECT_SINGLEITEM_H

#include <string>

#include "InventoryItem.h"
#include "ID.h"

using string = std::string;

class SingleItem : public InventoryItem {
public:
    SingleItem() :
        _id(ID()),
        _keyword(""),
        _shortdesc(""),
        _longdesc(""),
        _description("") {}

    SingleItem(ID anId,
            string aKeyword,
            string aShortdesc,
            string aLongdesc,
            string aDescription) :
            _keyword(move(aKeyword)),
            _shortdesc(move(aShortdesc)),
            _longdesc(move(aLongdesc)),
            _description(move(aDescription)) {}

    std::string getKeyword() const;

    std::string getShortdesc() const;

    std::string getLongdesc() const;

    std::string getDescription() const;

private:
    ID _id;

    string _keyword;

    string _shortdesc;

    string _longdesc;

    string _description;
};

#endif //PROJECT_SINGLEITEM_H
