//
// Created by Jan Ycasas on 2019-01-24.
//

#include <iostream>
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

channel::Area::Area() {}

void channel::from_json(const json &j, channel::Area &area) {
    // TODO complete this
    vector<Room> tempRoomContainer;
    const json& roomsJson = j.at("ROOMS");
    tempRoomContainer.resize(roomsJson.size());
    std::copy(roomsJson.begin(), roomsJson.end(), tempRoomContainer.begin());
    for (Room room : tempRoomContainer) {
        bool inputSuccess = area.addRoom(room);
        if (inputSuccess) {
            std::cout << room.getName() << " Room added successfully\n";
        } else {
            std::cout << room.getName() << " Room added unsucessfully\n";
        }
    }
}


