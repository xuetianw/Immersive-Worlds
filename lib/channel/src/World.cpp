//
// Created by Jan Ycasas on 2019-01-24.
//

#include "World.h"

channel::World::World(int id)
        :_id(id){
    // TODO
}

channel::World::~World() {
    // TODO
}

bool channel::World::addArea(Area area) {
    auto areaId     = area.getId();
    auto didInsert  = _areas.insert({areaId, std::move(area)}).second;

    return didInsert;
}

int channel::World::getId() const {
    // TODO make room ID unique
    return this->_id;
}


