//
// Created by vinshit on 13/02/19.
//

#ifndef WEBSOCKETNETWORKING_ABSTRACTCONTROLLER_H
#define WEBSOCKETNETWORKING_ABSTRACTCONTROLLER_H

#include "User.h"
#include "Message.h"

class AbstractController {
    virtual std::vector<Message> respondToMessage(const Message& message) = 0;
};

#endif //WEBSOCKETNETWORKING_ABSTRACTCONTROLLER_H
