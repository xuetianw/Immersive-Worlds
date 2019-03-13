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
#include "RoomConnectionService.h"
#include "AvatarService.h"

using Room = models::Room;
using RoomConnection = models::RoomConnection;
using Connection = networking::Connection;
using ConnectionHash = networking::ConnectionHash;
using string = std::string;

class GameService {
public:
    GameService()
        : _dataStorage(DataStorageService()),
          _roomConnectionService(_dataStorage),
          _avatarService(_dataStorage) {

    }

    bool moveUser(const User& user, const string& keywordString);

    bool userYell(const User& user, const string& messageString);

    bool spawnAvatarInStartingRoom(const ID& avatarId);

    bool spawnUserInRoom(const Connection& connection, const ID& id);

    string getCurrentRoomName(const Connection& connection);

    /** 
     * Get the current minigame available in this room
     */
    models::MiniGame getMiniGame(const User& user, const std::string keywordString);

    bool roomHaveMiniGame(const User& user);

    /** 
     * Verify if the answer given in the minigame is the correct one.
     */
    bool verifyAnswer(const User& user, const int input);


    std::vector<ID> getAllAvatarIdsForRoomId(ID roomId);

    const ID& getRoomIdFromAvatarId(const ID& avatarId);

private:
    std::unordered_map<std::string, models::MiniGame> _roomIdToMiniGameConnectionsList;
    std::unordered_map<ID, Room> _roomIdToRoom;
    std::unordered_map<Connection, ID, ConnectionHash> _connectionToRoomId;
    std::unordered_map<ID, std::vector<RoomConnection> > _roomIdToRoomConnectionsList;

    DataStorageService _dataStorage;
    RoomConnectionService _roomConnectionService;
    AvatarService _avatarService;

    const Room* getRoomByName(const string& roomName) const;

    const Room& getUserRoom(const Connection& connection);
};

#endif //WEBSOCKETNETWORKING_GAMESERVICE_H
