//
// Created by Owner on 1/18/2019.
//

#ifndef WEBSOCKETNETWORKING_AVATAR_H
#define WEBSOCKETNETWORKING_AVATAR_H

#include "ContainerItem.h"
#include "Inventory.h"
#include "Room.h"
#include "InventoryItem.h"

enum class AvatarType {
    NON_PLAYABLE,
    PLAYABLE
};

class Avatar {
public:
    Avatar(AvatarType avatarType, int userId);

    bool isPlayable();

    AvatarType get_avatarType() const;

    int get_userID() const;

    const InventoryItem &get_currentClothing() const;

    const Inventory &get_inventory() const;

    const string &getName() const;

    int get_hp() const;

    int get_mana() const;

    const models::Room &get_currentRoom() const;

    string get_shortDesc() const;

    string get_longDesc() const;

    string get_tellCommandMessages() const;

    void set_hp(unsigned int _hp);

    void set_mana(unsigned int _mana);

    void set_currentRoom(const models::Room &_currentRoom);

    /**
     * Adds an InventoryItem to characterInventory.
     * @param inventoryItem item to add to inventory
     */
    bool takeItem(InventoryItem inventoryItem);

    /**
     * Puts an object into a ContainerItem
     * @param inventoryItem item to put into ContainerItem
     * @param containerObject container to place object in
     */
    void putItem(InventoryItem inventoryItem, ContainerItem containerObject);

    /**
     * Removes object from characterInventory and places it in currentRoom's inventory
     * @param inventoryItem item to remove from inventory
     */
    void dropItem(InventoryItem inventoryItem);

    // TODO: move "giving" an item up higher as it requires knowledge of another avatar

    bool wearItem(InventoryItem inventoryItem);

    InventoryItem removeItem(InventoryItem inventoryItem);

private:
    // TODO: @Nirag, these are probably better off loaded in as opposed to declared global in the header
    int MAX_HP;
    int MAX_MANA;

    AvatarType _avatarType;

    /** A unique int identifying the character*/
    int _userID; //this will eventually be a User type object

    /**
     * Clothing item that the Avatar is currently wearing
     */
    InventoryItem _currentClothing;

    Inventory _inventory;

    std::string name;

    int _hp = MAX_HP;

    int _mana = MAX_MANA;

    models::Room _currentRoom;

    string _shortDesc;

    string _longDesc;

    string _tellCommandMessages; //eventually should be a buffer of Message objects for character-to-character messaging
};

#endif //WEBSOCKETNETWORKING_AVATAR_H
