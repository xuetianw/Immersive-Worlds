//
// Created by user on 2/8/19.
//

#include <GameService.h>
#include <Server.h>

#include "GameService.h"

bool GameService::moveUser(const networking::Connection &connection, const std::string keywordString) {
  auto roomId = _connectionToRoomId.at(connection);
  auto connectedRoomList = _roomIdToRoomConnectionsList.at(roomId.getId());
  auto connectedRoom = std::find_if(connectedRoomList.begin(), connectedRoomList.end(), [keywordString](const models::RoomConnection &roomConnection) -> bool {
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
  auto room = getUserRoom(connection);
  return room.getName();
}

bool GameService::spawnUserInStartRoom(const networking::Connection &connection) {
  _connectionToRoomId.emplace(connection, models::RoomId(10500)); // DEBUG starting room is in Lexia's shop
  return true;
}

bool GameService::spawnUserInRoom(const networking::Connection &connection, int id) {
  _connectionToRoomId.emplace(connection, models::RoomId(id));
  return true;
}


void GameService::loadFromStorage() {
  // load _roomIdToRoom
  for (const CusJson::Room &room:_dataStorage.getJsonArea()._rooms) {
    _roomIdToRoom.emplace(room._id, models::Room(room));
  }


  // load _roomIdToRoomConnectionsList
  using RoomIdConnectionsPair = std::pair<int, std::vector<models::RoomConnection>>;
  std::vector<RoomIdConnectionsPair> roomIdToRoomConnectionListPairList;
  for (const CusJson::Room &room:_dataStorage.getJsonArea()._rooms) {
      std::vector<models::RoomConnection> roomConnectionVector;
      for (const CusJson::JsonDoor& jsonDoor : room._jsonDoors) {
        roomConnectionVector.emplace_back(models::RoomId(jsonDoor._to), models::RoomId(room._id), jsonDoor._dir);
      }
      roomIdToRoomConnectionListPairList.emplace_back(room._id, roomConnectionVector);
    }

    for (const auto &roomConnection: roomIdToRoomConnectionListPairList) {
      _roomIdToRoomConnectionsList.insert(roomConnection);
    }
}

GameService::GameService() {
  loadFromStorage();
}

models::Room GameService::getUserRoom(const networking::Connection &connection) {
  auto roomId = _connectionToRoomId.at(connection);
  return _roomIdToRoom.at(roomId.getId());
}
