//
// Created by user on 2/11/19.
//

#include "DataStorageService.h"
#include <iostream>
#include <DataStorageService.h>


using CusJson::Area;

json DataStorageService::getTestingMiniGameList() {
    json j = R"(
  {
    "MINIGAMES" : [
        {
          "id" : 1,
          "roomId" : 10500,
          "roomName" : "Lexie's Scuba Shop",
          "type" : "multiple_choice",
          "questions" : [
                          "Which spelling is correct?",
                          "Which spelling is correct?"
                        ],
          "answers" : [
                        [
                          "RRRR",
                          "CAT",
                          "TTTT"
                        ],
                        [
                          "TTTT",
                          "WWW",
                          "HELLO"
                        ]
                      ],
          "correctanswers" :  [
                                1,
                                2
                              ]
        },
        {
          "id" : 2,
          "roomId" : 10608,
          "roomName" : "Marketplace.",
          "type" : "multiple_choice",
          "questions" : [
                        "Which spelling is correct?"
                        ],
          "answers" : [
                        [
                          "RRRR",
                          "DOG",
                          "TTTT"
                        ]
                      ],
          "correctanswers" : [
                              1
                            ]
        }
    ]
  }
)"_json;
    return j;
}

const Area& DataStorageService::getJsonArea() const {
    return _jsonArea;
}

void DataStorageService::configRoomsAndJsonIdMap(const CusJson::Area& jsonArea) {
    for (const CusJson::Room& jsonRoom : jsonArea._rooms) {
        models::Room room{jsonRoom};
        const ID& roomId = room.getId();

        _jsonRoomIdToUuid.emplace(jsonRoom._id, roomId);
        _roomIdToRoom.emplace(roomId, room);
    }
}

void DataStorageService::configObjectMap(const CusJson::Area& jsonArea, std::unordered_map<int, SingleItem>& jsonIdToItemMap) {
    for (CusJson::Object jsonObject : jsonArea._objects) {
        std::vector<string> keywords = jsonObject.keywords;
        std::vector<string> longDesc = jsonObject.longdesc;
        for (CusJson::ExtDesc extDesc : jsonObject._jsonExtDesc) {
            keywords.insert(keywords.begin(), extDesc._keywords.begin(), extDesc._keywords.end());
            longDesc.insert(longDesc.begin(), extDesc._desc.begin(), extDesc._desc.end());
        }
        auto item = SingleItem(ID(jsonObject.id), keywords, jsonObject.shortdesc, longDesc, "");
        jsonIdToItemMap.insert({jsonObject.id, item});
    }
}

SingleItem DataStorageService::spawnObjectCopy(int jsonId) {
    auto objectQueury = _objectMap.find(jsonId);
    if (objectQueury != _objectMap.end()) {
        return SingleItem(objectQueury->second);
    } else {
        std::cerr << "spawnObjectCopy called with unknown object Id";
    }
}

void DataStorageService::configNeighboursMap(std::unordered_map<int, ID> jsonIdToUuid,
                                             std::vector<CusJson::Room> jsonRooms) {
    for (const CusJson::Room& jsonRoom : jsonRooms) {
        Neighbours neighbours;

        buildNeighbours(jsonIdToUuid, jsonRoom, neighbours);

        auto correspRoomId = jsonIdToUuid.find(jsonRoom._id);
        if (correspRoomId == jsonIdToUuid.end()) {
            std::cout << "configNeighboursMap creation with " << jsonRoom._id << " in " << jsonRoom._name << " not found\n";
            return;
        }
        _roomIdToNeighbours.try_emplace(jsonIdToUuid[jsonRoom._id], neighbours);
    }
}

void DataStorageService::buildNeighbours(const std::unordered_map<int, ID>& jsonIdToUuid, const CusJson::Room& jsonRoom,
                                            Neighbours& neighbours) {
    for (const CusJson::JsonDoor& jsonDoor : jsonRoom._jsonDoors) {
        models::NeighbourInfo neighbourInfo;
        neighbourInfo.direction = models::DIRECTION_STRING_TO_ENUM_MAP.find(jsonDoor._dir)->second;

        auto correspRoomId = jsonIdToUuid.find(jsonDoor._to);
        if (correspRoomId == jsonIdToUuid.end()) {
            std::cout << "buildNeighbours with " << jsonDoor._to  << " not found\n";
            return;
        }

        neighbourInfo.destinationRoomId = jsonIdToUuid.at(jsonDoor._to);
        neighbourInfo.descriptions = jsonDoor._desc;

        neighbours.emplace_back(neighbourInfo);
    }
}

std::unordered_map<ID, models::Room> DataStorageService::getRoomIdToRoomMapCopy() {
    auto roomIdToRoomMapCopy = this->_roomIdToRoom;
    return roomIdToRoomMapCopy;
}

std::unordered_map<ID, std::vector<models::NeighbourInfo>> DataStorageService::getRoomIdToNeighboursMapCopy() {
    auto roomIdToNeighboursMapCopy = this->_roomIdToNeighbours;
    return roomIdToNeighboursMapCopy;
}

const CusJson::MiniGameList& DataStorageService::getMiniGameList() const {
    return _jsonMiniGameList;
}

void DataStorageService::readFromPath(std::string jsonDirPath) {
    std::vector<directory_entry> filesAndDir;
    std::vector<directory_entry> jsonFiles;
    path pathOfJsonDir(jsonDirPath);
    if (is_directory(pathOfJsonDir)) {
        copy(directory_iterator(pathOfJsonDir), directory_iterator(), back_inserter(filesAndDir));

        std::cout << pathOfJsonDir << " is a directory containing:\n";

        for (std::vector<directory_entry>::const_iterator it = filesAndDir.begin(); it != filesAndDir.end(); ++it) {
            auto filename = (*it).path().filename().string();
            // This assumes the json in the Dir are only Rooms. Loading files take a while so change this to find just one file to shorten startup.
            if (filename.find(".json") != std::string::npos) {
                jsonFiles.push_back((*it));
            }
        }
    }
    for (auto entry : jsonFiles) {
        std::cout << entry.path().filename().string() << " is being read\n";
        json jsonArea;
        auto jsonFileStream = boost::filesystem::ifstream(entry.path());
        jsonFileStream >> jsonArea;
        _jsonAreas.push_back(jsonArea.get<CusJson::Area>());
        configRoomsAndJsonIdMap(_jsonAreas.at(_jsonAreas.size() - 1));
        std::cout << entry.path().filename().string() << " is finished\n";
    }

    for (auto jsonArea : _jsonAreas) {
        std::cout << "Now configuring Objects and Neighbours for "<< jsonArea._name << std::endl;
        configObjectMap(jsonArea, _objectMap);
        configNeighboursMap(_jsonRoomIdToUuid, jsonArea._rooms);
    }
    std::cout << "All Configs complete, feel free to start connecting\n";
}

void DataStorageService::resetObjectsToWorld(std::unordered_map<ID, models::Room>& roomIdToRoomMap) {
    auto containerConfiguration = _jsonArea._containerWrappers;
    for (auto container : containerConfiguration) {
        auto roomQuery = roomIdToRoomMap.find(_jsonRoomIdToUuid.find(container._roomId)->second);
        if (roomQuery != roomIdToRoomMap.end()) {
            auto spawnedContainer = spawnObjectCopy(container._objectId);
            for (auto containedItemId : container._containedObjectIds) {
                spawnedContainer.getItemsInContainer().push_back(spawnObjectCopy(containedItemId));
            }
            roomQuery->second.addObject(spawnedContainer.getId(), spawnedContainer);
        }
    }
}
