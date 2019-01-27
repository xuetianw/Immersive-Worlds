//
// Created by Jacky Lui on 2019-01-18.
//

#ifndef CHANNEL_ROOM_H
#define CHANNEL_ROOM_H

#include <utility>
#include <string>
#include <deque>
#include <unordered_map>
#include <vector>

using std::string;
using std::deque;
using std::unordered_map;
using std::vector;

namespace channel {
  class Room {
    const int _id = 0;  //TODO make room id unique
    string _name;
    string _description;
    unordered_map<int, string> _avatars;  //TODO change generic type to Avatar/Character
    unordered_map<int, string> _objects;  //TODO change generic type to ItemObject
    unordered_map<int, Room&> _doors;

  public:
    Room();

    Room(const string& name, const string& description);

    Room(const Room& that);

    ~Room();

    int getId() const;

    const string& getName() const;

    void setName(string& name);

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

#endif //CHANNEL_ROOM_H