#ifndef WEBSOCKETNETWORKING_ROOMCONNECTIONSERVICE_H
#define WEBSOCKETNETWORKING_ROOMCONNECTIONSERVICE_H

#include "DataStorageService.h"
#include "ID.h"
#include "Room.h"

class RoomConnectionService {
public:
    explicit RoomConnectionService(DataStorageService& dataStorageService)
            : _dataStorageService(dataStorageService) {
//        buildDirectionsMap();
        loadFromStorage();
    }

    const ID& getStartingRoom();

    const std::optional<std::string> getRoomName(const ID& roomId);

    const std::optional<std::string> getRoomDescription(const ID& roomId);

    //Get the ID of a the neighbour of a room in a specific direction
    const std::optional<std::reference_wrapper<const ID>>
    getNeighbourId(const ID& roomId, const std::string& directionString);

    //Return a vector of direction strings available for a room
    const std::vector<std::string> getAvailableRoomDirections(const ID& roomId);

    std::vector<ID> getAllNeighbourId(const ID& roomId);

    //Check if a direction string is a valid direction
    const bool isValidDirectionString(const std::string& directionString);

    //Check if the room exists in the game
    const bool doesRoomExist(const ID& roomId);

private:
    using Room = models::Room;
    using Neighbours = std::vector<models::NeighbourInfo>;

    DataStorageService& _dataStorageService;

    std::unordered_map<ID, Room> _roomIdToRoom;
    std::unordered_map<ID, Neighbours> _roomIdToNeighbours;
    std::unordered_map<std::string, models::Direction> _directions = models::DIRECTION_STRING_TO_ENUM_MAP;

    const Room* findRoom(const ID& roomId);

    //builds a mapping of direction strings to Direction enum
//    void buildDirectionsMap();

    //loads maps from json into _roomIdToRoom and _roomIdToNeighbours
    void loadFromStorage();

};


#endif //WEBSOCKETNETWORKING_ROOMCONNECTIONSERVICE_H
