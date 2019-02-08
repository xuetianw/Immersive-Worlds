//
// Created by asim on 07/02/19.
//
#include "GameController.h"

Message GameController::yell(Command* cmd, const Message& message) {
    return cmd->execute(gameService, message);
}
