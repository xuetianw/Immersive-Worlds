#include <utility>

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
            _name(std::move(name)),
            _hp(200),
            _mana(100),
            _damageOutput(30),
            _inCombat(false){
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

        void enterCombat();

        void leaveCombat();


    private:
        ID _avatarId;
        ID _roomId;
        std::string _name;
        int _hp ;
        int _mana ;
        int _damageOutput;
        bool _inCombat;
    };
}

#endif //WEBSOCKETNETWORKING_AVATAR_H
