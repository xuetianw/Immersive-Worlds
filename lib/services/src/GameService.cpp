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

ID GameService::getCurrentRoomId(const Connection& connection) {
    // TODO: think of a better way to do this
    const ID& roomId = _connectionToRoomId[connection];
    auto roomIter = _roomIdToRoom.find(roomId);
    return roomIter->second.getId();
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

bool GameService::roomHaveMiniGame(const User& user) {
    auto roomName = getCurrentRoomName(user.getConnection());
    return roomName != "";
}

models::MiniGame GameService::getMiniGame(const User& user, const std::string keywordString) {
    //auto roomId = _connectionToRoomId.at(user.getConnection());
    auto roomId = getCurrentRoomName(user.getConnection());
    auto found = _roomIdToMiniGameConnectionsList.find(roomId);

    return found->second;
}

bool GameService::verifyAnswer(const User& user, const int input) {
    //auto roomId = _connectionToRoomId.at(user.getConnection());
    auto roomId = getCurrentRoomName(user.getConnection());
    auto result = _roomIdToMiniGameConnectionsList.find(roomId);
    auto correctAnswer = result->second.checkAnswer(input);
    result->second.nextRound();

    return correctAnswer;
}

const Room& GameService::getUserRoom(const Connection& connection) {
    // This is just a placeholder.
    // TODO: Implement the logic appropriately
    return std::move(Room());
}
