#include <algorithm>

#include "RoomConnectionService.h"

/*
 * PUBLIC
 */

const ID& RoomConnectionService::getStartingRoom() {
    //return the ID of first entry of the _roomIdToRoom map as the starting room id
    //TODO find a more elegant way to choose starting room
    auto it = std::find_if(_roomIdToRoom.begin(), _roomIdToRoom.end(),
                           [&](const std::pair<ID, Room>& pair) { return true; });

    return it->first;
}

const std::string RoomConnectionService::getRoomName(const ID& roomId) {
    if (!doesRoomExist(roomId)) {
        return nullptr;
    }

    const Room* room = findRoom(roomId);

    return room->getName();
}

const std::string RoomConnectionService::getRoomDescription(const ID& roomId) {
    if (!doesRoomExist(roomId)) {
        return nullptr;
    }

    const Room* room = findRoom(roomId);
    string descriptionString;

    for (auto& text : room->getDescription()) {
        descriptionString += text;
    }

    return descriptionString;
}

const ID* RoomConnectionService::getNeighbourId(const ID& roomId, const std::string directionString) {
    if (!isValidDirectionString(directionString)
        || !doesRoomExist(roomId)
        || _roomIdToNeighbours.count(roomId) == 0) {
        return nullptr;
    }

    const Direction direction = _directions.at(directionString);
    const Neighbours& neighbours = _roomIdToNeighbours.at(roomId);

    //iterate through all neighbours to find a matching one
    auto neighbour = find_if(neighbours.begin(), neighbours.end(),
                             [&](const NeighbourInfo& info) { return info.direction == direction; });

    if (neighbour == neighbours.end()) {
        //no matching neighbour
        return nullptr;
    }

    return &(*neighbour).destinationRoomId;
}

const std::vector<std::string> RoomConnectionService::getAvailableRoomDirections(const ID& roomId) {
    std::vector<std::string> availableDirections;

    if (!doesRoomExist(roomId)
        || _roomIdToNeighbours.count(roomId) == 0) {
        return availableDirections;
    }

    const Neighbours& neighbours = _roomIdToNeighbours.at(roomId);

    //add directions of all neighbours
    for (auto& neighbour : neighbours) {
        Direction direction = neighbour.direction;

        //there's no easy way to convert enums to strings
        //iterate _directions map to find matching direction enum value and return the key
        auto it = std::find_if(_directions.begin(), _directions.end(),
                               [&](const std::pair<string, Direction>& pair) { return pair.second == direction; });

        availableDirections.emplace_back(it->first);
    }

    return availableDirections;
}

const bool RoomConnectionService::isValidDirectionString(const std::string directionString) {
    return _directions.count(directionString) != 0;
}

const bool RoomConnectionService::doesRoomExist(const ID& roomId) {
    return _roomIdToRoom.count(roomId) != 0;
}

/*
 * PRIVATE
 */

const models::Room* RoomConnectionService::findRoom(const ID& roomId) {
    if (!doesRoomExist(roomId)) {
        return nullptr;
    }

    return &(_roomIdToRoom.at(roomId));
}

void RoomConnectionService::buildDirectionsMap() {
    _directions["north"] = Direction::NORTH;
    _directions["south"] = Direction::SOUTH;
    _directions["east"] = Direction::EAST;
    _directions["west"] = Direction::WEST;
}


void RoomConnectionService::loadFromStorage() {
    // jsonIdToUuid is mapping the JSON room IDs to a UUID.
    // It's needed when building up the neighbours since some neighbours might not have been assigned a UUID yet.
    std::unordered_map<int, ID> jsonIdToUuid;
    std::vector<CusJson::Room> jsonRooms = _dataStorageService.getJsonArea()._rooms;

    for (const CusJson::Room& jsonRoom : jsonRooms) {
        Room room{jsonRoom};
        const ID& roomId = room.getId();

        jsonIdToUuid.emplace(jsonRoom._id, roomId);
        _roomIdToRoom.emplace(roomId, room);
    }

    for (const CusJson::Room& jsonRoom : jsonRooms) {
        Neighbours neighbours;

        buildNeighbours(jsonIdToUuid, jsonRoom, neighbours);

        _roomIdToNeighbours.try_emplace(jsonIdToUuid[jsonRoom._id], neighbours);
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
