//
// Created by user on 2/8/19.
//

#include "Server.h"
#include "GameService.h"

using models::RoomConnection;

bool GameService::moveUser(const User& user, const std::string& keywordString) {
    auto roomId = _connectionToRoomId.at(user.getConnection());
    auto connectedRoomList = _roomIdToRoomConnectionsList.at(roomId);
    auto connectedRoom = std::find_if(connectedRoomList.begin(), connectedRoomList.end(), [keywordString](const models::RoomConnection &roomConnection) -> bool {
        return roomConnection.getUserInputDirKey() == keywordString;
    });
    if (connectedRoom != connectedRoomList.end()) {
        _connectionToRoomId.find(user.getConnection())->second = connectedRoom.base()->getTo();
    }
    return connectedRoom != connectedRoomList.end();
}

bool GameService::userYell(const User& user, const std::string& messageString) {
    return false;
}

string GameService::getCurrentRoomName(const Connection& connection) {
    const ID& roomId = _connectionToRoomId[connection];
    auto roomIter = _roomIdToRoom.find(roomId);
    return roomIter != _roomIdToRoom.end() ? roomIter->second.getName() : "";
}

bool GameService::spawnUserInRoomOnLogin(const Connection& connection) {
    const Room* userRoom = getRoomByName("Lexie's Scuba Shop");
    return userRoom ? spawnUserInRoom(connection, userRoom->getId()) : false;
}

bool GameService::spawnUserInRoom(const Connection& connection, const ID& id) {
    auto [it, inserted] = _connectionToRoomId.emplace(connection, id);
    return it != _connectionToRoomId.end() || inserted;
}

const Room* GameService::getRoomByName(const string& roomName) const {
    for(const auto& room : _roomIdToRoom) {
        if(room.second.getName() == roomName) {
            return &room.second;
        }
    }

    return nullptr;
}

const Room& GameService::getUserRoom(const Connection& connection) {
    // This is just a placeholder.
    // TODO: Implement the logic appropriately
    return std::move(Room());
}

void GameService::loadFromStorage() {
    // load data from cusJson
    for (const CusJson::Room& room : _dataStorage.getJsonArea()._rooms) {
        // Create a new models::Room from CusJson::Room
        Room newRoom {room};
        const ID& newRoomId = newRoom.getId();
        _roomIdToRoom.emplace(newRoomId, newRoom);

        std::vector<RoomConnection> roomConnectionVector;
        for (const CusJson::JsonDoor& jsonDoor : room._jsonDoors) {
            roomConnectionVector.emplace_back(ID(jsonDoor._to), ID(room._id), jsonDoor._dir);
        }

        _roomIdToRoomConnectionsList.emplace(newRoomId, roomConnectionVector);
    }
    auto containerConfiguration = _dataStorage.getJsonArea()._containerWrappers;
    for (auto container : containerConfiguration) {
        auto roomQuery = _roomIdToRoom.find(ID(container._roomId));
        if (roomQuery != _roomIdToRoom.end()) {
            auto spawnedContainer = _dataStorage.spawnObjectCopy(container._objectId);
            for (auto containedItemId : container._containedObjectIds) {
                spawnedContainer.getItemsInContainer().push_back(_dataStorage.spawnObjectCopy(containedItemId));
            }
            roomQuery->second.addObject(spawnedContainer.getId(), spawnedContainer);
        }
    }
}
