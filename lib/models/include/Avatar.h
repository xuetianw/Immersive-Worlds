#include <utility>

#ifndef WEBSOCKETNETWORKING_AVATAR_H
#define WEBSOCKETNETWORKING_AVATAR_H

#include <string>
#include "ID.h"

namespace models {
    class Avatar {
    public:

        Avatar(ID avatarId, std::string name) :
            _avatarId(avatarId),
            _name(std::move(name)){
        }

        Avatar(ID avatarId, ID roomId, std::string name, bool playable) :
            _avatarId(avatarId),
            _roomId(roomId),
            _name(std::move(name)),
            _being_played(playable) {
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

        bool is_being_played() const;

        void set_being_played(bool _being_played);


    private:
        ID _avatarId;
        ID _roomId;
        std::string _name;
        int _hp = 500;
        int _mana = 300;
        int _damageOutput = 40;
        bool _being_played;
    };
}

#endif //WEBSOCKETNETWORKING_AVATAR_H
