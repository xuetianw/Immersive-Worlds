//
// Created by user on 1/23/19.
//

#ifndef WEBSOCKETNETWORKING_WORLDHANDLER_H
#define WEBSOCKETNETWORKING_WORLDHANDLER_H
#include <string>
#include <deque>
#include "WorldContainer.h"
#include "Server.h"

using networking::Message;
class WorldHandler {
public:
    WorldHandler();
    std::string processCommand(const std::string& command);
    std::string processCommand(const std::deque<networking::Message>& messages);
private:
    WorldContainer worldContainer;
};
#endif //WEBSOCKETNETWORKING_WORLDHANDLER_H
