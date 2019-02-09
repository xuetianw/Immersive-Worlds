//
// Created by user on 2/8/19.
//

#include <RoomConnection.h>

#include "RoomConnection.h"

using channel::RoomConnection;

RoomConnection::RoomConnection(const channel::RoomId &_to, const channel::RoomId &_from,
                                        const string &_keyword) : _to(_to), _from(_from), _keyword(_keyword) {}

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

const string &RoomConnection::getKeyword() const {
    return _keyword;
}

void RoomConnection::setKeyword(const string &_keyword) {
    RoomConnection::_keyword = _keyword;
}
