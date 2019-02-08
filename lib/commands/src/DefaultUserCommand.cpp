//
// Created by asim on 08/02/19.
//

#include "DefaultUserCommand.h"

networking::Message DefaultUserCommand::execute(Service& service, const Message& message) {
    return service.updateUserState(message);
}