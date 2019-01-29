//
// Created by Michael on 1/23/19.
//

#ifndef WEBSOCKETNETWORKING_WORLDCONTAINTER_H
#define WEBSOCKETNETWORKING_WORLDCONTAINTER_H

#include <Area.h>
#include <World.h>
#include "CusJson.h"
#include "Room.h"

/**
 * This class is intended to contain the world from json
 * and different methods to access rooms/ncs/objects ect
 */
class WorldContainer {
public:
    WorldContainer();
    void loadFromStorage();
    void resetWorld();
private:
    channel::Area area = channel::Area(0);// TODO clean up temp id

    void printOutArea(const channel::Area &area);
    json debugArea();
};
#endif //WEBSOCKETNETWORKING_WORLDCONTAINTER_H
