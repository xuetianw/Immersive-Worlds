//
// Created by user on 3/4/19.
//

#ifndef WEBSOCKETNETWORKING_DOORSTATEJSONWRAPPER_H
#define WEBSOCKETNETWORKING_DOORSTATEJSONWRAPPER_H

#include <string>

namespace CusJson {
    /**
     * Encapsulates the json structure for RESETS when the action field is door
     * See doc/JsonStructureDocument for more details
     */
    class DoorStateJsonWrapper {
    public:
        int _id; // index of the door. North = 0, East = 1, South = 2, West = 3, Up = 4, Down = 5
        int _roomId; // jsonId of the room
        std::string _state; // From the json, it's either "closed" or "locked"

        DoorStateJsonWrapper(int id, int roomId, const std::string& state);
    };
}
#endif //WEBSOCKETNETWORKING_DOORSTATEJSONWRAPPER_H
