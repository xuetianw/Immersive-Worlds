//
// Created by Jan Ycasas on 2019-01-24.
//

#include "World.h"

channel::World::World(int id) {
    // TODO 
    this->_id = std::move(id);
}

channel::World::~World() {
    // TODO
}

bool channel::World::addArea(Area area) {
    auto areaId     = area.getId();
    auto newArea    = std::move(area);
    auto didInsert  = _areas.insert({areaId, newArea}).second;

    return didInsert;
}

int channel::World::getId() const {
    // TODO make room ID unique
    return this->_id;
}


