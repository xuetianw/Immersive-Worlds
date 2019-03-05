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
    std::vector<Message> updateUserState(const Message& message);

private:
    StateTransitions transitions;

    // Mock dummy usernames and passwords for testing until database is added
    // TODO: Remove the mock usernames and passwords once database is added
    std::unordered_map<string, string> _userData{
            {"John", "password123*"},
            {"Rex", "admin12345"},
            {"Alex", "myPassword!"},
            {"Garfield", "Pwd15081967@merci"}
    };
};

#endif //WEBSOCKETNETWORKING_USERSERVICE_H
