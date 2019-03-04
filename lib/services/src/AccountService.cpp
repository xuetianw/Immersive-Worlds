//
// Created by asim on 07/02/19.
//

#include <iostream>
#include <variant>

#include "AccountService.h"

std::vector<Message> AccountService::updateUserState(const Message& message) {

    Account& userAccount = message.user.getAccount();

    auto newState = std::visit(
            [&](auto& state) -> std::optional<UserStateVariant>
            {
                return transitions(state, userAccount, message.text);
            }, userAccount._state);
    userAccount._state = *std::move(newState);

    if(userAccount.isSubmittingRegistration) {
        // fill this with db method
    } else if (userAccount.isSubmittingLogin) {
        // fill in with db method
        userAccount.isLoggedIn = true;
    }

    return std::vector<Message>{ Message{message.user, transitions._currentUserResponseMessage} };
}


