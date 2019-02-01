#include "ID.h"


ID::ID(){
    UUIDGen generator;
    _uuid = generator();
}

ID::ID(UUIDGen& generator){
    _uuid = generator();
}

const ID::UUID& ID::getID() const {
    return _uuid;
}