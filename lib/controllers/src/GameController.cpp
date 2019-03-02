//
// Created by asim on 07/02/19.
//

#include "GameController.h"
#include "Message.h"

pair<bool, Message> GameController::respondToMessage(Message& message){

}

Message GameController::move(const Message& message) {
    Message newMessage = Message(message.user);
    if (!checkIsDirectionMessage(message)) {
        newMessage.text = WRONG_DIRECTION_MESSAGE;
        return newMessage;
    }
    std::string beforeMoveRoomName = _gameService.getCurrentRoomName(message.user.getConnection());
    if (_gameService.moveUser(message.user, message.text)) {
        std::string afterMoveRoomName = _gameService.getCurrentRoomName(message.user.getConnection());
        std::string output = "command /move " + message.text + " called\n" + "before move: " + beforeMoveRoomName + "\nafter move: " + afterMoveRoomName;
        newMessage.text = output;
    } else {
        newMessage.text = "user did not move";
    }

    return newMessage;
}

Message GameController::spawnUserInStartRoom(User& user) {
    if (_gameService.spawnUserInStartRoom(user.getConnection())) {
        return Message{user, INITIAL_ROOM_START_MESSAGE};
    } else {
        return Message{user, ROOM_SPAWN_FAIL_MESSAGE};
    }
}

void GameController::spawnUserInRoom(User& user, int debugRoomId) {
    _gameService.spawnUserInRoom(user.getConnection(), debugRoomId);
}

GameController::GameController(GameService &gameService) : _gameService(gameService){

}

void GameController::addUser(const networking::Connection& connection) {

}

bool GameController::checkIsDirectionMessage(const Message& message) {
    std::vector<std::string>::iterator it;
    it = std::find (directions.begin(), directions.end(), message.text);
    return it != directions.end();
}

Message GameController::outputCurrentLocationInfo(Message& message) {
    networking::Connection& currentConnection = message.user.getConnection();
    string currentRoom = _gameService.getCurrentRoomName(currentConnection);
    string responseText = USER_CURRENTLY_LOCATED_MESSAGE + currentRoom;

    Message response{message.user, responseText};

    return response;
}