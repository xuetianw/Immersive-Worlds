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

using channel::Room;
using nlohmann::json;

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

void Room::setName(
    string &name) {
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

void Room::addRoom(int roomId, Room& room) {
  _doors.emplace(roomId, room);
}

void Room::setId(int &id) {
  _id =  std::move(id);
}

void Room::setName(string name) {
  _name = std::move(name);
}

void Room::setId(int id) {
  _id = std::move(id);
}


void channel::to_json(json &j, const Room &room) {
    j = json{{"id", room.getId()}, {"name", room.getName()}};
  //TODO implement
}

void channel::from_json(const json &j, Room &room) {
  // for some reason, it needs the cast
  auto name = std::make_unique<string>(j.at("name"));
  room.setName(j.at("name"));
  room.setId(j.at("id"));
  const json& descJson = j.at("desc");
  room._jsonDesc.resize(descJson.size());
  std::copy(descJson.begin(), descJson.end(), room._jsonDesc.begin());
  const json& doorsJson = j.at("doors");
  room._jsonDoors.resize(doorsJson.size());
  std::copy(doorsJson.begin(), doorsJson.end(), room._jsonDoors.begin());
  const json& extDescJson = j.at("extended_descriptions");
  room._jsonDoors.resize(extDescJson.size());
  std::copy(extDescJson.begin(), extDescJson.end(), room._jsonExtDesc.begin());
}

void channel::to_json(json &j, const jsonDoor &door) {
  //TODO implement
}

void channel::from_json(const json &j, jsonDoor &door) {
  door._dir = j.at("dir");
  const json& descJson = j.at("desc");
  door._desc.resize(descJson.size());
  std::copy(descJson.begin(), descJson.end(), door._desc.begin());
  const json& keywordJson = j.at("keywords");
  door._keywords.resize(keywordJson.size());
  std::copy(keywordJson.begin(), keywordJson.end(), door._keywords.begin());
  door._to = j.at("to");
}

void channel::to_json(json &j, const extDesc &extDesc) {
  //TODO implement

}

void channel::from_json(const json &j, extDesc &extDesc) {
  const json& descJson = j.at("desc");
  extDesc._desc.resize(descJson.size());
  std::copy(descJson.begin(), descJson.end(), extDesc._desc.begin());
  const json& keywordJson = j.at("keywords");
  extDesc._keywords.resize(keywordJson.size());
  std::copy(keywordJson.begin(), keywordJson.end(), extDesc._keywords.begin());
}
