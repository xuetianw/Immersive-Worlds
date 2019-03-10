//
// Created by user on 2/8/19.
//

#include <GameService.h>
#include <Server.h>

#include "GameService.h"
#include <iostream>

bool GameService::moveUser(const networking::Connection& connection, const std::string keywordString) {
    auto roomId = _connectionToRoomId.at(connection);
    auto connectedRoomList = _roomIdToRoomConnectionsList.at(roomId.getId());
    auto connectedRoom = std::find_if(connectedRoomList.begin(), connectedRoomList.end(),
                                      [keywordString](const models::RoomConnection& roomConnection) -> bool {
                                          return roomConnection.getUserInputDirKey() == keywordString;
                                      });
    if (connectedRoom != connectedRoomList.end()) {
        _connectionToRoomId.find(connection)->second = connectedRoom.base()->getTo();
    }
    return connectedRoom != connectedRoomList.end();
}

bool GameService::userYell(const networking::Connection& connection, const std::string messageString) {
    return false;
}

string GameService::getCurrentRoomName(const networking::Connection& connection) {
    auto roomId = _connectionToRoomId.at(connection);
    auto room = _roomIdToRoom.at(roomId.getId());
    return room.getName();
}

bool GameService::spawnUserInStartRoom(const networking::Connection& connection) {
    auto[it, inserted] = _connectionToRoomId.insert_or_assign(connection, models::RoomId(
            10500)); // DEBUG starting room is in Lexia's shop
    return it != _connectionToRoomId.end() || !inserted;
}

bool GameService::spawnUserInRoom(const networking::Connection& connection, int id) {
    auto[it, inserted] = _connectionToRoomId.insert_or_assign(connection, models::RoomId(id));
    return it != _connectionToRoomId.end() || !inserted;
}


void GameService::loadFromStorage() {
    // load _roomIdToRoom
    for (const CusJson::Room& room:_dataStorage.getJsonArea()._rooms) {
        _roomIdToRoom.emplace(room._id, models::Room(room));
    }

    // load minigame
    for (const CusJson::MiniGame& minigame : _dataStorage.getMiniGameList()._minigames) {
        _roomIdToMiniGameConnectionsList.emplace(minigame._roomId, models::MiniGame(minigame));
    }

    // load _roomIdToRoomConnectionsList
    using RoomIdConnectionsPair = std::pair<int, std::vector<models::RoomConnection>>;
    std::vector<RoomIdConnectionsPair> roomIdToRoomConnectionListPairList;
    for (const CusJson::Room& room:_dataStorage.getJsonArea()._rooms) {
        std::vector<models::RoomConnection> roomConnectionVector;
        for (const CusJson::JsonDoor& jsonDoor : room._jsonDoors) {
            roomConnectionVector.emplace_back(models::RoomId(jsonDoor._to), models::RoomId(room._id), jsonDoor._dir);
        }
        roomIdToRoomConnectionListPairList.emplace_back(room._id, roomConnectionVector);
    }

    for (const auto& roomConnection: roomIdToRoomConnectionListPairList) {
        _roomIdToRoomConnectionsList.insert(roomConnection);
    }
}

GameService::GameService() {
    loadFromStorage();
}

bool GameService::roomHaveMiniGame(const networking::Connection& connection) {
    auto roomId = _connectionToRoomId.at(connection);
    auto found = _roomIdToMiniGameConnectionsList.find(roomId.getId());

    return found != _roomIdToMiniGameConnectionsList.end();
}

models::MiniGame GameService::getMiniGame(const networking::Connection& connection, const std::string keywordString) {
    auto roomId = _connectionToRoomId.at(connection);
    auto found = _roomIdToMiniGameConnectionsList.find(roomId.getId());

    return found->second;
}

bool GameService::verifyAnswer(const networking::Connection& connection, const int input) {
    auto roomId = _connectionToRoomId.at(connection);
    auto result = _roomIdToMiniGameConnectionsList.find(roomId.getId());
    auto correctAnswer = result->second.checkAnswer(input);

    return correctAnswer;
}
