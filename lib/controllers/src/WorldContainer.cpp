//
// Created by Michael on 1/23/19.
//
#include <iostream>
#include <string>
#include "../include/WorldContainer.h"
//mock implementation of login system. Will change with requirements

#include <CusJson.h>

#include <fstream>
#include <nlohmann/json.hpp>
#include <WorldContainer.h>

#include "string"

using json = nlohmann::json;
using namespace std;

void WorldContainer::loadFromStorage() {
    json solaceJson = debugArea();
    auto solaceArea = solaceJson.get<CusJson::Area>();
    this->_area = channel::Area(solaceArea);
}

void WorldContainer::resetWorld() {
    loadFromStorage();
}


WorldContainer::WorldContainer() {
  _area = channel::Area();
}

json WorldContainer::debugArea() {
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
      "id": 10501,
      "keywords": [
        "old",
        "lady"
      ],
      "shortdesc": "old lady",
      "longdesc": [
        "There is an old lady here."
      ],
      "description": []
    },
    {
      "id": 10502,
      "keywords": [
        "tired",
        "adventurer"
      ],
      "shortdesc": "tired adventurer",
      "longdesc": [
        "There is a tired adventurer resting here."
      ],
      "description": []
    },
    {
      "id": 10503,
      "keywords": [
        "Magnus",
        "wizard"
      ],
      "shortdesc": "Magnus wizard",
      "longdesc": [
        "Magnus the wizard is resting here from his long journeys."
      ],
      "description": []
    },
    {
      "id": 10504,
      "keywords": [
        "Lord",
        "doom",
        "warrior"
      ],
      "shortdesc": "Lord Doom",
      "longdesc": [
        "Lord Doom is resting here from his long journeys."
      ],
      "description": []
    },
    {
      "id": 10505,
      "keywords": [
        "foreign",
        "trade",
        "representative"
      ],
      "shortdesc": "Foreign Trade Representative",
      "longdesc": [
        "A foreign trade representative is waiting here to meet with the Captain of the Guard."
      ],
      "description": []
    },
    {
      "id": 10506,
      "keywords": [
        "bodyguard"
      ],
      "shortdesc": "bodyguard",
      "longdesc": [
        "There is a bodyguard here."
      ],
      "description": []
    },
    {
      "id": 10507,
      "keywords": [
        "Secretary",
        "captain"
      ],
      "shortdesc": "Secretary",
      "longdesc": [
        "The Captain of the Guard's Secretary is here."
      ],
      "description": [
        "She looks very busy.",
        "The Secretary says 'Sorry, but the Captain is extremely busy today'.",
        "The Secretary says 'Please sit down and have a seat in the meantime'."
      ]
    },
    {
      "id": 10508,
      "keywords": [
        "Secretary",
        "Lieutenant"
      ],
      "shortdesc": "Secretary",
      "longdesc": [
        "The Lieutenant Commander's Secretary is here."
      ],
      "description": [
        "She looks very busy.",
        "The Secretary says 'Sorry, but the Lieutenant is extremely busy today'.",
        "The Secretary says 'Please sit down and have a seat in the meantime'."
      ]
    },
    {
      "id": 10509,
      "keywords": [
        "Secretary",
        "Sergeant"
      ],
      "shortdesc": "Secretary",
      "longdesc": [
        "The Sergeant at Arm's Secretary is here."
      ],
      "description": [
        "She looks very busy.",
        "The Secretary says 'Sorry, but the Sergeant is extremely busy today'.",
        "The Secretary says 'Please sit down and have a seat in the meantime'."
      ]
    },
    {
      "id": 10510,
      "keywords": [
        "Macaw"
      ],
      "shortdesc": "the macaw",
      "longdesc": [
        "A large macaw is here."
      ],
      "description": [
        "The macaw looks like a strong, fearless fighter. It is a beautiful bird."
      ]
    },
    {
      "id": 10511,
      "keywords": [
        "Raven"
      ],
      "shortdesc": "the raven",
      "longdesc": [
        "A large, black raven is here."
      ],
      "description": [
        "The raven looks like a strong, fearless fighter."
      ]
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
      "name": "Marketplace.",
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

std::string WorldContainer::getRoomName(const int id) {
  return this->_area.getRoom({10500}).getName(); // currently uses constant id
}
