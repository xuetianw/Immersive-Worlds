//
// Created by fred on 15/03/19.
//

#ifndef WEBSOCKETNETWORKING_AVATARCONTROLLER_H
#define WEBSOCKETNETWORKING_AVATARCONTROLLER_H

#include "AvatarService.h"
#include "AbstractController.h"

class AvatarController : AbstractController {
public:

    std::vector<Message> registerAvatar(const Message& message);

    Message respondToMessage(const Message& message) override;

    std::vector<Message> displayAvatarInfo(const Message& message);


private:
    AvatarService avatarService;
};

#endif //WEBSOCKETNETWORKING_AVATARCONTROLLER_H
