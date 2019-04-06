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
    std::unordered_map<int, ID> getJsonIdToRoomIdCopy();

    SingleItem spawnObjectCopy(int jsonId);

    void resetObjectsToWorld(std::unordered_map<ID, models::Room>& roomIdToRoomMap) override;

    void resetDoorStatsToWorld(std::unordered_map<ID, Neighbours>& roomIdToNeighbours) override;

private:

    void loadInJsonAreas();

    void loadInMiniGames();

    /**
     * Since DoorStateJsonWrapper only has information for one side of the door but requires that both sides requiring a state change,
     * This function is to set that doors state on the other side
     * @param roomIdToNeighbours The map of IDs to Neighbours to modify
     * @param doorConfiguration information about the door action reset
     * @param doorState the enum states of the door
     * @param neighbour the original single direction neighbour object which its corresponding neighbour needs modification
     */
    void configDoorOnTheOtherSide(std::unordered_map<ID, Neighbours>& roomIdToNeighbours,
                                  const CusJson::DoorStateJsonWrapper& doorConfiguration,
                                  const models::DoorState& doorState, models::NeighbourInfo neighbour) const;
};

#endif //WEBSOCKETNETWORKING_DATASTORAGESERVICE_H
