
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
    return _damageOutput;
}

void Avatar::set_hp(int _hp) {
    Avatar::_hp = _hp;
}

void Avatar::set_mana(int _mana) {
    Avatar::_mana = _mana;
}

void Avatar::setDamageOutput(int damageOutput) {
    Avatar::_damageOutput = damageOutput;
}

bool models::Avatar::getBeingPlayed() const {
    return _being_played;
}

void models::Avatar::setBeingplayed(bool being_played) {
    Avatar::_being_played = being_played;
}

std::string models::Avatar::display() {
    std::ostringstream response;
    response << "name: " << this->getName();
    if (this->getBeingPlayed()) {
        response << "\nbeing played: " << "yes";
    } else{
        response << "\nbeing played: " << "no";
    }
    response << "\n_hp: " << std::to_string(this->get_hp())
             << "\n_mana: " << std::to_string(this->get_mana())
             << "\n";

    return response.str();
}


bool Avatar::getConfuseState() const {
    return _isConfused;
}

void Avatar::setConfuseState(bool isConfused) {
    _isConfused = isConfused;
}
