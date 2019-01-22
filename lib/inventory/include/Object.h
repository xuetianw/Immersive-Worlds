//
// Created by Lucy on 2019-01-18.
//

#ifndef PROJECT_OBJECT_H
#define PROJECT_OBJECT_H

#include <string>
using namespace std;

class Object {
    private:
        int id;
        string keyword, shortdesc, longdesc, description;
    public:
        Object(int anId, string aKeyword, string aShortdesc, string aLongdesc, string aDescription);
        int getId() const;
        string getKeyword() const;
        string getShortdesc() const;
        string getLongdesc() const;
        string getDescription() const;

};


#endif //PROJECT_OBJECT_H
