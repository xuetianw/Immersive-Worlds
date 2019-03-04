//
// Created by asim on 06/02/19.
//

#ifndef WEBSOCKETNETWORKING_GAMESERVICE_H
#define WEBSOCKETNETWORKING_GAMESERVICE_H

#include <string>

#include "Area.h"
#include "RoomConnection.h"
#include "User.h"
#include "Message.h"
#include "CusJson.h"
#include "DataStorage.h"

using Room = models::Room;
using RoomId = models::RoomId;
using RoomConnection = models::RoomConnection;
using Connection = networking::Connection;
using ConnectionHash = networking::ConnectionHash;
using string = std::string;

class GameService {
public:
    GameService();

private:
    std::vector<models::Area> _areas;
    std::unordered_map<int, models::Room> _roomIdToRoom;
    std::unordered_map<Connection, RoomId, ConnectionHash> _connectionToRoomId;
    std::unordered_map<int, std::vector<RoomConnection>> _roomIdToRoomConnectionsList;

    DataStorage _dataStorage = DataStorage();

    const Room& getRoom(const RoomId& roomId);

    const Room& getUserRoom(const Connection& connection);

    void loadFromStorage();

public:

    /**
     * It is assumed that the user is in a room, and the room has a list of connections(can be blank).
     */
    bool moveUser(const User& user, const string& keywordString);

    bool userYell(const User& user, const string& messageString);

    bool spawnUserInStartRoom(const Connection& connection);

    bool spawnUserInRoom(const Connection& connection, int id);

    string getCurrentRoomName(const Connection& connection);

};

#endif //WEBSOCKETNETWORKING_GAMESERVICE_H
