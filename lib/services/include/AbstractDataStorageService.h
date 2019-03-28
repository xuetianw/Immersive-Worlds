#ifndef WEBSOCKETNETWORKING_DATASTORAGESERVICEINTERFACE_H
#define WEBSOCKETNETWORKING_DATASTORAGESERVICEINTERFACE_H

#include <ID.h>
#include <Room.h>

class AbstractDataStorageService {
public:
    using Neighbours = std::vector<models::NeighbourInfo>;

    virtual std::unordered_map<ID, models::Room> getRoomIdToRoomMapCopy() = 0;

    virtual std::unordered_map<ID, Neighbours> getRoomIdToNeighboursMapCopy() = 0;

    virtual void resetObjectsToWorld(std::unordered_map<ID, models::Room>& roomIdToRoomMap) = 0;

};

#endif //WEBSOCKETNETWORKING_DATASTORAGESERVICEINTERFACE_H
