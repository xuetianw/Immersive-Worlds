//
// Created by user on 2/11/19.
//

#ifndef WEBSOCKETNETWORKING_DATASTORAGESERVICE_H
#define WEBSOCKETNETWORKING_DATASTORAGESERVICE_H

#include "SingleItem.h"
#include "CusJson.h"
#include "Room.h"
#include <iostream>

#define BOOST_NO_CXX11_SCOPED_ENUMS
#include <boost/filesystem.hpp>
#undef BOOST_NO_CXX11_SCOPED_ENUMS
using namespace boost::filesystem;

class DataStorageService {
private:
    using Neighbours = std::vector<models::NeighbourInfo>;

    CusJson::Area _jsonArea;
    std::vector<CusJson::Area> _jsonAreas;
    std::unordered_map<int, SingleItem> _objectMap;
    std::unordered_map<int, ID> _jsonRoomIdToUuid;
    std::unordered_map<ID, models::Room> _roomIdToRoom;
    std::unordered_map<ID, Neighbours> _roomIdToNeighbours;
    CusJson::MiniGameList _jsonMiniGameList;

    void configRoomsAndJsonIdMap(const CusJson::Area& jsonArea);
    void configObjectMap(const CusJson::Area& jsonArea, std::unordered_map<int, SingleItem>& jsonIdToItemMap);
    void configNeighboursMap(std::unordered_map<int, ID> jsonIdToUuid, std::vector<CusJson::Room> jsonRooms);
    void buildNeighbours(const std::unordered_map<int, ID>& tmp, const CusJson::Room& jsonRoom, Neighbours& neighbours);

public:
    DataStorageService() {
        json solaceJson = getTestingArea();
        _jsonArea = solaceJson.get<CusJson::Area>();
        configObjectMap(_jsonArea, _objectMap);
        configRoomsAndJsonIdMap(_jsonArea);
        configNeighboursMap(_jsonRoomIdToUuid, _jsonArea._rooms);
        json minigameJson = getTestingMiniGameList();
        _jsonMiniGameList = minigameJson.get<CusJson::MiniGameList>();
    }

    DataStorageService(std::string jsonDirPath) {

        readFromPath(jsonDirPath);
        json minigameJson = getTestingMiniGameList();
        _jsonMiniGameList = minigameJson.get<CusJson::MiniGameList>();
    }

    const CusJson::Area& getJsonArea() const;

    std::unordered_map<ID, models::Room> getRoomIdToRoomMapCopy();
    std::unordered_map<ID, Neighbours> getRoomIdToNeighboursMapCopy();
    SingleItem spawnObjectCopy(int jsonId);

    const CusJson::MiniGameList& getMiniGameList() const;
    void resetObjectsToWorld(std::unordered_map<ID, models::Room>& roomIdToRoomMap);

private:
    json getTestingArea();

    json getTestingMiniGameList();

    void readFromPath(std::string jsonDirPath);
};

#endif //WEBSOCKETNETWORKING_DATASTORAGESERVICE_H
