//
// Created by Jacky Lui on 2019-01-18.
//

#ifndef CHANNEL_ROOM_H
#define CHANNEL_ROOM_H

#include <utility>
#include <string>
#include <deque>
#include <nlohmann/json.hpp>

#include <unordered_map>
#include <vector>

using json = nlohmann::json;
using std::string;
using std::deque;
using std::unordered_map;
using std::vector;

namespace channel {
    // JSON stuff
    struct jsonDoor {
        string _dir;
        vector<string> _desc;
        vector<string> _keywords;
        int _to;
    };
    struct extDesc {
        vector<string> _keywords;
        vector<string> _desc;
    };


  class Room {
    int _id = 0;  //TODO make room id unique
    string _name;
    string _description;
    unordered_map<int, string> _avatars;  //TODO change generic type to Avatar/Character
    unordered_map<int, string> _objects;  //TODO change generic type to ItemObject
    unordered_map<int, Room&> _doors;

//    //json stuff
//    vector<string>_jsonDesc;
//    vector<jsonDoor> _jsonDoors;
//    vector<extDesc> _jsonExtDesc;

  public:
    Room();

    Room(const string& name, const string& description);

    Room(const Room& that);

    ~Room();

    int getId() const;

    void setId(int &id);

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

    //json stuff
    void setName(string name);
    void setId(int id);
    vector<string>_jsonDesc;
    vector<jsonDoor> _jsonDoors;
    vector<extDesc> _jsonExtDesc;
  };
  void to_json(json &j, const Room &room);
  void from_json(const json &j, Room &room);
  void to_json(json &j, const jsonDoor &door);
  void from_json(const json &j, jsonDoor &door);
  void to_json(json &j, const extDesc &extDesc);
  void from_json(const json &j, extDesc &extDesc);

}

#endif //CHANNEL_ROOM_H