//
// Created by user on 3/1/19.
//

#ifndef WEBSOCKETNETWORKING_NPCACTION_H
#define WEBSOCKETNETWORKING_NPCACTION_H

#include "NPCJsonWrapper.h"

namespace CusJson {
    class NPCAction {
        virtual void addObject(NPCJsonWrapper& npcJsonWrapper) = 0;
    };
}
#endif //WEBSOCKETNETWORKING_NPCACTION_H
