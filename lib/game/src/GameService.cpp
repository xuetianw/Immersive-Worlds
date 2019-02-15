//
// Created by user on 2/8/19.
//

#include <GameService.h>
#include <Server.h>

#include "GameService.h"

bool GameService::moveUser(const networking::Connection &connection, const std::string keywordString) {
  auto roomId = _connectionToRoomId.at(connection);
  auto connectedRoomList = _roomIdToRoomConnectionsList.at(roomId.getId());
  auto connectedRoom = std::find_if(connectedRoomList.begin(), connectedRoomList.end(), [keywordString](const channel::RoomConnection &roomConnection) -> bool {
    return roomConnection.getUserInputDirKey() == keywordString;
  });
  if (connectedRoom != connectedRoomList.end()) {
    _connectionToRoomId.find(connection)->second = connectedRoom.base()->getTo();
  }
  return connectedRoom != connectedRoomList.end();
}

bool GameService::userYell(const networking::Connection &connection, const std::string messageString) {
  return false;
}

string GameService::getCurrentRoomName(const networking::Connection &connection) {
  auto roomId = _connectionToRoomId.at(connection);
  auto room = _roomIdToRoom.at(roomId.getId());
  return room.getName();
}

bool GameService::spawnUserInStartRoom(const networking::Connection &connection) {
  _connectionToRoomId.emplace(connection, channel::RoomId(10500)); // DEBUG starting room is in Lexia's shop
  return true;
}

bool GameService::spawnUserInRoom(const networking::Connection &connection, int id) {
  _connectionToRoomId.emplace(connection, channel::RoomId(id));
  return true;
}

void GameService::loadFromStorage() {
    for (const channel::Room &room : _dataStorage.getRooms()) {
        _roomIdToRoom.emplace(room.getId(), room);
    }
    for (const std::pair<int, std::vector<channel::RoomConnection>> &roomConnection : _dataStorage.getRoomConnectionsPairs()) {
        _roomIdToRoomConnectionsList.insert(roomConnection);
    }
}

GameService::GameService() {
  loadFromStorage();
}
