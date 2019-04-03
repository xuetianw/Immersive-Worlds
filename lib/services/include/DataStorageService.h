//
// Created by user on 2/11/19.
//

#ifndef WEBSOCKETNETWORKING_DATASTORAGESERVICE_H
#define WEBSOCKETNETWORKING_DATASTORAGESERVICE_H

#include "SingleItem.h"
#include "CusJson.h"
#include "Room.h"
#include "AbstractDataStorageService.h"
#include <iostream>

#define BOOST_NO_CXX11_SCOPED_ENUMS
#include <boost/filesystem.hpp>
#undef BOOST_NO_CXX11_SCOPED_ENUMS
using namespace boost::filesystem;

class DataStorageService : public AbstractDataStorageService {
private:
    using Neighbours = std::vector<models::NeighbourInfo>;

    const std::string ABSOLUTE_PATH_CONFIG_DIR = "config/";
    const std::string AREAS_DIRECTORY = "areas/";
    const std::string MINIGAMES_DIRECTORY = "minigames/";
    const std::string MINIGAME_FILE_NAME = "minigame.json";

    CusJson::Area _jsonArea;
    std::vector<CusJson::Area> _jsonAreas;
    std::unordered_map<int, SingleItem> _objectMap;
    std::unordered_map<int, ID> _jsonRoomIdToUuid;
    std::unordered_map<ID, models::Room> _roomIdToRoom;
    std::unordered_map<ID, Neighbours> _roomIdToNeighbours;
    
    CusJson::MiniGameList _jsonMiniGameList;
    std::unordered_map<ID, models::MiniGame> _roomIdToMiniGameConnectionsList;

    void configRoomsAndJsonIdMap(const CusJson::Area& jsonArea);
    void configObjectMap(const CusJson::Area& jsonArea, std::unordered_map<int, SingleItem>& jsonIdToItemMap);
    void configRoomsAndMiniGame(const CusJson::MiniGameList& jsonMiniGameList);
    void configNeighboursMap(std::unordered_map<int, ID> jsonIdToUuid, std::vector<CusJson::Room> jsonRooms);
    void buildNeighbours(const std::unordered_map<int, ID>& tmp, const CusJson::Room& jsonRoom, Neighbours& neighbours);

public:
    DataStorageService() {
        loadInJsonAreas();
        loadInMiniGames();
    }

    std::unordered_map<ID, models::Room> getRoomIdToRoomMapCopy() override;

    std::unordered_map<ID, Neighbours> getRoomIdToNeighboursMapCopy() override;

    std::unordered_map<ID, models::MiniGame> getRoomIdToMiniGameCopy();

    SingleItem spawnObjectCopy(int jsonId);
    
    void resetObjectsToWorld(std::unordered_map<ID, models::Room>& roomIdToRoomMap) override;

private:

    void loadInJsonAreas();

    void loadInMiniGames();
};

#endif //WEBSOCKETNETWORKING_DATASTORAGESERVICE_H
