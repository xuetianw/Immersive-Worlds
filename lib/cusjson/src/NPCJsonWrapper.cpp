//
// Created by user on 3/1/19.
//

#include "NPCJsonWrapper.h"

using namespace CusJson;

void NPCJsonWrapper::addObject(int objectId) {
    _givenObject.push_back(objectId);
}

void NPCJsonWrapper::addEquipment(struct Equipment equipment) {
    _givenEquipment.push_back(equipment);
}

NPCJsonWrapper::NPCJsonWrapper(int _NPCId, int _limit, int _roomId) : _NPCId(_NPCId), _limit(_limit),
                                                                      _roomId(_roomId) {}
