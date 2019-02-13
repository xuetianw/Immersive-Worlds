//
// Created by asim on 06/02/19.
//

#ifndef WEBSOCKETNETWORKING_GAMESERVICE_H
#define WEBSOCKETNETWORKING_GAMESERVICE_H

#include "Area.h"
#include "RoomConnection.h"
#include <Server.h>
#include "CusJson.h"
#include "DataStorage.h"
#include "GameService.h"

class GameService {
public:
    GameService();

private:
    // TODO: Add data models
    std::vector<channel::Area> _areas;
    std::unordered_map<int, channel::Room> _roomIdToRoom;
    std::unordered_map<int, channel::RoomId> _connectionIdToRoomId;
    std::unordered_map<int, std::vector<channel::RoomConnection>> _roomIdToRoomConnectionsList;

    DataStorage _dataStorage = DataStorage();

    channel::Room getRoom(const channel::RoomId &roomId);

    channel::Room getUserRoom(const networking::Connection &connection);

    void loadFromStorage();

public:

    /**
     * It is assumed that the user is in a room, and the room has a list of connections(can be blank).
     */
    bool moveUser(const networking::Connection &connection, const std::string keywordString);

    bool userYell(const networking::Connection &connection, const std::string messageString);

    bool placeUserInStartRoom(const networking::Connection &connection);

    bool placeUserInStartRoomDebug(const networking::Connection &connection, int id);

    string getCurrentRoomName(const networking::Connection &connection);

};

#endif //WEBSOCKETNETWORKING_GAMESERVICE_H
