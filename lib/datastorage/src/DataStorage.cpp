//
// Created by user on 2/11/19.
//

#include <DataStorage.h>

#include "DataStorage.h"

DataStorage::DataStorage() {
    json solaceJson = getTestingArea();
    jsonArea = solaceJson.get<CusJson::Area>();
}



json DataStorage::getTestingArea() {
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
      "id": 10502
    },
    {
      "action": "door",
      "id": 0,
      "room": 10609,
      "state": "locked"
    }
  ]
})"_json;
    return j;
}


const CusJson::Area &DataStorage::getJsonArea() const {
    return jsonArea;
}

void DataStorage::setJsonArea(const CusJson::Area &jsonArea) {
    DataStorage::jsonArea = jsonArea;
}
