#include <utility>

#include <utility>

//
// Created by Jacky Lui on 2019-01-18.
//

#include <iostream>
#include <string>
#include <deque>
#include <Room.h>
#include <nlohmann/json.hpp>

#include "Room.h"

using models::Room;
using nlohmann::json;

using std::make_pair;

const ID& Room::getId() const {
    return _id;
}

const string& Room::getName() const {
    return _name;
}

void Room::setName(
        string name) {
    _name = move(name);
}

const std::vector<string>& Room::get_description() const {
    return _description;
}

void Room::set_description(const std::vector<string>& description) {
    _description = description;
}

std::vector<InventoryItem> Room::getAllObjects() const {
    std::vector<InventoryItem> objects;

    for(auto& obj : _objects) {
        objects.push_back(obj.second);
    }

    return objects;
}

void Room::addObject(ID objectId, const InventoryItem& object) {
    _objects.insert(make_pair(objectId, object));
}

std::vector<Room> Room::getAllDoors() const {
    std::vector<Room> rooms;
    for(auto& d : _doors) {
        rooms.push_back(d.second);
    }

    return rooms;
}
