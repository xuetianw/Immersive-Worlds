//
// Created by user on 2/11/19.
//

#ifndef WEBSOCKETNETWORKING_DATASTORAGE_H
#define WEBSOCKETNETWORKING_DATASTORAGE_H

#include "CusJson.h"

class DataStorage {
private:
    CusJson::Area _jsonArea;

public:
    DataStorage() {
        json solaceJson = getTestingArea();
        _jsonArea = solaceJson.get<CusJson::Area>();
    }

    const CusJson::Area& getJsonArea() const;

    void setJsonArea(const CusJson::Area& jsonArea);

private:
    json getTestingArea();
};

#endif //WEBSOCKETNETWORKING_DATASTORAGE_H
