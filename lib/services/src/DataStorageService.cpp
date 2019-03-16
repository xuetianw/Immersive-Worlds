//
// Created by user on 2/11/19.
//

#include "DataStorageService.h"
#include <iostream>

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

json DataStorageService::getTestingArea() {
    json j = R"(
{
"AREA": {
    "name": "Town Of Solace"
  },
  "NPCS": [
    {
      "id": 10500,
      "keywords": [
        "bat"
      ],
      "shortdesc": "bat",
      "longdesc": [
        "There is a large bat here."
      ],
      "description": []
    },
    {
      "id": 10538,
      "keywords": [
        "Lexie"
      ],
      "shortdesc": "Lexie",
      "longdesc": [
        "Lexie is here."
      ],
      "description": [
        "Lexie is an accomplish diver. But he seems to have problems keeping",
        "students."
      ]
    }
  ],
  "OBJECTS": [
    {
      "id": 10500,
      "keywords": [
        "chamorro",
        "ringmail"
      ],
      "shortdesc": "chamorro ringmail",
      "longdesc": [
        "A bunch of rings sewn together with taotamoa bark is on the ground."
      ],
      "extra": [
        {
          "keywords": [
            "ringmail"
          ],
          "desc": [
            "This armor is imported from the island of Guam."
          ]
        }
      ]
    },
    {
      "id": 10501,
      "keywords": [
        "Mcbread"
      ],
      "shortdesc": "mcbread",
      "longdesc": [
        "A Mcloaf of Mcbread has been left here."
      ],
      "extra": []
    },
    {
      "id": 10502,
      "keywords": [
        "enchanted",
        "two-handed",
        "sword"
      ],
      "shortdesc": "enchanted two-handed sword",
      "longdesc": [
        "A large two-handed sword with runes etched in it is on the floor."
      ],
      "extra": []
    },
    {
      "id": 10562,
      "keywords": [
        "safe",
        "deposit",
        "box"
      ],
      "shortdesc": "safe deposit box",
      "longdesc": [
        "A strong metal box is embedded in the wall."
      ],
      "extra": [
        {
          "keywords": [
            "safe",
            "deposit",
            "box"
          ],
          "desc": [
            "You see a strong metal box used to keep the town deposits in."
          ]
        }
      ]
    },
    {
      "id": 10563,
      "keywords": [
        "gold",
        "coins"
      ],
      "shortdesc": "alot of gold coins.",
      "longdesc": [
        "A lot of gold is here."
      ],
      "extra": []
    }
  ],
  "ROOMS": [
    {
      "id": 10500,
      "name": "Lexie's Scuba Shop",
      "desc": [
        "This is one shop that seems to be ahead of its time.",
        "But who doesn't like scuba diving. If you don't already have",
        "a diving license you can buy one. Lexie can also train you too. Not  in",
        "scuba though. Something about a revoked teaching credential due to too",
        "many students dying or something. This does seem to be an odd place to have",
        "a scuba shop considering the sea is miles away. But I guess you could",
        "always go diving in the lake. But why?....",
        "There is a small sign here."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "You see the marketplace."
          ],
          "keywords": [],
          "to": 10608
        }
      ],
      "extended_descriptions": [
        {
          "keywords": [
            "sign"
          ],
          "desc": [
            "The sign reads:",
            "",
            "  List  - Show which various items are in the store.",
            "  Buy   - Buy an item.",
            "  Value - The shopkeeper will (free of charge) tell how much he will",
            "          pay for your item.",
            "  Sell  - Sell an item."
          ]
        }
      ]
    },
   {
      "id": 10608,
      "name": "Marketplace.",
      "desc": [
        "This is the Marketplace of Solace. Where the farmers come to sell their",
        "crops. The smell of vegetables and fruit fill the air. There are a couple",
        "other vendors selling trinkets and other items."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see Lexie's Scuba Shop."
          ],
          "keywords": [],
          "to": 10500
        },
        {
          "dir": "west",
          "desc": [
            "You see the Marketplace."
          ],
          "keywords": [],
          "to": 10609
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10609,
      "name": "Marketplace2.",
      "desc": [
        "This is the Marketplace of Solace. Where the farmers come to sell their",
        "crops. The smell of vegetables and fruit fill the air. There are a couple",
        "other vendors selling trinkets and other items."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see the marketplace."
          ],
          "keywords": [],
          "to": 10608
        }
      ],
      "extended_descriptions": []
    }
  ],
  "RESETS": [
    {
      "action": "npc",
      "id": 10538,
      "limit": 1,
      "room": 10500
    },
    {
      "action": "give",
      "id": 10500
    },
    {
      "action": "give",
      "id": 10501
    },
    {
      "action": "equip",
      "id": 10502,
      "slot": 16
    },
    {
      "action": "door",
      "id": 0,
      "room": 10609,
      "state": "locked"
    },
    {
      "action": "object",
      "id": 10562,
      "room": 10500
    },
    {
      "action": "put",
      "id": 10563,
      "container": 10562
    }
  ]
})"_json;
    return j;
}

const Area& DataStorageService::getJsonArea() const {
    return _jsonArea;
}

std::unordered_map<int, SingleItem> DataStorageService::getObjectsFromJson() {
    return _objectMap;
}

void DataStorageService::configRoomsAndJsonIdMap(const CusJson::Area& jsonArea) {
    for (const CusJson::Room& jsonRoom : jsonArea._rooms) {
        models::Room room{jsonRoom};
        const ID& roomId = room.getId();

        _jsonRoomIdToUuid.emplace(jsonRoom._id, roomId);
        _roomIdToRoom.emplace(roomId, room);
    }
}

std::unordered_map<int, SingleItem> DataStorageService::configObjectMap(const CusJson::Area& jsonArea) {
    std::unordered_map<int, SingleItem> map;
    for (CusJson::Object jsonObject : jsonArea._objects) {
        std::vector<string> keywords = jsonObject.keywords;
        std::vector<string> longDesc = jsonObject.longdesc;
        for (CusJson::ExtDesc extDesc : jsonObject._jsonExtDesc) {
            keywords.insert(keywords.begin(), extDesc._keywords.begin(), extDesc._keywords.end());
            longDesc.insert(longDesc.begin(), extDesc._desc.begin(), extDesc._desc.end());
        }
        auto item = SingleItem(ID(jsonObject.id), keywords, jsonObject.shortdesc, longDesc, "");
        map.insert({jsonObject.id, item});
    }
    return map;
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

        _roomIdToNeighbours.try_emplace(jsonIdToUuid[jsonRoom._id], neighbours);
    }
}

void DataStorageService::buildNeighbours(const std::unordered_map<int, ID>& tmp, const CusJson::Room& jsonRoom,
                                            Neighbours& neighbours) {
    for (const CusJson::JsonDoor& jsonDoor : jsonRoom._jsonDoors) {
        models::NeighbourInfo neighbourInfo;
        neighbourInfo.direction = models::DIRECTION_STRING_TO_ENUM_MAP.find(jsonDoor._dir)->second;
        neighbourInfo.destinationRoomId = tmp.at(jsonDoor._to);
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
