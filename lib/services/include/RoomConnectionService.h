#ifndef WEBSOCKETNETWORKING_ROOMCONNECTIONSERVICE_H
#define WEBSOCKETNETWORKING_ROOMCONNECTIONSERVICE_H

#include "ID.h"
#include "Direction.h"
#include "Room.h"

class RoomConnectionService {


public:


private:
    using Room = models::Room;
    using Neighbour = std::vector<std::pair<Direction, ID>>;

    std::unordered_map<ID, Room> _roomIdToRoom;
    std::unordered_map<ID, Neighbour> roomIdToNeighbours;

    void loadFromStorage();
};


#endif //WEBSOCKETNETWORKING_ROOMCONNECTIONSERVICE_H
