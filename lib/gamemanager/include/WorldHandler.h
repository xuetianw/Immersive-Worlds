//
// Created by user on 1/23/19.
//

#ifndef WEBSOCKETNETWORKING_WORLDHANDLER_H
#define WEBSOCKETNETWORKING_WORLDHANDLER_H
#include <string>
#include "WorldContainer.h"

class WorldHandler {
public:
    std::string processCommand(std::string command);
};
#endif //WEBSOCKETNETWORKING_WORLDHANDLER_H
