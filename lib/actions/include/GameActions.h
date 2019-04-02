//
// Created by asim on 25/03/19.
//

#ifndef WEBSOCKETNETWORKING_GAMEACTIONS_H
#define WEBSOCKETNETWORKING_GAMEACTIONS_H

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

class GameActions {
public:
    GameActions(RoomConnectionService& roomConnectionService, AvatarService& avatarService)
            : _roomConnectionService(roomConnectionService),
              _avatarService(avatarService) {}

    /**
     * Changes the roomID of an avatar to the room in the direction of the avatar's current room.
     * Direction should be valid for the current avatar's room.
     * @param avatarId
     * @param directionString
     * @return true if successfully changed avatar's room id. false otherwise.
     */
    bool moveAvatar(const ID& avatarId, const std::string& directionString);

    /**
     * Get a list of directions available for the Avatar
     * @param avatarId
     * @return vector of directions.
     */
    std::vector<string> getDirectionsForAvatarId(const ID& avatarId);

    /**
     * Spawns avatar in starting room.
     * @param avatarId
     * @return true if avatar does not already exist. false otherwise
     */
    bool spawnAvatarInStartingRoom(const ID& avatarId);

    std::optional<std::string> getAvatarRoomName(const ID& avatarId);

    std::vector<ID> getAllAvatarIds(ID roomId);

    const ID& getRoomId(const ID& avatarId);

    std::vector<std::string> getAllAvatarsNamesForRoomId(const ID& roomId);

    /**
     * Get ids of adjacent rooms and current room
     */
    std::vector<ID> getAllAvatarIdsInNeighbourAndCurrent(ID roomId);

    std::vector<Message> displayAvatarinfo(const Message& message);

private:
    std::unordered_map<std::string, models::MiniGame> _roomIdToMiniGameConnectionsList;

    RoomConnectionService& _roomConnectionService;

    AvatarService& _avatarService;
};

#endif //WEBSOCKETNETWORKING_GAMEACTIONS_H
