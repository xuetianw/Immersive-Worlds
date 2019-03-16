//
// Created by user on 2/11/19.
//

#ifndef WEBSOCKETNETWORKING_DATASTORAGESERVICE_H
#define WEBSOCKETNETWORKING_DATASTORAGESERVICE_H

#include "SingleItem.h"
#include "CusJson.h"
#include "Room.h"
#include <iostream>

class DataStorageService {
private:
    using Neighbours = std::vector<models::NeighbourInfo>;

    CusJson::Area _jsonArea;
    std::unordered_map<int, SingleItem> _objectMap;
    std::unordered_map<int, ID> _jsonRoomIdToUuid;
    std::unordered_map<ID, models::Room> _roomIdToRoom;
    std::unordered_map<ID, Neighbours> _roomIdToNeighbours;

    void configRoomsAndJsonIdMap(const CusJson::Area& jsonArea);
    std::unordered_map<int, SingleItem> configObjectMap(const CusJson::Area& jsonArea);
    void configNeighboursMap(std::unordered_map<int, ID> jsonIdToUuid, std::vector<CusJson::Room> jsonRooms);
    void buildNeighbours(const std::unordered_map<int, ID>& tmp, const CusJson::Room& jsonRoom, Neighbours& neighbours);
    json getTestingArea();

public:
    DataStorageService() {
        json solaceJson = getTestingArea();
        _jsonArea = solaceJson.get<CusJson::Area>();
        _objectMap = configObjectMap(_jsonArea);
        configRoomsAndJsonIdMap(_jsonArea);
        configNeighboursMap(_jsonRoomIdToUuid, _jsonArea._rooms);
    }

    const CusJson::Area& getJsonArea() const;

    std::unordered_map<int, SingleItem> getObjectsFromJson();
    std::unordered_map<ID, models::Room> getRoomIdToRoomMapCopy();
    std::unordered_map<ID, Neighbours> getRoomIdToNeighboursMapCopy();
    SingleItem spawnObjectCopy(int jsonId);

};

#endif //WEBSOCKETNETWORKING_DATASTORAGESERVICE_H
