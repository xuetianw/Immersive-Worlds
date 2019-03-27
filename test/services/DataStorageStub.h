#ifndef WEBSOCKETNETWORKING_DATASTORAGESTUB_H
#define WEBSOCKETNETWORKING_DATASTORAGESTUB_H

#include "gmock/gmock.h"
#include "DataStorageServiceInterface.h"

class DataStorageStub : public DataStorageServiceInterface {
public:
    MOCK_METHOD0(getRoomIdToRoomMapCopy, std::unordered_map<ID, models::Room>());
    MOCK_METHOD0(getRoomIdToNeighboursMapCopy, std::unordered_map<ID, std::vector<models::NeighbourInfo>>());
    MOCK_METHOD1(resetObjectsToWorld, void(std::unordered_map<ID, models::Room>
        &));
};

#endif //WEBSOCKETNETWORKING_DATASTORAGESTUB_H
