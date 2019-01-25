//
// Created by Lucy on 2019-01-18.
//

#include "Object.h"

using namespace std;

Object::Object() : _id(0), _keyword(""), _shortdesc(""), _longdesc("") {}
Object::Object(int anId, string aKeyword, string aShortdesc, string aLongdesc, string aDescription)
: _id(anId), _keyword(aKeyword), _shortdesc(aShortdesc), _description(aDescription){}

int Object::getId() const { return _id; }
string Object::getKeyword() const { return _keyword; }
string Object::getShortdesc() const { return _shortdesc; }
string Object::getLongdesc() const { return _longdesc; }
string Object::getDescription() const { return _description; }


