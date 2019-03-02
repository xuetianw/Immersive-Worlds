//
// Created by user on 3/1/19.
//
#include "EquipNPCAction.h"

using namespace CusJson;

void EquipNPCAction::addObject(CusJson::NPCJsonWrapper &npcJsonWrapper) {
    npcJsonWrapper.addEquipment({_objectIdToGive, _equipSlotIndex});
}