//
// Created by asim on 07/02/19.
//

#ifndef WEBSOCKETNETWORKING_USERSERVICE_H
#define WEBSOCKETNETWORKING_USERSERVICE_H

#include "UserState.h"
#include "User.h"
#include "Message.h"

class AccountService{
public:
    std::vector<Message> updateUserState(const Message& message, UserEventVariant event);

private:
    StateTransitions _transitions;
};

#endif //WEBSOCKETNETWORKING_USERSERVICE_H
