///////////////////////////////////////////////////////////////////////////////////////////////////
// Authors: Asim, Nirag, Vincent
// Created On: January 26, 2019
//
// This file defines the interface for AccountController.
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef WEBSOCKETNETWORKING_CLIENTMANAGER_H
#define WEBSOCKETNETWORKING_CLIENTMANAGER_H

#include "User.h"
#include "AccountService.h"
#include "AbstractController.h"

class AccountController : public AbstractController {
public:
    AccountController() : _accountService() {}

    std::vector<Message> startLogin(const Message& message);

    std::vector<Message> startRegister(const Message& message);

    std::vector<Message> logoutUser(const Message& message);

    std::vector<Message> escapeLogin(const Message& message);

    std::vector<Message> respondToMessage(const Message& message) override;

private:
    AccountService _accountService;
};

#endif // WEBSOCKETNETWORKING_CLIENTMANAGER_H
