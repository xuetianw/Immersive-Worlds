//
// Created by user on 3/1/19.
//

#include "GiveNPCAction.h"

using namespace CusJson;

void GiveNPCAction::addObject(NPCJsonWrapper& npcJsonWrapper) {
    npcJsonWrapper.addObject(this->_objectIdToGive);
}