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
#include "DataStorageService.h"
#include "ID.h"

using Room = models::Room;
using RoomConnection = models::RoomConnection;
using Connection = networking::Connection;
using ConnectionHash = networking::ConnectionHash;
using string = std::string;

class GameService {
public:
    GameService() : _dataStorage(DataStorageService()) {
        loadFromStorage();
    }

private:
    std::vector<models::Area> _areas;
    std::unordered_map<std::string, models::MiniGame> _roomIdToMiniGameConnectionsList;
    std::unordered_map<ID, Room> _roomIdToRoom;
    std::unordered_map<Connection, ID, ConnectionHash> _connectionToRoomId;
    std::unordered_map<ID, std::vector<RoomConnection> > _roomIdToRoomConnectionsList;

    DataStorageService _dataStorage;

    const Room* getRoomByName(const string& roomName) const;

    const Room& getUserRoom(const Connection& connection);

    void loadFromStorage();

public:

    /**
     * It is assumed that the user is in a room, and the room has a list of connections(can be blank).
     */
    bool spawnUserInStartRoom(const networking::Connection& connection);
    
    bool moveUser(const User& user, const string& keywordString);

    bool userYell(const User& user, const string& messageString);

    bool spawnUserInRoomOnLogin(const Connection& connection);

    bool spawnUserInRoom(const Connection& connection, const ID& id);

    string getCurrentRoomName(const Connection& connection);

    ID getCurrentRoomId(const Connection& connection);

    /** 
     * Get the current minigame available in this room
     */
    models::MiniGame getMiniGame(const User& user, const std::string keywordString);

    bool roomHaveMiniGame(const User& user);

    /** 
     * Verify if the answer given in the minigame is the correct one.
     */
    bool verifyAnswer(const User& user, const int input);
};

#endif //WEBSOCKETNETWORKING_GAMESERVICE_H
