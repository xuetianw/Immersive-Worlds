//
// Created by user on 3/1/19.
//

#ifndef WEBSOCKETNETWORKING_GIVENPCACTION_H
#define WEBSOCKETNETWORKING_GIVENPCACTION_H

#include "NPCAction.h"
namespace CusJson {
    class GiveNPCAction: public NPCAction {
    public:
        int _objectIdToGive;
        void addObject(NPCJsonWrapper& npcJsonWrapper);
    };
}
#endif //WEBSOCKETNETWORKING_GIVENPCACTION_H
