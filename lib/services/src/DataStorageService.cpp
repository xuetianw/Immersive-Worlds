//
// Created by user on 2/11/19.
//

#include "DataStorageService.h"
#include <iostream>

using CusJson::Area;

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
        std::cerr << "spawnObjectCopy called with unknown object Id" << jsonId << std::endl;
    }
}

void DataStorageService::configNeighboursMap(std::unordered_map<int, ID> jsonIdToUuid,
                                             std::vector<CusJson::Room> jsonRooms) {
    for (const CusJson::Room& jsonRoom : jsonRooms) {
        Neighbours neighbours;

        buildNeighbours(jsonIdToUuid, jsonRoom, neighbours);

        auto correspRoomId = jsonIdToUuid.find(jsonRoom._id);
        if (correspRoomId == jsonIdToUuid.end()) {
            std::cerr << "configNeighboursMap creation with " << jsonRoom._id << " in " << jsonRoom._name << " not found\n";
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
            std::cerr << "buildNeighbours with " << jsonDoor._to  << " not found\n";
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

void DataStorageService::loadInJsonAreas() {
    std::cout << "Assumed that ABSOLUTE_PATH_CONFIG_DIR + AREAS_DIRECTORY only contains areaJson files \n";
    std::vector<directory_entry> jsonFiles;
    string jsonAreaPath = DataStorageService::ABSOLUTE_PATH_CONFIG_DIR + DataStorageService::AREAS_DIRECTORY;
    path pathOfAreaJsonDir(jsonAreaPath);
    copy(directory_iterator(pathOfAreaJsonDir), directory_iterator(), back_inserter(jsonFiles));

    for (auto areaJsonFile : jsonFiles) {
        std::cout << areaJsonFile.path().filename().string() << " is being read\n";
        auto jsonFileStream = boost::filesystem::ifstream(areaJsonFile.path());
        json jsonArea;
        jsonFileStream >> jsonArea;
        _jsonAreas.push_back(jsonArea.get<CusJson::Area>());
        configRoomsAndJsonIdMap(_jsonAreas.back());
        std::cout << areaJsonFile.path().filename().string() << " is finished\n";
    }

    for (auto jsonArea : _jsonAreas) {
        std::cout << "Now configuring Objects and Neighbours for "<< jsonArea._name << std::endl;
        configObjectMap(jsonArea, _objectMap);
        configNeighboursMap(_jsonRoomIdToUuid, jsonArea._rooms);
    }
    std::cout << "Room Configs complete\n";
}


void DataStorageService::loadInMiniGames() {
    std::cout << "Assumed that ABSOLUTE_PATH_CONFIG_DIR + MINIGAMES_DIRECTORY + MINIGAME_FILE_NAME is the path to the minigame file \n";
    std::vector<directory_entry> jsonFiles;
    string minigamePath = DataStorageService::ABSOLUTE_PATH_CONFIG_DIR + DataStorageService::MINIGAMES_DIRECTORY + DataStorageService::MINIGAME_FILE_NAME;
    path pathOfJsonDir(minigamePath);
    auto jsonFileStream = boost::filesystem::ifstream(pathOfJsonDir);
    json jsonMinigame;
    jsonFileStream >> jsonMinigame;
    _jsonMiniGameList = jsonMinigame.get<CusJson::MiniGameList>();

    std::cout << "Minigame Configs complete\n";
}

void DataStorageService::resetObjectsToWorld(std::unordered_map<ID, models::Room>& roomIdToRoomMap) {
    auto objectConfiguration = _jsonArea._objectWrappers;
    for (auto container : objectConfiguration) {
        auto roomQuery = roomIdToRoomMap.find(_jsonRoomIdToUuid.find(container._roomJsonId)->second);
        if (roomQuery != roomIdToRoomMap.end()) {
            auto spawnedContainer = spawnObjectCopy(container._objectJsonId);
            for (auto containedItemId : container._containedObjectJsonIds) {
                spawnedContainer.getItemsInContainer().push_back(spawnObjectCopy(containedItemId));
            }
            roomQuery->second.addObject(spawnedContainer.getId(), spawnedContainer);
        }
    }
}
