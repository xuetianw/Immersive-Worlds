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
