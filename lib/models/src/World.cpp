//
// Created by Jan Ycasas on 2019-01-24.
//

#include "World.h"

using models::World;
using std::move;

World::World(int id)
        :_id(id){
    // TODO
}

World::~World() {
    // TODO
}

bool models::World::addArea(Area area) {
    auto areaId     = area.getId();
    auto didInsert  = _areas.insert({areaId, move(area)}).second;

    return didInsert;
}

int models::World::getId() const {
    // TODO make room ID unique
    return _id;
}


