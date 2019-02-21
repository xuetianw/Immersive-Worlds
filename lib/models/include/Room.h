//
// Created by Jacky Lui on 2019-01-18.
//

#ifndef MODELS_ROOM_H
#define MODELS_ROOM_H

#include <utility>
#include <string>
#include <deque>
#include <nlohmann/json.hpp>
#include <CusJson.h>

#include <unordered_map>
#include <vector>

using json = nlohmann::json;
using std::string;
using std::deque;
using std::unordered_map;
using std::vector;

namespace models {
  class RoomId {
  private:
    int _id;
  public:
    int getId() const;
    RoomId();
    RoomId(int i);
  };

  class Room {
    RoomId _id;  //TODO make room id unique
    string _name;
    string _description;
    unordered_map<int, string> _avatars;  //TODO change generic type to Avatar/Character
    unordered_map<int, string> _objects;  //TODO change generic type to ItemObject
    unordered_map<int, Room&> _doors;

  public:
    Room();

    Room(const string& name, const string& description);

    Room(const CusJson::Room &jsonForm);

    int getId() const;

    const string& getName() const;

    void setName(string &name);

    const string& getDescription() const;

    void setDescription(string& description);

    vector<string> getAllAvatars() const;

    void addAvatar(int id, const string& avatar);

    vector<string> getAllObjects() const;

    void addObject(int objectId, const string& object);

    vector<Room> getAllDoors() const;

    void addRoom(int roomId, Room& room);

  };

}

#endif //MODELS_ROOM_H