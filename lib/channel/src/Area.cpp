//
// Created by Jan Ycasas on 2019-01-24.
//

#include "Area.h"

channel::Area::Area(int id)
        :_id(id){
    // TODO
}

channel::Area::~Area() {
    // TODO
}

bool channel::Area::addRoom(Room room) {
    auto roomId     = room.getId();
    auto didInsert  = _rooms.insert({roomId, std::move(room)}).second;

    return didInsert;
}

int channel::Area::getId() const {
    // TODO make room ID unique
    return this->_id;
}


