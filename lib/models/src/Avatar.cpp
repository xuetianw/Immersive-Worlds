
#include <Avatar.h>

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

void Avatar::setName(const std::string& name) {
    _name = name;
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

void Avatar::set_hp(int _hp) {
    Avatar::_hp = _hp;
}

void Avatar::set_mana(int _mana) {
    Avatar::_mana = _mana;
}

void Avatar::setDamageOutput(int damageOutput) {
    Avatar::damageOutput = damageOutput;
}

void Avatar::enterCombat() {
    Avatar::inCombat = true;
}

void models::Avatar::leaveCombat() {
    Avatar::inCombat = false;
}
