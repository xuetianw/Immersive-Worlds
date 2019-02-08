//
// Created by asim on 08/02/19.
//

#include <UserState.h>
#include "RegisterCommand.h"

Message RegisterCommand::execute(Service& service, const Message& message) {
    return service.updateUserState(message);
}