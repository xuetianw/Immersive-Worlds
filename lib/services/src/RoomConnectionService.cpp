#include "RoomConnectionService.h"

/*
 * PUBLIC
 */



/*
 * PRIVATE
 */
void RoomConnectionService::buildDirections() {
    _directions["north"] = Direction::NORTH;
    _directions["south"] = Direction::SOUTH;
    _directions["east"] = Direction::EAST;
    _directions["west"] = Direction::WEST;
}


void RoomConnectionService::loadFromStorage() {
    std::unordered_map<int, ID> tmp;
    std::vector<CusJson::Room> jsonRooms = _dataStorage.getJsonArea()._rooms;

    for (const CusJson::Room& jsonRoom : jsonRooms) {
        Room room{jsonRoom};
        const ID& roomId = room.getId();

        tmp.emplace(jsonRoom._id, roomId);
        _roomIdToRoom.emplace(roomId, room);
    }

    for (const CusJson::Room& jsonRoom : jsonRooms) {
        Neighbours neighbours;

        buildNeighbours(tmp, jsonRoom, neighbours, 0);

        _roomIdToNeighbours.try_emplace(tmp[jsonRoom._id], neighbours);
    }
}

void RoomConnectionService::buildNeighbours(const std::unordered_map<int, ID>& tmp, const CusJson::Room& jsonRoom,
                                            RoomConnectionService::Neighbours& neighbours) {
    for (const CusJson::JsonDoor& jsonDoor : jsonRoom._jsonDoors) {
        NeighbourInfo neighbourInfo;
        neighbourInfo.direction = _directions[jsonDoor._dir];
        neighbourInfo.destinationRoomId = tmp[jsonDoor._to];
        neighbourInfo.descriptions = jsonDoor._desc;

        neighbours.emplace_back(neighbourInfo);
    }
}