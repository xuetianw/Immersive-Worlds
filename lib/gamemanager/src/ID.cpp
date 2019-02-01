#include "ID.h"


ID::ID(){
    boost::uuids::random_generator generator;
    _uuid = generator();
}

ID::ID(boost::uuids::random_generator &generator){
    _uuid = generator();
}

boost::uuids::uuid ID::getID() const {
    return _uuid;
}