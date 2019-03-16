#include "Avatar.h"

using models::Avatar;

const ID& Avatar::getRoomId() const {
    return _roomId;
}

void Avatar::setRoomId(const ID& roomId) {
    _roomId = roomId;
}

const ID& models::Avatar::getAvatarId() const {
    return _avatarId;
}

const std::string& models::Avatar::getName() const {
    return _name;
}

void models::Avatar::setName(const std::string& name) {
    _name = name;
}

int models::Avatar::get_hp() const {
    return _hp;
}

void models::Avatar::set_hp(int _hp) {
    Avatar::_hp = _hp;
}

int models::Avatar::get_mana() const {
    return _mana;
}

void models::Avatar::set_mana(int _mana) {
    Avatar::_mana = _mana;
}

void models::Avatar::setDamageOutput(int damageOutput) {
    Avatar::damageOutput = damageOutput;
}

int models::Avatar::getDamageOutput() const {
    return damageOutput;
}

