    //
// Created by fred on 18/01/19.
//

#include "../include/Combat.h"

Combat :: ~Combat() {}

Combat ::Combat() {
    state_of_fight = true;
}

void Combat::attack() {

}

void Combat::kill() {

}

void Combat::flee() {

}

bool Combat::get_state_of_fight() {
    return this->state_of_fight;
}


void Combat::set_state_of_fight(bool state) {
    this->state_of_fight = state;
}