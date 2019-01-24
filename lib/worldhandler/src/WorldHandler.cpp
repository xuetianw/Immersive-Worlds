//
// Created by Michael on 1/23/19.
//
#include <iostream>
#include <string>
#include <WorldHandler.h>
#include <WorldContainer.h>

//mock implementation of login system. Will change with requirements
using namespace std;

std::string WorldHandler::processCommand(std::string command) {
    //TODO reimplement this over the testing code
    WorldContainer classses = WorldContainer();
    WorldContainer::resetWorld();
    return std::__cxx11::string();
}
