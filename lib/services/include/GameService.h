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
    std::vector<models::Area> _areas;
    std::unordered_map<int, models::Room> _roomIdToRoom;
    std::unordered_map<networking::Connection, models::RoomId, networking::ConnectionHash> _connectionToRoomId;
    std::unordered_map<int, std::vector<models::RoomConnection>> _roomIdToRoomConnectionsList;

    DataStorage _dataStorage = DataStorage();

    models::Room getRoom(const models::RoomId &roomId);

    models::Room getUserRoom(const networking::Connection &connection);

    void loadFromStorage();

public:

    /**
     * It is assumed that the user is in a room, and the room has a list of connections(can be blank).
     */
    bool moveUser(const networking::Connection &connection, const std::string keywordString);

    bool userYell(const networking::Connection &connection, const std::string messageString);

    bool spawnUserInStartRoom(const networking::Connection &connection);

    bool spawnUserInRoom(const networking::Connection &connection, int id);

    string getCurrentRoomName(const networking::Connection &connection);

};

#endif //WEBSOCKETNETWORKING_GAMESERVICE_H
