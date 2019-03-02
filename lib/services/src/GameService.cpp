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
  auto roomId = _connectionToRoomId.at(connection);
  auto room = _roomIdToRoom.at(roomId.getId());
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

channel::MiniGame GameService::getMiniGame(const networking::Connection &connection, const std::string keywordString) {
  // TODO: CHECK MINIGAME MAP IF MINIGAME EXISTS, CHECK IF USER LOGGED IN
  channel::MiniGame miniGame = channel::MiniGame();
  miniGame.addQuestion("THIS IS THE QUESTION 1");
  miniGame.addAnswer("Correct Answer");
  miniGame.addAnswer("Wrong Answer");
  miniGame.addCorrectAnswer(0);

  auto roomId = _connectionToRoomId.at(connection);
  std::pair<int, channel::MiniGame> pair (roomId.getId(), miniGame);
  _roomIdToMiniGameConnectionsList.emplace(pair);

  return miniGame;
}

bool GameService::verifyAnswer(const networking::Connection &connection, const int input) { 
  auto roomId = _connectionToRoomId.at(connection);

  auto got = _roomIdToMiniGameConnectionsList.find(roomId.getId());

  auto found = (got != _roomIdToMiniGameConnectionsList.end());
  auto correctAnswer = got->second.checkAnswer(input);

  return found && correctAnswer;
}
