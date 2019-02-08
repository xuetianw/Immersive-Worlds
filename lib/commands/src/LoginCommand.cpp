//
// Created by asim on 08/02/19.
//

#include "LoginCommand.h"

Message LoginCommand::execute(Service& service, const Message& message) {
    return service.updateUserState(message);
}