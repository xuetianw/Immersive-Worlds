//
// Created by Lucy on 2019-01-18.
//

#ifndef PROJECT_OBJECT_H
#define PROJECT_OBJECT_H

#include <string>


class Object {

    public:
        enum class ItemType {
            CLOTHING,
            WEAPON
        };

        Object();
        Object(int anId,
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


#endif //PROJECT_OBJECT_H
