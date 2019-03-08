#ifndef WEBSOCKETNETWORKING_ROOMCONNECTIONSERVICE_H
#define WEBSOCKETNETWORKING_ROOMCONNECTIONSERVICE_H

#include "DataStorage.h"
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
    RoomConnectionService() : _dataStorage() {
        buildDirections();
        loadFromStorage();
    }


private:
    using Room = models::Room;
    using Neighbours = std::vector<NeighbourInfo>;

    DataStorage _dataStorage;

    std::unordered_map<ID, Room> _roomIdToRoom;
    std::unordered_map<ID, Neighbours> _roomIdToNeighbours;
    std::unordered_map<std::string, Direction> _directions;

    void buildDirections();
    void loadFromStorage();

    void buildNeighbours(const std::unordered_map<int, ID>& tmp, const CusJson::Room& jsonRoom, Neighbours& neighbours);
};


#endif //WEBSOCKETNETWORKING_ROOMCONNECTIONSERVICE_H
