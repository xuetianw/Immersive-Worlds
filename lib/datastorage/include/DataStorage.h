//
// Created by user on 2/11/19.
//

#ifndef WEBSOCKETNETWORKING_DATASTORAGE_H
#define WEBSOCKETNETWORKING_DATASTORAGE_H


#include <RoomConnection.h>
#include "CusJson.h"
#include "Room.h"

class DataStorage {
private:
    CusJson::Area _jsonArea;
    json getTestingArea();

public:
    DataStorage();
    std::vector<channel::Room> getRooms();

    /**
     * parses through the json and per each room, creates a vector of RoomConnections based on the door
     * @return a vector of vectors of Room connections grouped by _from parameter of RoomConnection
     */
    std::vector<std::vector<channel::RoomConnection>> getRoomConnection();
};


#endif //WEBSOCKETNETWORKING_DATASTORAGE_H
