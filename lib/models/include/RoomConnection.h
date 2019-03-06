//
// Created by user on 2/8/19.
//

#ifndef WEBSOCKETNETWORKING_ROOMCONNECTION_H
#define WEBSOCKETNETWORKING_ROOMCONNECTION_H

#include "ID.h"
#include "Room.h"

namespace models {
    class RoomConnection {
    private:
        ID _to;
        ID _from;
        std::string _userInputDirKey;

    public:
        RoomConnection(const ID& to,
                const ID& from,
                string userInputDirKey) :
                _to(to),
                _from(from),
                _userInputDirKey(move(userInputDirKey)) {}

        const ID& getTo() const;

        void setTo(const ID& to);

        const ID& getFrom() const;

        void setFrom(const ID& from);

        const string& getUserInputDirKey() const;

        void setUserInputDirKey(const string& keyword);

    //private:
        // int state; TODO: this is left empty for now as design for making doors active or not is unknown/tbd later
    };
}

#endif //WEBSOCKETNETWORKING_ROOMCONNECTION_H
