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
using std::move;
using std::make_pair;

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

Room::~Room() {
  // TODO destructor
}

int Room::getId() const {
  // TODO make room ID unique
  return _id;
}

const string& Room::getName() const {
  return _name;
}

void Room::setName(string& name) {
  _name = move(name);
}

const string& Room::getDescription() const {
  return _description;
}

void Room::setDescription(string& description) {
  _description = move(description);
}

vector<string> Room::getAllAvatars() const {
  vector<string> avatars;

  for(auto& a : _avatars) {
    avatars.push_back(a.second);
  }

  return avatars;
}

void Room::addAvatar(int avatarId, const string& avatar) {
  _avatars.insert(make_pair(avatarId, avatar));
}

vector<string> Room::getAllObjects() const {
  vector<string> objects;

  for(auto& o : _objects) {
    objects.push_back(o.second);
  }

  return objects;
}

void Room::addObject(int objectId, const string& object) {
  _objects.insert(make_pair(objectId, object));
}

vector<Room> Room::getAllDoors() const {
  vector<Room> rooms;

  for(auto& d : _doors) {
    rooms.push_back(d.second);
  }

  return rooms;
}

void Room::addRoom(int roomId, const Room& room) {
  _doors.insert(make_pair(roomId, room));
}