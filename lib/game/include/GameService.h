//
// Created by asim on 06/02/19.
//

#ifndef WEBSOCKETNETWORKING_GAMESERVICE_H
#define WEBSOCKETNETWORKING_GAMESERVICE_H

#include "Area.h"
#include "RoomConnection.h"
#include <Server.h>

#include "GameService.h"

class GameService {
public:
    GameService() = default;

    // TODO: Define interface to access data
private:
    // TODO: Add data models
    std::vector<channel::Area> _areas;
    std::unordered_map<int, channel::Room> _roomIdToRoom;
    std::unordered_map<int, channel::RoomId> _connectionIdToRoomId;
    std::unordered_map<int, std::vector<channel::RoomConnection>> _roomIdToConnections;
    channel::Room getRoom(const channel::RoomId &roomId);
    channel::Room getUserRoom(const networking::Connection &connection);
public:

  /**
   * It is assumed that the user is in a room, and the room has a list of connections(can be blank).
   */
    bool moveUser(const networking::Connection &connection, const std::string keywordString);

    bool userYell(const networking::Connection &connection, const std::string messageString);

    bool placeUserInStartRoom(const networking::Connection &connection);

    string getCurrentRoomName(const networking::Connection &connection);

};

#endif //WEBSOCKETNETWORKING_GAMESERVICE_H
