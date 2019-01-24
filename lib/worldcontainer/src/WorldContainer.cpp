//
// Created by Michael on 1/23/19.
//
#include <iostream>
#include <string>
#include "WorldContainer.h"
//mock implementation of login system. Will change with requirements

#include <CusJson.h>

#include <fstream>
#include <nlohmann/json.hpp>
#include "string"

using json = nlohmann::json;
using namespace std;

static CusJson::World world;
void WorldContainer::jsonTest() {
    std::ifstream solaceFile;
    solaceFile.open("../solace.json"); // Need help with this
    std::string a;
    if (!solaceFile) {
        std::cout << "File was unable to open";
    } else {
        json solaceJson;
        solaceFile >> solaceJson;
        auto solaceWorld = solaceJson.get<CusJson::World>();
        world = solaceWorld;
        std::cout << solaceWorld.area.name << std::endl;
        for (CusJson::NPC npc : solaceWorld.NPCS) {
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
    solaceFile.close();
}

std::string WorldContainer::getNPCDesc(int roomId) {
    json debugNPC = world.NPCS.at(0);
    return debugNPC;
}

void WorldContainer::resetWorld() {
    jsonTest();
}

