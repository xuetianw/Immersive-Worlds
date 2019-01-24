#include <utility>

//
// Created by Jacky Lui on 2019-01-18.
//

#include "Room.h"

#include <iostream>
#include <string>
#include <deque>

using channel::Room;
using std::string;
using std::deque;
using std::unordered_map;
using std::vector;

Room::Room() {
  // TODO default constructor
};

Room::Room(const string& name, const string& description)
        : _name(name), _description(description) {
  // TODO
}


Room::Room(const Room& that) {
  // TODO copy constructor
}

int Room::getId() const {
  // TODO make room ID unique
  return _id;
}

const string& Room::getName() const {
  // TODO
}

void Room::setName(const string& name) {
  // TODO
}

const string& Room::getDescription() const {
  // TODO
}

void Room::setDescription(const string& name) {
  // TODO
}

vector<string> Room::getAllAvatars() const {
  // TODO
}

void Room::addAvatar(const string& avatar) {
  // TODO
}

vector<string> Room::getAllObjects() const {
  // TODO
}

void Room::addObject(const string& object) {
  // TODO
}

vector<string> Room::getAllDoors() const {
  // TODO
}

void Room::addRoom(const Room& room) {
  // TODO
}