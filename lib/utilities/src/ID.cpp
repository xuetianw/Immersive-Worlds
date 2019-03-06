#include "ID.h"


ID::ID() {
    UUIDGen generator;
    _uuid = generator();
}

ID::ID(int id) : _id(id) {
    UUIDGen generator;
    _uuid = generator();
}

ID::ID(UUIDGen& generator){
    _uuid = generator();
}

const UUID& ID::getID() const {
    return _uuid;
}