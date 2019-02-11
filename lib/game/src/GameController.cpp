//
// Created by asim on 07/02/19.
//
#include <GameController.h>

#include "GameController.h"

networking::Message GameController::yell(Command *cmd, const networking::Message &message) {
    return cmd->execute(gameService, message);
}

networking::Message GameController::attack(Command *cmd, const networking::Message &message) {
    return cmd->execute(gameService, message);
}

networking::Message GameController::move(Command *cmd, const networking::Message &message) {
    return cmd->execute(gameService, message);
}

void GameController::spawnUser(const networking::Connection &connection) {
    gameService.placeUserInStartRoom(connection);
}

void GameController::spawnUser(const networking::Connection &connection, int debugRoomId) {
    gameService.placeUserInStartRoomDebug(connection, debugRoomId);
}
