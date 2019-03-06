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
        _keywords(std::vector<string>()),
        _shortdesc(""),
        _longdescs(std::vector<string>()),
        _description("") {}

    SingleItem(ID anId,
               std::vector<string>  aKeyword,
               string aShortdesc,
               std::vector<string>  aLongdesc,
               string aDescription) :
            _keywords(move(aKeyword)),
            _shortdesc(move(aShortdesc)),
            _longdescs(move(aLongdesc)),
            _description(move(aDescription)) {}

    std::vector<string> getKeyword() const;

    std::string getShortdesc() const;

    std::vector<string> getLongdesc() const;

    std::string getDescription() const;

private:
    ID _id;

    std::vector<string> _keywords;

    string _shortdesc;

    std::vector<string>  _longdescs;

    string _description;
};

#endif //PROJECT_SINGLEITEM_H
