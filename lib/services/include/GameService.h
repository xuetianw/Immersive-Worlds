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

    /**
     * Changes the roomID of an avatar to the room in the direction of the avatar's current room.
     * Direction should be valid for the current avatar's room.
     * @param avatarId
     * @param directionString
     * @return true if successfully changed avatar's room id. false otherwise.
     */
    bool moveAvatar(const ID& avatarId, const std::string& directionString);

    bool userYell(const User& user, const string& messageString);

    /**
     * Spawns avatar in starting room.
     * @param avatarId
     * @return true if avatar does not already exist. false otherwise
     */
    bool spawnAvatarInStartingRoom(const ID& avatarId);

    string getCurrentRoomName(const Connection& connection);

    std::optional<std::string> getAvatarRoomName(const ID& avatarId);

    /** 
     * Get the current minigame available in this room
     */
    models::MiniGame getMiniGame(const User& user, const std::string keywordString);

    bool roomHaveMiniGame(const User& user);

    /** 
     * Verify if the answer given in the minigame is the correct one.
     */
    bool verifyAnswer(const User& user, const int input);


    std::vector<ID> getAllAvatarIds(ID roomId);

    const ID& getRoomId(const ID& avatarId);

private:
    std::unordered_map<std::string, models::MiniGame> _roomIdToMiniGameConnectionsList;
    std::unordered_map<ID, Room> _roomIdToRoom;
    std::unordered_map<Connection, ID, ConnectionHash> _connectionToRoomId; //TODO remove

    DataStorageService _dataStorage;
    RoomConnectionService _roomConnectionService;
    AvatarService _avatarService;
};

#endif //WEBSOCKETNETWORKING_GAMESERVICE_H
