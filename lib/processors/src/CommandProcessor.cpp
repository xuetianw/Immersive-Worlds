//
// Created by vinshit on 31/01/19.
//

#include <utility>
#include <boost/algorithm/string.hpp>

#include "CommandProcessor.h"

void CommandProcessor::addCommand(const string& keyword, Command command, function_ptr fnPtr) {
    _keywords[keyword] = command;
    _commands[command] = move(fnPtr);
}

std::vector<Message> CommandProcessor::processCommand(const Message& message) {
    const std::pair commandMessagePair = splitCommand(message.text);

    auto keywordIter = _keywords.find(commandMessagePair.first);
    auto commandsIter = keywordIter != _keywords.end() ? _commands.find(keywordIter->second) : _commands.end();

    if(commandsIter != _commands.end()) {

        if(message.user.canPreformCommand(commandsIter->first)) {
            return commandsIter->second(Message {message.user, commandMessagePair.second});
        } else { return std::vector<Message>{ Message {message.user, INVALID_INPUT_PROMPT} };}
    }
    // when it is a valid command
    return handleDefaultMessage(message);
}

std::vector<Message> CommandProcessor::handleDefaultMessage(const Message& message) {
    // Default Game handler when the user is logged in
    if(message.user.getAccount().isLoggedIn) {
        return gameController->respondToMessage(message);
    }
    // if the user is not logged in yet
    std::vector<Message> accountControllerResponse = accountController->respondToMessage(message);
    bool loggedInStatusChanged = accountControllerResponse.front().user.getAccount().isLoggedIn;
    if(loggedInStatusChanged) {
        return gameController->onLogin(accountControllerResponse.front());
    }

    return accountControllerResponse;
}


std::vector<Message> CommandProcessor::listAvailableCommands(const Message& message) {
    std::stringstream output;
    auto allowedCommands = message.user.getAllowedCommands();

    output << "Allowed Commands: \n";

    for(auto& keywordCommandPair : _keywords) {
        auto command = keywordCommandPair.second;
        auto keyword = keywordCommandPair.first;
        if(allowedCommands.find(command) != allowedCommands.end()) {
            output << keyword << "\n";
        }
    }

    return std::vector<Message>{Message{message.user, output.str()}};
}


//Private


std::pair<string,string> CommandProcessor::splitCommand(string messageText) {
    boost::trim(messageText);
    stringstream msgStream(messageText);
    string keyCommand, remainder;
    msgStream >> keyCommand;
    getline(msgStream >> std::ws, remainder);
    return std::pair<string, string>(keyCommand, remainder);
}

void CommandProcessor::buildCommands() {
    addCommand("/look", LOOK, [this](const Message& message) { return gameController->outputCurrentLocationInfo(message); });
    addCommand("/logout", LOGOUT, [this] (const Message& message) { return accountController->logoutUser(message); });
    addCommand("/login", LOGIN, [this] (const Message& message) { return accountController->startLogin(message); });
    addCommand("/register", REGISTER, [this] (const Message& message) { return accountController->startRegister(message); });
    addCommand("/escape", ESCAPE, [this] (const Message& message) { return accountController->escapeLogin(message); });
    addCommand("/move", MOVE, [this] (const Message& message) { return gameController->move(message); });
    addCommand("/say", SAY, [this] (const Message& message) { return gameController->say(message); });
    addCommand("/yell", YELL, [this] (const Message& message) { return gameController->yell(message); });
    addCommand("/tell", TELL, [this] (const Message& message) { return gameController->tell(message); });
    addCommand("/minigame", MINIGAME, [this] (const Message& message) { return gameController->startMiniGame(message); });
    addCommand("/answer", MINIGAME_ANSWER, [this] (const Message& message) { return gameController->verifyMinigameAnswer(message); });
    addCommand("/attack", ATTACK, [this] (const Message& message) { return gameController->attackNPC(message);});
    addCommand("/flee", FLEE, [this] (const Message& message) { return gameController->fleeCombat(message);});
    addCommand("/nextRound", MINIGAME_NEXTROUND, [this] (const Message& message) { return gameController->nextRound(message); });
    addCommand("/help", HELP, [this] (const Message& message) { return listAvailableCommands(message);});
    addCommand("/directions", DIRECTIONS, [this](const Message& message) { return gameController->listDirections(message); });
    addCommand("/avatar", AVATAR_INFO, [this] (const Message& message) { return gameController->displayAvatarInfo(message);});
    addCommand("/swap", SWAP_AVATAR, [this] (const Message& message) { return gameController->swapAvatar(message);});
    addCommand("/confuse", CONFUSE, [this] (const Message& message) { return gameController->confuseAvatar(message);});
    addCommand("/unconfuse", UNCONFUSE, [this] (const Message& message) { return gameController->unconfuseAvatar(message);});
    addCommand("/look_avatar", LOOK_AVATAR, [this] (const Message& message) { return gameController->outputAvatarsInCurrentRoom(message);});
}

