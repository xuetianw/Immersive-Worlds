//
// Created by Owner on 1/18/2019.
//

#include "Avatar.h"

using models::Avatar;
using models::AvatarType;

bool Avatar::takeItem(InventoryItem inventoryItem) {
    return _inventory.addItem(inventoryItem);
}

void Avatar::putItem(InventoryItem inventoryItem, ContainerItem containerObject) {
    // TODO: complete once adding to a containerItem is implemented
}

void Avatar::dropItem(InventoryItem inventoryItem) {
    // TODO: complete after implementing an _inventory in a room
}

bool Avatar::wearItem(InventoryItem inventoryItem) {
    if (inventoryItem.getItemType() == ItemType::CLOTHING) {
        InventoryItem clothingToRemove = _currentClothing;
        std::unique_ptr<InventoryItem> clothingToWear = removeItem(inventoryItem);
        _currentClothing = *clothingToWear;
        return _inventory.addItem(clothingToRemove);
    }
    return false;
}

std::unique_ptr<InventoryItem> Avatar::removeItem(const InventoryItem& inventoryItem) {
    return _inventory.removeItem(inventoryItem.getId());
}

bool Avatar::isPlayable() {
    return _avatarType == AvatarType::PLAYABLE;
}

Avatar::Avatar(AvatarType avatarType, ID userId)
        : MAX_HP(200),
          MAX_MANA(150),
          MAX_DAMAGE_OUTPUT(30),
          _avatarType(avatarType),
          _userID(userId),
          _inventory(Inventory(_userID)) {}

void Avatar::set_hp(unsigned int _hp) {
    Avatar::_hp = _hp;
}

void Avatar::set_mana(unsigned int _mana) {
    Avatar::_mana = _mana;
}

void Avatar::setDamageOutput(int damageOutput) {
    Avatar::damageOutput = damageOutput;
}

AvatarType Avatar::get_avatarType() const {
    return _avatarType;
}

const ID& Avatar::get_userID() const {
    return _userID;
}

const InventoryItem &Avatar::get_currentClothing() const {
    return _currentClothing;
}

const Inventory &Avatar::get_inventory() const {
    return _inventory;
}

const string &Avatar::getName() const {
    return name;
}

int Avatar::get_hp() const {
    return _hp;
}

int Avatar::get_mana() const {
    return _mana;
}

int Avatar::getDamageOutput() const {
    return damageOutput;
}

string Avatar::get_shortDesc() const {
    return _shortDesc;
}

string Avatar::get_longDesc() const {
    return _longDesc;
}

string Avatar::get_tellCommandMessages() const {
    return _tellCommandMessages;
}
