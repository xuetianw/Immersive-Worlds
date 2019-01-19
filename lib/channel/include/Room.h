//
// Created by Jacky Lui on 2019-01-18.
//

#ifndef CHANNEL_ROOM_H
#define CHANNEL_ROOM_H

#include <string>
#include <deque>

namespace channel {
  class Room {
  public:
    Room(std::string name, std::string description);
    std::string getDescription();
    std::string getName();
    deque<string> getCharacters();

  private:
    std::string name;
    std::string description;
    std::deque<string> characters;
  };
}

#endif //CHANNEL_ROOM_H