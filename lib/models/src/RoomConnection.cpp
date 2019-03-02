//
// Created by user on 2/8/19.
//

#include <RoomConnection.h>

#include "RoomConnection.h"

using models::RoomConnection;

RoomConnection::RoomConnection(const models::RoomId &_to, const models::RoomId &_from,
                                        const string &_userInputDirKey) : _to(_to), _from(_from), _userInputDirKey(_userInputDirKey) {}

const models::RoomId &models::RoomConnection::getTo() const {
    return _to;
}

void RoomConnection::setTo(const models::RoomId &_to) {
    this->_to = _to;
}

const models::RoomId &RoomConnection::getFrom() const {
    return _from;
}

void RoomConnection::setFrom(const models::RoomId &_from) {
    this->_from = _from;
}

const string &RoomConnection::getUserInputDirKey() const {
    return _userInputDirKey;
}

void RoomConnection::setUserInputDirKey(const string &_keyword) {
    RoomConnection::_userInputDirKey = _keyword;
}
