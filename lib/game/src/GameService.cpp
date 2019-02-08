//
// Created by user on 2/8/19.
//

#include <GameService.h>

#include "GameService.h"

const vector<channel::Area> &GameService::get_areas() const {
    return _areas;
}

void GameService::set_areas(const vector<channel::Area> &_areas) {
   this->_areas = std::move(_areas);
}
