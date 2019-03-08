#include <utility>

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

using models::Room;
using nlohmann::json;

using std::string;
using std::deque;
using std::unordered_map;
using std::vector;
using std::move;
using std::make_pair;

Room::Room() : _id({-1}){
  // TODO default constructor
};

models::Room::Room(const models::RoomId &_id, const string &_name,
                   const vector<string> &_description) : _id(_id),
                                                         _name(_name), _description(_description) {}

models::Room::Room( const string &_name,
                   const vector<string> &_description) :
                                                         _name(_name), _description(_description) {}

Room::Room(const CusJson::Room &jsonForm)
        : _id(RoomId(jsonForm._id)), _name(jsonForm._name), _description(jsonForm._jsonDesc) {

}

int Room::getId() const {
  // TODO make room ID unique
  return this->_id.getId();
}

const string& Room::getName() const {
  return _name;
}

void Room::setName(
    string &name) {
  _name = move(name);
}

const vector<string> &models::Room::get_description() const {
  return _description;
}

void models::Room::set_description(const vector<string> &_description) {
  Room::_description = _description;
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

void Room::addRoom(int roomId, Room& room) {
  _doors.emplace(roomId, room);
}

// TODO think about moving this to its own file
models::RoomId::RoomId(int id): _id(id) {

}

int models::RoomId::getId() const{
  return this->_id;
}

models::RoomId::RoomId() {

}