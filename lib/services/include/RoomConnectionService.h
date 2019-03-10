#ifndef WEBSOCKETNETWORKING_ROOMCONNECTIONSERVICE_H
#define WEBSOCKETNETWORKING_ROOMCONNECTIONSERVICE_H

#include "DataStorageService.h"
#include "ID.h"
#include "Direction.h"
#include "Room.h"

struct NeighbourInfo {
    Direction direction;
    ID destinationRoomId;
    std::vector<string> descriptions;
};

class RoomConnectionService {
public:
    explicit RoomConnectionService(DataStorageService& dataStorageService)
        : _dataStorageService(dataStorageService) {
        buildDirections();
        loadFromStorage();
    }

    const std::string getRoomName(const ID& roomId);

    const std::string getRoomDescription(const ID& roomId);

    const ID* getNeighbourId(const ID& roomId, std::string directionString);

    const std::vector<std::string> getAvailableDirections(const ID&, std::string directionString);

    const bool isValidDirectionString(std::string directionString);

private:
    using Room = models::Room;
    using Neighbours = std::vector<NeighbourInfo>;

    DataStorageService _dataStorageService;

    std::unordered_map<ID, Room> _roomIdToRoom;
    std::unordered_map<ID, Neighbours> _roomIdToNeighbours;
    std::unordered_map<std::string, Direction> _directions;

    const Room* findRoom(const ID& roomId);

    void buildDirections();

    void loadFromStorage();

    void buildNeighbours(const std::unordered_map<int, ID>& tmp, const CusJson::Room& jsonRoom, Neighbours& neighbours);
};


#endif //WEBSOCKETNETWORKING_ROOMCONNECTIONSERVICE_H
