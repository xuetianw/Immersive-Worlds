//
// Created by user on 2/11/19.
//

#ifndef WEBSOCKETNETWORKING_DATASTORAGE_H
#define WEBSOCKETNETWORKING_DATASTORAGE_H

#include "SingleItem.h"
#include "CusJson.h"
#include <iostream>

class DataStorage {
private:
    CusJson::Area _jsonArea;
    std::unordered_map<int, SingleItem> _objectMap;

public:
    DataStorage();
    const CusJson::Area& getJsonArea() const;

    void setJsonArea(const CusJson::Area& jsonArea);
    std::unordered_map<int, SingleItem> getObjectsFromJson();
    SingleItem spawnObjectCopy(int objectId);

private:
    std::unordered_map<int, SingleItem> configObjectMap(const CusJson::Area& jsonArea);
    json getTestingArea();
};

#endif //WEBSOCKETNETWORKING_DATASTORAGE_H
