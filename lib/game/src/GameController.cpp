//
// Created by asim on 07/02/19.
//
#include "GameController.h"

networking::Message GameController::yell(Command *cmd, const networking::Message &message) {
    return cmd->execute(_gameService, message);
}

networking::Message GameController::attack(Command *cmd, const networking::Message &message) {
    return cmd->execute(_gameService, message);
}

networking::Message GameController::move(Command *cmd, const networking::Message &message) {
    return cmd->execute(_gameService, message);
}

void GameController::spawnUserInStartRoom(const networking::Connection &connection) {
    _gameService.spawnUserInStartRoom(connection);
}

void GameController::spawnUserInRoom(const networking::Connection &connection, int debugRoomId) {
    _gameService.spawnUserInRoom(connection, debugRoomId);
}

GameController::GameController(GameService gameService) : _gameService(gameService){

}
