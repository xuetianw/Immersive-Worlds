//
// Created by asim on 08/02/19.
//

#include "LogoutCommand.h"

Message LogoutCommand::execute(Service &service, const Message& message) {
    return service.updateUserState(message);
}