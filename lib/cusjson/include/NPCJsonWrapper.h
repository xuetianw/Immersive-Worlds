//
// Created by user on 3/1/19.
//

#ifndef WEBSOCKETNETWORKING_NPCJSONWRAPPER_H
#define WEBSOCKETNETWORKING_NPCJSONWRAPPER_H

#include <vector>

namespace CusJson {
    struct Equipment {
        int _equidId;
        int _objectId;
    };

    class NPCJsonWrapper {
    public:
        int _NPCId;
        int _limit;
        int _roomId;
        std::vector<int> _givenObject;
        std::vector<struct Equipment> _givenEquipment;

        NPCJsonWrapper(int _NPCId, int _limit, int _roomId);

        void addObject(int objectId);

        void addEquipment(struct Equipment equipment);
    };
}


#endif //WEBSOCKETNETWORKING_NPCJSONWRAPPER_H
