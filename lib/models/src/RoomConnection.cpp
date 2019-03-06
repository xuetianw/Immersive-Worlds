//
// Created by user on 2/8/19.
//

#include "RoomConnection.h"

using models::RoomConnection;

const ID& models::RoomConnection::getTo() const {
    return _to;
}

void RoomConnection::setTo(const ID& to) {
    _to = to;
}

const ID& RoomConnection::getFrom() const {
    return _from;
}

void RoomConnection::setFrom(const ID& from) {
    _from = from;
}

const string& RoomConnection::getUserInputDirKey() const {
    return _userInputDirKey;
}

void RoomConnection::setUserInputDirKey(const string& keyword) {
    _userInputDirKey = keyword;
}
