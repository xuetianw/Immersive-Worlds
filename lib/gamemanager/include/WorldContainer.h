//
// Created by user on 1/23/19.
//

#ifndef WEBSOCKETNETWORKING_WORLDCONTAINTER_H
#define WEBSOCKETNETWORKING_WORLDCONTAINTER_H

#include "CusJson.h"

class WorldContainer {
public:
    void loadFromStorage();
    std::string getNPCDesc(const int& roomId);
    void resetWorld();
private:
    CusJson::World world;

    void printOutWorld(const CusJson::World &world);
};
#endif //WEBSOCKETNETWORKING_WORLDCONTAINTER_H
