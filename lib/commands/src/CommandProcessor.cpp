//
// Created by vinshit on 31/01/19.
//

#include <utility>
#include <boost/algorithm/string.hpp>

#include "CommandProcessor.h"

bool CommandProcessor::isCommand(const Message &message) {
    std::pair commandMessagePair = splitCommand(message.text);
    return _keywords.find(commandMessagePair.first) != _keywords.end();
}

void CommandProcessor::addCommand(string keyword, Command command, function_ptr fnPtr) {
    _keywords[keyword] = command;
    _commands[command] = InputHandler { move(fnPtr) };
}

Message CommandProcessor::processCommand(const Message& message) {
    std::pair commandMessagePair = splitCommand(message.text);

    auto keywordIter = _keywords.find(commandMessagePair.first);
    auto commandsIter = keywordIter!=_keywords.end() ? _commands.find(keywordIter->second) : _commands.end();

    if(commandsIter != _commands.end()) {
        if(message.user.canPreformCommand(commandsIter->first)){
            return commandsIter->second.functionPtr(Message {message.user, commandMessagePair.second});
        }
        return Message{message.user, "You cannot preform: " + commandMessagePair.first};
    }

    return Message{message.user, "Attempted Command Not Found."};
}

Message CommandProcessor::handleDefaultMessage(const Message& message) {
    std::pair<bool, Message> accountControllerResponse = accountController->respondToMessage(message);

    return message.user.getAccount().isLoggedIn
        ? gameController->respondToMessage(accountControllerResponse.second).second
        : accountControllerResponse.second;
}

std::pair<string,string> CommandProcessor::splitCommand(string messageText) {
    boost::trim(messageText);
    stringstream msgStream(messageText);
    string keyCommand, remainder;
    msgStream >> keyCommand;
    getline(msgStream >> std::ws, remainder);
    return std::pair<string,string>(keyCommand, remainder);
}

void CommandProcessor::buildCommands() {
    addCommand("/whereami", WHEREAMI, [&] (Message message) { return gameController->outputCurrentLocationInfo(message); });
    addCommand("/logout", LOGOUT, [this] (Message message) { return accountController->logoutUser(message); });
    addCommand("/login", LOGIN, [this] (Message message) { return accountController->startLogin(message); });
    addCommand("/register", REGISTER, [this] (Message message) { return accountController->startRegister(message); });
    addCommand("/escape", ESCAPE, [this] (Message message) { return accountController->escapeLogin(message); });
    addCommand("/move", MOVE, [this] (Message message) { return gameController->move(message); });
}

