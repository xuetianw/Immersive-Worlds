//
// Created by Nirag Mehta on 2019-02-07.
//

#ifndef WEBSOCKETNETWORKING_ATTACKCOMMAND_H
#define WEBSOCKETNETWORKING_ATTACKCOMMAND_H



#include "Command.h"
#include "Server.h"

class AttackCommand : public Command {

public:

    AttackCommand() = default;

    ~AttackCommand(){};

    virtual networking::Message execute(GameService &service) override;

};

#endif //WEBSOCKETNETWORKING_ATTACKCOMMAND_H