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

    /*
     * functions which does the following
     * -Checks if combat already exists (maps User Id to respective Combat)
     * -checks if Avatar exists for given ID
     * -creates Combat object for User Avatar and changes their state
     */
    bool createCombat(ID playerId, ID NPCId);

    /*
     * function which
     * destroys combat if found and returns true,
     * otherwise returns false
     */
    bool destroyCombat(ID playerId);

private:
    int fightsInitialized;
    std::unordered_map<ID, Combat> _combatMap;
    AvatarService& _avatarService;
    RoomConnectionService& _roomConnectionService;
};

#endif //WEBSOCKETNETWORKING_COMBATSERVICE_H


