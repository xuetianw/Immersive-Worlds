#ifndef WEBSOCKETNETWORKING_ROOMCONNECTIONSERVICE_H
#define WEBSOCKETNETWORKING_ROOMCONNECTIONSERVICE_H

#include "DataStorageService.h"
#include "ID.h"
#include "Room.h"

class RoomConnectionService {
public:
    explicit RoomConnectionService(DataStorageService& dataStorageService)
            : _dataStorageService(dataStorageService) {
        buildDirectionsMap();
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

    //Check if a direction string is a valid direction
    const bool isValidDirectionString(const std::string& directionString);

    //Check if the room exists in the game
    const bool doesRoomExist(const ID& roomId);

private:
    enum Direction {
        NORTH, SOUTH, EAST, WEST
    };

    struct NeighbourInfo {
        Direction direction;
        ID destinationRoomId;
        std::vector<string> descriptions;
    };

    using Room = models::Room;
    using Neighbours = std::vector<NeighbourInfo>;

    DataStorageService _dataStorageService;

    std::unordered_map<ID, Room> _roomIdToRoom;
    std::unordered_map<ID, Neighbours> _roomIdToNeighbours;
    std::unordered_map<std::string, Direction> _directions;
    std::unordered_map<ID, models::MiniGame> _roomIdToMiniGameConnectionsList;

    const Room* findRoom(const ID& roomId);

    //builds a mapping of direction strings to Direction enum
    void buildDirectionsMap();

    //loads maps from json into _roomIdToRoom and _roomIdToNeighbours
    void loadFromStorage();

    //helper method for loadFromStoage to build neighbours
    void buildNeighbours(const std::unordered_map<int, ID>& tmp, const CusJson::Room& jsonRoom, Neighbours& neighbours);
};


#endif //WEBSOCKETNETWORKING_ROOMCONNECTIONSERVICE_H