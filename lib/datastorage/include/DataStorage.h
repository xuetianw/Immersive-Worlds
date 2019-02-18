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
    std::vector<models::Room> getRooms();

    /**
     * @return a list of pairs where the int is the roomId, and the second is a list of RoomConnections for that roomId
     */
    std::vector<std::pair<int, std::vector<models::RoomConnection>>> getRoomConnectionsPairs();
};


#endif //WEBSOCKETNETWORKING_DATASTORAGE_H
