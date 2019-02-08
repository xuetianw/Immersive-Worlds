//
// Created by Jan Ycasas on 2019-01-24.
//

#include <iostream>
#include <Area.h>

#include "Area.h"

using channel::Area;
using std::move;

Area::Area(int id)
        : _id(id) {
    // TODO
}

Area::~Area() {
    // TODO
}

Area::Area() {}

Area::Area(const CusJson::Area& jsonArea)
        : _name(jsonArea._name) {
    for (const CusJson::Room &jsonRoom : jsonArea._rooms) {
        this->addRoom(jsonRoom);
    }
}

bool Area::addRoom(const Room &room) {
    auto roomId = room.getId();
    auto didInsert = _rooms.emplace(roomId, room).second;

    return didInsert;
}

int Area::getId() const {
    // TODO make room ID unique
    return _id;
}

string Area::getName() {
    return _name;
}

channel::Room channel::Area::getRoom(const channel::RoomId &roomId) {
    try {
        auto room = _rooms.at(roomId.getId());
        return room;
    } catch (std::out_of_range e) {
        std::cerr << "Room with " << roomId.getId() << "does not exist";
    }
    return Room();
}
