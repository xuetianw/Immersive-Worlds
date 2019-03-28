//
// Created by Nirag Mehta on 2019-03-08.
//

#ifndef WEBSOCKETNETWORKING_COMBATSERVICE_H
#define WEBSOCKETNETWORKING_COMBATSERVICE_H

#include <unordered_map>
#include "Room.h"
#include "Avatar.h"
#include "Combat.h"
#include "AvatarService.h"
#include "RoomConnectionService.h"

using namespace models;

/*
 * class for combat logic
 */
class CombatActions {

public:
    CombatActions(AvatarService& avatarService, RoomConnectionService& roomConnectionService) :
        _avatarService(avatarService), _roomConnectionService(roomConnectionService){}

    bool createCombat(Avatar& player, Avatar& NPC);

    void destroyCombat(Avatar& player);

private:
    int fightsInitialized;
    std::unordered_map<ID, Combat> _combatMap;
    AvatarService& _avatarService;
    RoomConnectionService& _roomConnectionService;
};

#endif //WEBSOCKETNETWORKING_COMBATSERVICE_H


