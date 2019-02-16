//
// Created by asim on 07/02/19.
//
#include "GameController.h"

Message GameController::yell(const Message& message) {
    return Message{};
}

pair<bool, Message> GameController::respondToMessage(const Message &message) {
    return {true, Message{message.connection, "Default Message"}};
}