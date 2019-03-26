#include <utility>

#ifndef WEBSOCKETNETWORKING_AVATAR_H
#define WEBSOCKETNETWORKING_AVATAR_H

#include <string>
#include "ID.h"

namespace models {
    class Avatar {
    public:
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

        int get_hp() const;

        int get_mana() const;

        int getDamageOutput() const;

        void set_hp(int _hp);

        void set_mana(int _mana);

        void setDamageOutput(int damageOutput);


    private:
        ID _avatarId;
        ID _roomId;
        std::string _name;
        int _hp ;
        int _mana ;
        int damageOutput;
    };
}

#endif //WEBSOCKETNETWORKING_AVATAR_H
