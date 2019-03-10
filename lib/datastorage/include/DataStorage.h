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
    CusJson::Area jsonArea;
    CusJson::MiniGameList jsonMiniGameList;
public:
    DataStorage();

    const CusJson::Area& getJsonArea() const;

    const CusJson::MiniGameList& getMiniGameList() const;

    void setJsonArea(const CusJson::Area& jsonArea);

private:
    json getTestingArea();

    json getTestingMiniGameList();


};


#endif //WEBSOCKETNETWORKING_DATASTORAGE_H
