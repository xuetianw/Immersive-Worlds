//
// Created by user on 3/1/19.
//

#ifndef WEBSOCKETNETWORKING_EQUIPNPCACTION_H
#define WEBSOCKETNETWORKING_EQUIPNPCACTION_H

#include "NPCAction.h"
namespace CusJson {
    class EquipNPCAction: public NPCAction {
    public:
        int _objectIdToGive;
        int _equipSlotIndex;
        void addObject(NPCJsonWrapper& npcJsonWrapper);
    };
}
#endif //WEBSOCKETNETWORKING_EQUIPNPCACTION_H
