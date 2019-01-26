#include <utility>

//
// Created by Jacky Lui on 2019-01-18.
//

#include "Room.h"

#include <iostream>
#include <string>
#include <deque>
#include <Room.h>
#include <nlohmann/json.hpp>

using channel::Room;
using nlohmann::json;

Room::Room() {

}

Room::Room(std::string name, int id) {
    this->name = std::move(name);
    this->id = std::move(id);
}

Room::Room(std::string name, std::string description) {
    this->name = std::move(name);
    this->description = std::move(description);
}

std::string
Room::getDescription() {
  return this->description;
}

std::string
Room::getName() const {
  return this->name;
}

std::deque<std::string>
Room::getCharacters() {
  return this->characters;
}

int channel::Room::getId() const {
    return this->id;
}

void Room::setId(int id) {
    this->id = id;
}

void channel::Room::setName(std::string name) {
    this->name = std::move(name);
};

void channel::to_json(json &j, const Room &p) {
    j = json{{"id", p.getId()}, {"name", p.getName()}};

}

void channel::from_json(const json &j, Room &p) {
    p.setId(j.at("id"));
    p.setName(j.at("name"));
}
