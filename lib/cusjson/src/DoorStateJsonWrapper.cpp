//
// Created by user on 3/4/19.
//

#include "DoorStateJsonWrapper.h"

CusJson::DoorStateJsonWrapper::DoorStateJsonWrapper(int id, int _roomId, const std::string& state)
        : _id(id), _roomId(_roomId), state(state) {}
