//
// Created by user on 2/8/19.
//

#include <GameService.h>
#include <Server.h>

#include "GameService.h"

bool GameService::moveUser(const networking::Connection &connection, const std::string keywordString) {
  auto userId = connection.id;
  auto roomId = _connectionIdToRoomId.at((int)userId);
  auto connectedRoomList = _roomIdToConnections.at(roomId.getId());
  auto connectedRoom = std::find_if(connectedRoomList.begin(), connectedRoomList.end(), [keywordString](const channel::RoomConnection &roomConnection) -> bool {
    return roomConnection.getKeyword() == keywordString;
  });
  if (connectedRoom != connectedRoomList.end()) {
    _connectionIdToRoomId.find((int) userId)->second =connectedRoom.base()->getTo();
  }
  return connectedRoom != connectedRoomList.end();
}

bool GameService::userYell(const networking::Connection &connection, const std::string messageString) {
  return false;
}

string GameService::getCurrentRoomName(const networking::Connection &connection) {
  auto userId = connection.id;
  auto roomId = _connectionIdToRoomId.at((int)userId);
  auto room = _roomIdToRoom.at(roomId.getId());
  return room.getName();
}

bool GameService::placeUserInStartRoom(const networking::Connection &connection) {
  auto userId = connection.id;
  _connectionIdToRoomId.emplace((int)userId, channel::RoomId(10500)); // DEBUG starting room is in Lexia's shop
  return true;
}

void GameService::loadFromStorage() {
  json solaceJson = getTestingArea();
  auto solaceAreaJson = solaceJson.get<CusJson::Area>();

  for (const CusJson::Room &jsonRoom : solaceAreaJson._rooms) {
    _roomIdToRoom.emplace(jsonRoom._id, channel::Room(jsonRoom));
    vector<channel::RoomConnection> connectingRooms;
    for (const auto &jsonDoor : jsonRoom._jsonDoors) {
      connectingRooms.emplace_back(channel::RoomId(jsonDoor._to), channel::RoomId(jsonRoom._id), jsonDoor._dir); // Complete debug mode
    }
    _roomIdToConnections.emplace(jsonRoom._id, connectingRooms);
  }
}

json GameService::getTestingArea() {
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

GameService::GameService() {
  loadFromStorage();
}
