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
public:
    const CusJson::Area &get_jsonArea() const;

    void set_jsonArea(const CusJson::Area &_jsonArea);

private:
    json getTestingArea();

public:
    DataStorage();
};


#endif //WEBSOCKETNETWORKING_DATASTORAGE_H
