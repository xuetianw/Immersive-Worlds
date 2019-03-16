#include "Avatar.h"

using models::Avatar;

const ID& Avatar::getRoomId() const {
    return _roomId;
}

void Avatar::setRoomId(const ID& roomId) {
    _roomId = roomId;
}

const int & models::Avatar::getAvatarId() const {
    return _avatarId;
}

const std::string& models::Avatar::getName() const {
    return _name;
}

void models::Avatar::setName(const std::string& name) {
    _name = name;
}
