//
// Created by user on 2/11/19.
//

#ifndef WEBSOCKETNETWORKING_DATASTORAGESERVICE_H
#define WEBSOCKETNETWORKING_DATASTORAGESERVICE_H

#include "CusJson.h"

class DataStorageService {
private:
    CusJson::Area _jsonArea;

public:
    DataStorageService() {
        json solaceJson = getTestingArea();
        _jsonArea = solaceJson.get<CusJson::Area>();
    }

    const CusJson::Area& getJsonArea() const;

    void setJsonArea(const CusJson::Area& jsonArea);

private:
    json getTestingArea();
};

#endif //WEBSOCKETNETWORKING_DATASTORAGESERVICE_H
