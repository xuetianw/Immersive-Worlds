//
// Created by user on 2/11/19.
//

#ifndef WEBSOCKETNETWORKING_DATASTORAGESERVICE_H
#define WEBSOCKETNETWORKING_DATASTORAGESERVICE_H

#include "CusJson.h"

class DataStorageService {
private:
    CusJson::Area _jsonArea;
    CusJson::MiniGameList _jsonMiniGameList;

public:
    DataStorageService() {
        json solaceJson = getTestingArea();
        _jsonArea = solaceJson.get<CusJson::Area>();

        json minigameJson = getTestingMiniGameList();
        _jsonMiniGameList = minigameJson.get<CusJson::MiniGameList>();
    }

    const CusJson::Area& getJsonArea() const;

    const CusJson::MiniGameList& getMiniGameList() const;

    void setJsonArea(const CusJson::Area& jsonArea);

private:
    json getTestingArea();

    json getTestingMiniGameList();
};

#endif //WEBSOCKETNETWORKING_DATASTORAGESERVICE_H
