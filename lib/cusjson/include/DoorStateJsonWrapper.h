//
// Created by user on 3/4/19.
//

#ifndef WEBSOCKETNETWORKING_DOORSTATEJSONWRAPPER_H
#define WEBSOCKETNETWORKING_DOORSTATEJSONWRAPPER_H

#include <string>

namespace CusJson {
    class DoorStateJsonWrapper {
    public:
        int _id;
        int _roomId;
        std::string state;

        DoorStateJsonWrapper(int id, int _roomId, const std::string& state);
    };
}
#endif //WEBSOCKETNETWORKING_DOORSTATEJSONWRAPPER_H
