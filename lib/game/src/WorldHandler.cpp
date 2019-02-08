//
// Created by Michael on 1/23/19.
//
#include <iostream>
#include <string>
#include <WorldHandler.h>
#include <WorldContainer.h>
#include "Server.h"

using networking::Message;

//mock implementation of login system. Will change with requirements
using namespace std;

std::string WorldHandler::processCommand(const std::string& command) {
    //TODO reimplement this over the testing code
    /**
     * Some form of parsing here
     * using worldcontainer to get world info
     **/
    return "string mock process";
}

std::string WorldHandler::processCommand(const std::deque<networking::Message>& messages) {
    return "deques<Message> mock process";
}

WorldHandler::WorldHandler() {
    worldContainer = WorldContainer();
    worldContainer.resetWorld();
}

std::string WorldHandler::getAreaName(const int &id) {
    return this->worldContainer.getRoomName(id);
}
