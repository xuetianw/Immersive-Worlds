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
#include "MiniGame.h"

class GameService {
public:
    GameService();

private:
    std::vector<channel::Area> _areas;
    std::unordered_map<int, channel::Room> _roomIdToRoom;
    std::unordered_map<networking::Connection, channel::RoomId, networking::ConnectionHash> _connectionToRoomId;
    std::unordered_map<int, std::vector<channel::RoomConnection>> _roomIdToRoomConnectionsList;
    std::unordered_map<int, channel::MiniGame> _roomIdToMiniGameConnectionsList;

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

    bool spawnUserInStartRoom(const networking::Connection &connection);

    bool spawnUserInRoom(const networking::Connection &connection, int id);

    string getCurrentRoomName(const networking::Connection &connection);

    channel::MiniGame getMiniGame(const networking::Connection &connection, const std::string keywordString);
    
    bool verifyAnswer(const networking::Connection &connection, const int input);
};

#endif //WEBSOCKETNETWORKING_GAMESERVICE_H
