//
// Created by user on 2/8/19.
//

#include <RoomConnection.h>

#include "RoomConnection.h"

using channel::RoomConnection;

RoomConnection::RoomConnection(const channel::RoomId &_to, const channel::RoomId &_from,
                                        const string &_keyword) : _to(_to), _from(_from), _keyword(_keyword) {}

const channel::RoomId &channel::RoomConnection::get_to() const {
    return _to;
}

void RoomConnection::set_to(const channel::RoomId &_to) {
    this->_to = _to;
}

const channel::RoomId &RoomConnection::get_from() const {
    return _from;
}

void RoomConnection::set_from(const channel::RoomId &_from) {
    this->_from = _from;
}

const string &RoomConnection::get_keyword() const {
    return _keyword;
}

void RoomConnection::set_keyword(const string &_keyword) {
    RoomConnection::_keyword = _keyword;
}
