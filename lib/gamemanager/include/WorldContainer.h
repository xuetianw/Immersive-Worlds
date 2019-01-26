//
// Created by Michael on 1/23/19.
//

#ifndef WEBSOCKETNETWORKING_WORLDCONTAINTER_H
#define WEBSOCKETNETWORKING_WORLDCONTAINTER_H

#include "CusJson.h"
#include "Room.h"

/**
 * This class is intended to contain the world from json
 * and different methods to access rooms/ncs/objects ect
 */
class WorldContainer {
public:
    void loadFromStorage();
    std::string getNPCDesc(const int& roomId);
    CusJson::NPC getNPC(const int& npcId);
    CusJson::Area getArea(const int& areaId);
    channel::Room getRoom(const int& roomId);

    void resetWorld();
private:
    CusJson::World world;

    void printOutWorld(const CusJson::World &world);
};
#endif //WEBSOCKETNETWORKING_WORLDCONTAINTER_H
