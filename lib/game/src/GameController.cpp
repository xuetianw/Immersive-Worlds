//
// Created by asim on 07/02/19.
//
#include "GameController.h"

networking::Message GameController::yell(Command* cmd) {
    return cmd->execute(gameService);
}
