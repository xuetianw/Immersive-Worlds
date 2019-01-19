//
// Created by fred on 18/01/19.
//

#ifndef ADVENTURE2019_COMBAT_H
#define ADVENTURE2019_COMBAT_H

class Combat {
public:
    Combat();
    ~Combat();
    void attack();
    void kill();
    void flee();

    bool get_state_of_fight();
    void set_state_of_fight(bool state);


private:
    bool state_of_fight;
};

#endif //ADVENTURE2019_COMBAT_H
