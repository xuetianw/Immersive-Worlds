//
// Created by asim on 07/02/19.
//

#include <iostream>
#include <variant>

#include "AccountService.h"

std::vector<Message> AccountService::updateUserState(const Message& message, UserEventVariant event) {
    Account& userAccount = message.user.getAccount();

    auto newState = std::visit(
            [&](auto& state) -> std::optional<UserStateVariant>
            {
                return _transitions(state, event, userAccount, message.text);
            }, userAccount._state);
    if(newState) {
        userAccount._state = *std::move(newState);
    }

    return std::vector<Message>{ Message{message.user, _transitions._currentUserResponseMessage} };
}


