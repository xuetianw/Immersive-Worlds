//
// Created by asim on 07/02/19.
//

#ifndef WEBSOCKETNETWORKING_USERSERVICE_H
#define WEBSOCKETNETWORKING_USERSERVICE_H

#include "AccountStateTransitions.h"
#include "User.h"
#include "Message.h"
#include "DBUtil.h"

class AccountService{
public:
    std::vector<Message> updateUserState(const Message& message, UserEventVariant event);

private:
    AccountStateTransitions<DBUtil> _transitions;
};

#endif //WEBSOCKETNETWORKING_USERSERVICE_H
