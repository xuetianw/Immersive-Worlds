//
// Created by user on 2/8/19.
//

#include <RoomConnection.h>

#include "RoomConnection.h"

using channel::RoomConnection;

RoomConnection::RoomConnection(const channel::RoomId &_to, const channel::RoomId &_from,
                                        const string &_userInputDirKey) : _to(_to), _from(_from), _userInputDirKey(_userInputDirKey) {}

const channel::RoomId &channel::RoomConnection::getTo() const {
    return _to;
}

void RoomConnection::setTo(const channel::RoomId &_to) {
    this->_to = _to;
}

const channel::RoomId &RoomConnection::getFrom() const {
    return _from;
}

void RoomConnection::setFrom(const channel::RoomId &_from) {
    this->_from = _from;
}

const string &RoomConnection::getUserInputDirKey() const {
    return _userInputDirKey;
}

void RoomConnection::setUserInputDirKey(const string &_keyword) {
    RoomConnection::_userInputDirKey = _keyword;
}
