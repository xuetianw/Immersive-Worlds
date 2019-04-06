#ifndef WEBSOCKETNETWORKING_DATASTORAGESTUB_H
#define WEBSOCKETNETWORKING_DATASTORAGESTUB_H

#include "gmock/gmock.h"
#include "AbstractDataStorageService.h"

class DataStorageStub : public AbstractDataStorageService {
public:
    MOCK_METHOD0(getRoomIdToRoomMapCopy, std::unordered_map<ID, models::Room>());
    MOCK_METHOD0(getRoomIdToNeighboursMapCopy, std::unordered_map<ID, std::vector<models::NeighbourInfo>>());

    //TODO resetObjectsToWorld will be moved to "InventoryService"
    //this line is need to get the unit tests to work
    MOCK_METHOD1(resetObjectsToWorld, void(std::unordered_map<ID, models::Room>
        &));

    MOCK_METHOD1(resetDoorStatsToWorld, void(std::unordered_map<ID, Neighbours>& roomIdToNeighbours));

};

#endif //WEBSOCKETNETWORKING_DATASTORAGESTUB_H
