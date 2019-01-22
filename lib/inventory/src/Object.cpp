//
// Created by Lucy on 2019-01-18.
//

#include "../include/Object.h"

using namespace std;

Object::Object() : id(0), keyword(""), shortdesc(""), longdesc("")

Object::Object(int anId, string aKeyword, string aShortdesc, string aLongdesc, string aDescription)
: id(anId), keyword(aKeyword), shortdesc(aShortdesc), description(aDescription){}

int Object::getId() const { return id }
string Object::getKeyword() const { return keyword }
string Object::getShortdesc() const { return shortdesc }
string Object::getLongdesc() const { return longdesc }
string Object::getDescription() const { return description }


