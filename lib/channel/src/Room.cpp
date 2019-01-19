#include <utility>

//
// Created by Jacky Lui on 2019-01-18.
//

#include "Room.h"

#include <iostream>
#include <string>
#include <deque>

using namespace std;
using channel::Room;

namespace channel {

Room::Room(string name, string description) {
    this->name = std::move(name);
    this->description = std::move(description);
  }
};

string
Room::getDescription() {
  return this->description;
}

string
Room::getName() {
  return this->name;
}

deque<string>
Room::getCharacters() {
  return this->characters;
};