#include <utility>

#ifndef WEBSOCKETNETWORKING_AVATAR_H
#define WEBSOCKETNETWORKING_AVATAR_H

#include <string>
#include "ID.h"

namespace models {
    class Avatar {
    public:
//        Avatar(ID roomId, std::string name) :
//            _avatarId(ID{}),
//            _roomId(roomId),
//            _name(std::move(name)) {
//        }

        Avatar(ID avatarID, std::string name) :
                _avatarId(avatarID),
                _name(std::move(name)) {
        }


        Avatar(ID avatar, ID roomId, std::string name) :
            _avatarId(avatar),
            _roomId(roomId),
            _name(std::move(name)) {
        }

        const ID& getRoomId() const;

        void setRoomId(const ID& roomId);

        const ID& getAvatarId() const;

        const std::string& getName() const;

        void setName(const std::string& _name);

    private:
        ID _avatarId;
        ID _roomId;
        std::string _name;
    };
}

#endif //WEBSOCKETNETWORKING_AVATAR_H
