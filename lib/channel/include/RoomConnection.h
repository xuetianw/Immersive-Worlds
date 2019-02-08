//
// Created by user on 2/8/19.
//

#ifndef WEBSOCKETNETWORKING_ROOMCONNECTION_H
#define WEBSOCKETNETWORKING_ROOMCONNECTION_H


#include "Room.h"

namespace channel {
    class RoomConnection {
    private:
        channel::RoomId _to;
        channel::RoomId _from;
        std::string _keyword;
    public:
        RoomConnection(const RoomId &_to, const RoomId &_from, const string &_keyword);

        const RoomId &get_to() const;

        void set_to(const RoomId &_to);

        const RoomId &get_from() const;

        void set_from(const RoomId &_from);

        const string &get_keyword() const;

        void set_keyword(const string &_keyword);

//private:
//    int state; // TODO this is left empty for now as design for making doors active or not is unknown/tbd later
    };
}

#endif //WEBSOCKETNETWORKING_ROOMCONNECTION_H
