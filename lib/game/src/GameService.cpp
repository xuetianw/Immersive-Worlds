//
// Created by user on 2/8/19.
//

#include <GameService.h>
#include <Server.h>

#include "GameService.h"

bool GameService::moveUser(const networking::Connection &connection, const std::string keywordString) {
  auto userId = connection.id;
  auto roomId = _connectionIdToRoomId.at((int)userId);
  auto connectedRoomList = _roomIdToRoomConnectionsList.at(roomId.getId());
  auto connectedRoom = std::find_if(connectedRoomList.begin(), connectedRoomList.end(), [keywordString](const channel::RoomConnection &roomConnection) -> bool {
    return roomConnection.getKeyword() == keywordString;
  });
  if (connectedRoom != connectedRoomList.end()) {
    _connectionIdToRoomId.find((int) userId)->second =connectedRoom.base()->getTo();
  }
  return connectedRoom != connectedRoomList.end();
}

bool GameService::userYell(const networking::Connection &connection, const std::string messageString) {
  return false;
}

string GameService::getCurrentRoomName(const networking::Connection &connection) {
  auto userId = connection.id;
  auto roomId = _connectionIdToRoomId.at((int)userId);
  auto room = _roomIdToRoom.at(roomId.getId());
  return room.getName();
}

bool GameService::placeUserInStartRoom(const networking::Connection &connection) {
  auto userId = connection.id;
  _connectionIdToRoomId.emplace((int)userId, channel::RoomId(10500)); // DEBUG starting room is in Lexia's shop
  return true;
}

bool GameService::placeUserInStartRoomDebug(const networking::Connection &connection, int id) {
  auto userId = connection.id;
  _connectionIdToRoomId.emplace((int)userId, channel::RoomId(id));
  return true;
}

void GameService::loadFromStorage() {
    for (const channel::Room &room : _dataStorage.getRooms()) {
        _roomIdToRoom.emplace(room.getId(), room);
    }
    for (const std::pair<int, std::vector<channel::RoomConnection>> &roomConnection : _dataStorage.getRoomConnectionsPairs()) {
        _roomIdToRoomConnectionsList.insert(roomConnection); //
    }
}

GameService::GameService() {
  loadFromStorage();
}
