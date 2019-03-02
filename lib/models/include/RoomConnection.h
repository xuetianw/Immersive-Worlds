//
// Created by user on 2/8/19.
//

#ifndef WEBSOCKETNETWORKING_ROOMCONNECTION_H
#define WEBSOCKETNETWORKING_ROOMCONNECTION_H


#include "Room.h"

namespace models {
    class RoomConnection {
    private:
        models::RoomId _to;
        models::RoomId _from;
        std::string _userInputDirKey;
    public:
        RoomConnection(const RoomId &_to, const RoomId &_from, const string &_userInputDirKey);

        const RoomId &getTo() const;

        void setTo(const RoomId &_to);

        const RoomId &getFrom() const;

        void setFrom(const RoomId &_from);

        const string &getUserInputDirKey() const;

        void setUserInputDirKey(const string &_keyword);

//private:
//    int state; // TODO this is left empty for now as design for making doors active or not is unknown/tbd later
    };
}

#endif //WEBSOCKETNETWORKING_ROOMCONNECTION_H
