//
// Created by fred on 15/03/19.
//


#include "AvatarController.h"
#include <boost/lexical_cast.hpp>


std::vector<Message> AvatarController::registerAvatar(const Message& message) {
    return std::vector<Message>();
}

Message AvatarController::respondToMessage(const Message& message) {
    avatarService.generateAvatarFromAvatarId(ID(), message.text);
    return message;
}

std::atomic<int> AvatarController::nextid() {
    return std::atomic<int>();
}
