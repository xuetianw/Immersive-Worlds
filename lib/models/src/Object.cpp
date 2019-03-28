//
// Created by asim on 25/03/19.
//

#include "Object.h"

using namespace models;

const ID& Object::getId() const {
    return _id;
}

bool Object::isContainer() const {
    return _isContainer;
}

Object* Object::getParent() const {
    return _parent;
}

void Object::setParent(Object* parent) {
    _parent = parent;
}