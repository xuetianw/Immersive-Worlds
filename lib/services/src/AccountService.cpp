//
// Created by asim on 07/02/19.
//

#include <iostream>
#include <variant>

#include "AccountService.h"


void updateUserAccountCommands(User& user) {

    Account &userAccount = user.getAccount();

    if (userAccount.isLoggingIn || userAccount.isRegistering) {
        user.addCommand(ESCAPE);
        user.removeCommand(REGISTER);
        user.removeCommand(LOGIN);
    } else if (userAccount.isLoggedIn) {
        user.removeCommand(ESCAPE);
        user.addCommand(LOGOUT);
    }
}

std::vector<Message> AccountService::updateUserState(const Message& message) {

    User& user = message.user;
    Account& userAccount = user.getAccount();

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

    updateUserAccountCommands(user);

    return std::vector<Message>{ Message{message.user, transitions._currentUserResponseMessage} };
}


