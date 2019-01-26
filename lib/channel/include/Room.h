//
// Created by Jacky Lui on 2019-01-18.
//

#ifndef CHANNEL_ROOM_H
#define CHANNEL_ROOM_H

#include <string>
#include <deque>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace channel {
  class Room {
  public:
    Room();
    Room(std::string name, int id);
    Room(std::string name, std::string description);
    int getId() const;
    void setId(int id);
    std::string getName() const;
    void setName(std::string name);
    std::string getDescription();
    std::deque<std::string> getCharacters();

  private:
    int id;
    std::string name;
    std::string description;
    std::deque<std::string> characters;
    std::vector<std::string> paths; // placeholder for now
    std::vector<std::string> extendedDesc; // placeholder for now
  };
  void to_json(json &j, const Room &p);
  void from_json(const json &j, Room &p);
}

#endif //CHANNEL_ROOM_H