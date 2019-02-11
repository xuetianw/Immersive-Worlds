
#ifndef WEBSOCKETNETWORKING_MOVECOMMAND_H
#define WEBSOCKETNETWORKING_MOVECOMMAND_H

#include "Command.h"
#include "Server.h"

class MoveCommand : public Command {
public:
    MoveCommand() = default;

    virtual networking::Message execute(GameService &service, const networking::Message& message) override;

};

#endif //WEBSOCKETNETWORKING_MOVECOMMAND_H