#include <algorithm>

#include "RoomConnectionService.h"

/*
 * PUBLIC
 */
const std::string RoomConnectionService::getRoomName(const ID& roomId) {
    const Room* room = findRoom(roomId);

    if (room == nullptr) {
        return nullptr;
    }

    return room->getName();
}

const std::string RoomConnectionService::getRoomDescription(const ID& roomId) {
    const Room* room = findRoom(roomId);

    if (room == nullptr) {
        return nullptr;
    }

    string result = "";

    for (auto text : room->getDescription()) {
        result += text;
    }

    return result;
}

const ID* RoomConnectionService::getNeighbourId(const ID& roomId, const std::string directionString) {
    if (!isValidDirectionString(directionString)) {
        return nullptr;
    }

    Direction direction = _directions[directionString];

    auto neighbourIt = _roomIdToNeighbours.find(roomId);
    if (neighbourIt == _roomIdToNeighbours.end()) {
        return nullptr;
    }
    Neighbours neighbours = neighbourIt->second;

    auto neighbourInfo = find(neighbours.begin(), neighbours.end(),
                              [&](const NeighbourInfo& info) { return info.direction == direction; });

    return &(*neighbourInfo).destinationRoomId;
}

const std::vector<std::string> RoomConnectionService::getAvailableDirections(const ID&, std::string direction) {
    return std::vector<string>();
}

const bool RoomConnectionService::isValidDirectionString(const std::string directionString) {
    return _directions.find(directionString) != _directions.end();
}

/*
 * PRIVATE
 */
const models::Room* RoomConnectionService::findRoom(const ID& roomId) {
    auto it = _roomIdToRoom.find(roomId);

    if (it == _roomIdToRoom.end()) {
        return nullptr;
    }

    return &(it->second);
}

void RoomConnectionService::buildDirections() {
    _directions["north"] = Direction::NORTH;
    _directions["south"] = Direction::SOUTH;
    _directions["east"] = Direction::EAST;
    _directions["west"] = Direction::WEST;
}


void RoomConnectionService::loadFromStorage() {
    std::unordered_map<int, ID> tmp;
    std::vector<CusJson::Room> jsonRooms = _dataStorageService.getJsonArea()._rooms;

    for (const CusJson::Room& jsonRoom : jsonRooms) {
        Room room{jsonRoom};
        const ID& roomId = room.getId();

        tmp.emplace(jsonRoom._id, roomId);
        _roomIdToRoom.emplace(roomId, room);
    }

    for (const CusJson::Room& jsonRoom : jsonRooms) {
        Neighbours neighbours;

        buildNeighbours(tmp, jsonRoom, neighbours);

        _roomIdToNeighbours.try_emplace(tmp[jsonRoom._id], neighbours);
    }
}

void RoomConnectionService::buildNeighbours(const std::unordered_map<int, ID>& tmp, const CusJson::Room& jsonRoom,
                                            RoomConnectionService::Neighbours& neighbours) {
    for (const CusJson::JsonDoor& jsonDoor : jsonRoom._jsonDoors) {
        NeighbourInfo neighbourInfo;
        neighbourInfo.direction = _directions[jsonDoor._dir];
        neighbourInfo.destinationRoomId = tmp.at(jsonDoor._to);
        neighbourInfo.descriptions = jsonDoor._desc;

        neighbours.emplace_back(neighbourInfo);
    }
}