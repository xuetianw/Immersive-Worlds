//
// Created by user on 2/11/19.
//

#include "DataStorageService.h"
#include <iostream>

using CusJson::Area;

json DataStorageService::getTestingMiniGameList() {

    std::cout << "RAN MINIGAME" << std::endl;
    json j = R"(
  {
    "MINIGAMES" : [
        {
          "id" : 1,
          "roomId" : 10500,
          "roomName" : "Lexie's Scuba Shop",
          "type" : "multiple_choice",
          "question" : "Which spelling is correct?",
          "answers" : [
            "RRRR",
            "CAT",
            "TTTT"
          ],
          "correctanswer" : 1
        },
        {
          "id" : 2,
          "roomId" : 10608,
          "roomName" : "Marketplace.",
          "type" : "multiple_choice",
          "question" : "Which spelling is correct?",
          "answers" : [
            "RRRR",
            "DOG",
            "TTTT"
          ],
          "correctanswer" : 1
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

]})"_json;
    return j;
}

const Area& DataStorageService::getJsonArea() const {
    return _jsonArea;
}

void DataStorageService::setJsonArea(const Area& jsonArea) {
    _jsonArea = jsonArea;
}

const CusJson::MiniGameList& DataStorageService::getMiniGameList() const {
    return _jsonMiniGameList;
}
