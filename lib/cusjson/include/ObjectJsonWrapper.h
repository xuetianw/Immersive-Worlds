//
// Created by user on 3/4/19.
//

#ifndef WEBSOCKETNETWORKING_CONTAINERJSONWRAPPER_H
#define WEBSOCKETNETWORKING_CONTAINERJSONWRAPPER_H

#include <vector>

namespace CusJson {
    class ObjectJsonWrapper {
    public:
        int _objectJsonId;
        int _roomJsonId;
        std::vector<int> _containedObjectJsonIds;

        ObjectJsonWrapper(int _objectId, int _roomId);

        void addObject(int objectId);
    };
}


#endif //WEBSOCKETNETWORKING_CONTAINERJSONWRAPPER_H
