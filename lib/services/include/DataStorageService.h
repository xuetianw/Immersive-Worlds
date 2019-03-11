//
// Created by user on 2/11/19.
//

#ifndef WEBSOCKETNETWORKING_DATASTORAGESERVICE_H
#define WEBSOCKETNETWORKING_DATASTORAGESERVICE_H

#include "SingleItem.h"
#include "CusJson.h"
#include <iostream>

class DataStorageService {
private:
    CusJson::Area _jsonArea;
    std::unordered_map<int, SingleItem> _objectMap;

public:
    DataStorageService() {
        json solaceJson = getTestingArea();
        _jsonArea = solaceJson.get<CusJson::Area>();
        _objectMap = configObjectMap(_jsonArea);
    }

    const CusJson::Area& getJsonArea() const;

    void setJsonArea(const CusJson::Area& jsonArea);
    std::unordered_map<int, SingleItem> getObjectsFromJson();
    SingleItem spawnObjectCopy(int objectId);

private:
    std::unordered_map<int, SingleItem> configObjectMap(const CusJson::Area& jsonArea);
    json getTestingArea();
};

#endif //WEBSOCKETNETWORKING_DATASTORAGESERVICE_H
