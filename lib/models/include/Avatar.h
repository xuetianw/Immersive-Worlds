#ifndef WEBSOCKETNETWORKING_AVATAR_H
#define WEBSOCKETNETWORKING_AVATAR_H

#include <string>
#include "ID.h"

namespace models {
    class Avatar {
    public:
        Avatar(ID roomId, std::string name) :
            _avatarId(ID{}),
            _roomId(roomId),
            _name(std::move(name)) {

        }

        const ID& getRoomId() const;

        void setRoomId(const ID& roomId);

        const ID& getAvatarId() const;

        const string& getName() const;

        void setName(const string& _name);

    private:
        ID _avatarId;
        ID _roomId;
        std::string _name;
    };
}

#endif //WEBSOCKETNETWORKING_AVATAR_H
