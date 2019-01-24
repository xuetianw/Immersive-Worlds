//
// Created by user on 1/23/19.
//

#ifndef WEBSOCKETNETWORKING_WORLDCONTAINTER_H
#define WEBSOCKETNETWORKING_WORLDCONTAINTER_H

#include "CusJson.h"

class WorldContainer {
public:
    static CusJson::World world;
    static void jsonTest();
    std::string getNPCDesc(int roomId);
    static void resetWorld();
};
#endif //WEBSOCKETNETWORKING_WORLDCONTAINTER_H
