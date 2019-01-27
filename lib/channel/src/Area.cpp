//
// Created by Jan Ycasas on 2019-01-24.
//

#include "Area.h"

using channel::Area;
using std::move;

Area::Area(int id)
        :_id(id){
    // TODO
}

Area::~Area() {
    // TODO
}

bool Area::addRoom(Room room) {
    auto roomId     = room.getId();
    auto didInsert  = _rooms.insert({roomId, move(room)}).second;

    return didInsert;
}

int Area::getId() const {
    // TODO make room ID unique
    return _id;
}


