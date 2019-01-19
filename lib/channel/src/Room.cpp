#include <utility>

//
// Created by Jacky Lui on 2019-01-18.
//

#include "Room.h"

#include <iostream>
#include <string>
#include <deque>

using channel::Room;

Room::Room(std::string name, std::string description) {
    this->name = std::move(name);
    this->description = std::move(description);
  }
};

std::string
Room::getDescription() {
  return this->description;
}

std::string
Room::getName() {
  return this->name;
}

std::deque<string>
Room::getCharacters() {
  return this->characters;
};