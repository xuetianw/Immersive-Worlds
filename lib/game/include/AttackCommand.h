//
// Created by Nirag Mehta on 2019-02-07.
//

#ifndef WEBSOCKETNETWORKING_ATTACKCOMMAND_H
#define WEBSOCKETNETWORKING_ATTACKCOMMAND_H

const int MAX_ROUNDS = 20;
const int HEARTBEATS_PER_ROUND= 5;


#include "Command.h"
#include "Server.h"

class AttackCommand : public Command {

private:
    unsigned int rounds;

    unsigned int heartbeatCount = 0;

public:

    AttackCommand() = default;

    //need to figure out how to obtain Character
    void attackCharacter(int opponentId);

    virtual networking::Message execute(GameService &service) override;

};

#endif //WEBSOCKETNETWORKING_ATTACKCOMMAND_H