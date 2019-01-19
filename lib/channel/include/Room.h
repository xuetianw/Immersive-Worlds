//
// Created by Jacky Lui on 2019-01-18.
//

#ifndef CHANNEL_ROOM_H
#define CHANNEL_ROOM_H

#include <string>
#include <deque>

using namespace std;

namespace channel {
  class Room {
  public:
    Room(std::string name, std::string description);
    string getDescription();
    string getName();
    deque<string> getCharacters();

  private:
    string name;
    string description;
    deque<string> characters;
  };
}

#endif //CHANNEL_ROOM_H