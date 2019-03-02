//
// Created by asim on 07/02/19.
//

#include <iostream>
#include <variant>
#include "AccountService.h"

void AccountService::connectUser(User &user) {
    user.setAccount(Account{});
    user.setAllowedCommands({LOGIN, REGISTER});
}

//On the Account side, disconnecting a User from its account seems identical to connecting to one
// i.e making the User have an blank account structure

void AccountService::disconnectUser(User &user) {
    //do some sort of save here perhaps for the other Service
    user.setAccount(Account{});
    user.setAllowedCommands({LOGIN, REGISTER});
}

Message AccountService::updateUserState(Message &message) {

    Account& userAccount = message.user.getAccount();

    auto newState = std::visit(
            [&](auto& state) -> std::optional<UserStateVariant>
            {
                return transitions(state, userAccount, message.text);
            }, userAccount._state);
    userAccount._state = *std::move(newState);

    if(userAccount.isSubmittingRegistration){
        // fill this with db method
    } else if (userAccount.isSubmittingLogin){
        // fill in with db method
        userAccount.isLoggedIn = true;
    }

    return Message{message.user, transitions._currentUserResponseMessage};
}


