//
// Created by Michael on 1/23/19.
//
#include <iostream>
#include <string>
#include "../include/WorldContainer.h"
//mock implementation of login system. Will change with requirements

#include <CusJson.h>

#include <fstream>
#include <nlohmann/json.hpp>
#include <WorldContainer.h>

#include "string"

using json = nlohmann::json;
using namespace std;

void WorldContainer::loadFromStorage() {
    std::ifstream solaceFile;
    solaceFile.open("solace.json"); // Path is not set properly at the moment
    std::string a;
    if (!solaceFile) {
        std::cout << "File was unable to open";
    } else {
        std::cout << "File was found";
        json solaceJson;
        solaceFile >> solaceJson;
        auto solaceWorld = solaceJson.get<CusJson::World>();
        world = solaceWorld;
        printOutWorld(world); // debug purposes
    }
    solaceFile.close();
}

std::string WorldContainer::getNPCDesc(const int& roomId) {

    return "mocked desc";
}

void WorldContainer::resetWorld() {
    loadFromStorage();
}

void WorldContainer::printOutWorld(const CusJson::World &world) {
    cout << world.area.name << std::endl;
    for (CusJson::NPC npc : world.NPCS) {
        std::cout << "npc id: " + std::to_string(npc.id) << std::endl;
        for (std::string keyword : npc.keywords) {
            std::cout << "keywords: "+ keyword << std::endl;
        }

        std::cout << "shortdesc: "+ npc.shortdesc << std::endl;
        for (std::string longdesc : npc.longdesc) {
            std::cout << "longdesc: "+ longdesc << std::endl;
        }

        for (std::string description : npc.description) {
            std::cout << description << std::endl;
        }
        std::cout << std::endl;
    }
}

// To implement later
CusJson::NPC WorldContainer::getNPC(const int &npcId) {
    return CusJson::NPC();
}

CusJson::Area WorldContainer::getArea(const int &areaId) {
    return CusJson::Area();
}

channel::Room WorldContainer::getRoom(const int &roomId) {
    // return channel::Room(__cxx11::basic_string(), __cxx11::basic_string());
}

