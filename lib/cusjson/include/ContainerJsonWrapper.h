//
// Created by user on 3/4/19.
//

#ifndef WEBSOCKETNETWORKING_CONTAINERJSONWRAPPER_H
#define WEBSOCKETNETWORKING_CONTAINERJSONWRAPPER_H

#include <vector>
namespace CusJson {
    class ContainerJsonWrapper {
    public:
        int _objectId;
        int _roomId;
        std::vector<int> _containedObjectIds;

        ContainerJsonWrapper(int _objectId, int _roomId);
        void addObject(int objectId);
    };
}


#endif //WEBSOCKETNETWORKING_CONTAINERJSONWRAPPER_H
