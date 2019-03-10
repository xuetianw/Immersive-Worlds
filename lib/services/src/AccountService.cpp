//
// Created by asim on 07/02/19.
//

#include <iostream>
#include <variant>

#include "AccountService.h"

constexpr char ESCAPEONLYMESSAGE[] = "You are currently logging in / registering - use /escape to restart";
constexpr char NOESCAPEMESSAGE[] = "You are not logging in / Registering";

void updateUserAccountCommands(User& user) {
    Account &userAccount = user.getAccount();

    if (userAccount.isLoggingIn || userAccount.isRegistering) {
        user.addCommand(ESCAPE);
        user.removeCommand(REGISTER, ESCAPEONLYMESSAGE);
        user.removeCommand(LOGIN, ESCAPEONLYMESSAGE);
    } else if (userAccount.isLoggedIn) {
        user.removeCommand(ESCAPE, NOESCAPEMESSAGE);
        user.addCommand(LOGOUT);
    }
}

std::vector<Message> AccountService::updateUserState(const Message& message, UserEventVariant event) {
    User& user = message.user;
    Account& userAccount = user.getAccount();

    auto newState = std::visit(
            [&](auto& state) -> std::optional<UserStateVariant>
            {
                return transitions(state, event, userAccount, message.text);
            }, userAccount._state);
    userAccount._state = *std::move(newState);

    if(userAccount.isSubmittingRegistration) {
        userAccount.isRegistering = false;
        userAccount.isSubmittingRegistration = false;
        userAccount.isLoggingIn = true; // On sucessful register
        // fill this with db method
    } else if (userAccount.isSubmittingLogin) {
        // fill in with db method
        userAccount.isLoggedIn = true;
        userAccount.isLoggingIn = false;
        userAccount.isSubmittingLogin = false;
    }

    updateUserAccountCommands(user);

    return std::vector<Message>{ Message{message.user, transitions._currentUserResponseMessage} };
}


