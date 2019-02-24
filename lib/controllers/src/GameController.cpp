//
// Created by asim on 07/02/19.
//
#include <GameController.h>

pair<bool, Message> GameController::respondToMessage(const Message& message){

}

networking::Message GameController::move(const networking::Message &message) {

    networking::Message newMessage = networking::Message();
    newMessage.connection = message.connection;
    std::string beforeMoveRoomName = _gameService.getCurrentRoomName(message.connection);
    _gameService.moveUser(message.connection, message.text);
    std::string afterMoveRoomName = _gameService.getCurrentRoomName(message.connection);
    std::string output = "command /move " + message.text + " called\n" + "before move: " + beforeMoveRoomName + "\nafter move: " + afterMoveRoomName;
    newMessage.text = output;
    return newMessage;
}

Message GameController::spawnUserInStartRoom(const networking::Connection &connection) {
    if (_gameService.spawnUserInStartRoom(connection)) {
        return Message{connection, ROOM_SPAWN_SUCCESS_MESSAGE};
    } else {
        return Message{connection, ROOM_SPAWN_FAIL_MESSAGE};
    }
}
void GameController::spawnUserInRoom(const networking::Connection &connection, int debugRoomId) {
    _gameService.spawnUserInRoom(connection, debugRoomId);
}

GameController::GameController(GameService gameService) : _gameService(gameService){

}

void GameController::addUser(const networking::Connection &connection) {

}
