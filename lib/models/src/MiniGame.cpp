//
// Created by Jan Ycasas on 2019-02-06.
//

#include "MiniGame.h"

using channel::MiniGame;

bool MiniGame::execute() {
    return true;
}

void MiniGame::addUser(int id) {
    _users.push_back(id);
}