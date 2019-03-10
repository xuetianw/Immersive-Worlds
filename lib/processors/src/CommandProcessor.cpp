//
// Created by vinshit on 31/01/19.
//

#include <utility>
#include <boost/algorithm/string.hpp>

#include "CommandProcessor.h"

Message CommandProcessor::getDisabledCommandMessage(string keyword, User& user){
    auto disableEnd = user.getDisabledCommands().end();
    auto disableIter =  user.getDisabledCommands().find(_keywords.at(keyword));

    string returnMessage = disableIter != disableEnd ? disableIter->second : "You cannot preform: " + keyword;

    return Message{user, returnMessage};
}

bool CommandProcessor::isCommand(const Message& message) {
    std::pair commandMessagePair = splitCommand(message.text);
    return _keywords.find(commandMessagePair.first) != _keywords.end();
}

void CommandProcessor::addCommand(string keyword, Command command, function_ptr fnPtr) {
    _keywords[keyword] = command;
    _commands[command] = move(fnPtr);
}

std::vector<Message> CommandProcessor::processCommand(const Message& message) {
    std::pair commandMessagePair = splitCommand(message.text);

    auto keywordIter = _keywords.find(commandMessagePair.first);
    auto commandsIter = keywordIter!=_keywords.end() ? _commands.find(keywordIter->second) : _commands.end();

    if(commandsIter != _commands.end()) {

        auto command = commandsIter->first;
        auto commandFunc = commandsIter->second;

        if(message.user.canPreformCommand(command)){
            return commandFunc(Message {message.user, commandMessagePair.second});
        } else {
            return std::vector<Message>{ getDisabledCommandMessage(commandMessagePair.first, message.user) };
        }
    }

    return std::vector<Message>{ Message{message.user, "Attempted Command Not Found."} };
}

Message CommandProcessor::handleDefaultMessage(const Message& message) {
    Message accountControllerResponse = accountController->respondToMessage(message);

    return message.user.getAccount().isLoggedIn
        ? gameController->respondToMessage(accountControllerResponse)
        : accountControllerResponse;
}

std::pair<string,string> CommandProcessor::splitCommand(string messageText) {
    boost::trim(messageText);
    stringstream msgStream(messageText);
    string keyCommand, remainder;
    msgStream >> keyCommand;
    getline(msgStream >> std::ws, remainder);
    return std::pair<string,string>(keyCommand, remainder);
}

std::vector<Message> CommandProcessor::listAllowedCommands(const Message& message){
    std::stringstream output;
    auto allowedCommands = message.user.getAllowedCommands();

    output << "Allowed Commands: \n";

    for(auto keywordCommandPair : _keywords){

        auto command = keywordCommandPair.second;
        auto keyword = keywordCommandPair.first;
        if(allowedCommands.find(command) != allowedCommands.end()){
            output << keyword << "\n";
        }
    }

    return std::vector<Message>{Message{message.user, output.str()}};
}

void CommandProcessor::buildCommands() {
    addCommand("/whereami", WHEREAMI, [this] (Message message) { return gameController->outputCurrentLocationInfo(message); });
    addCommand("/logout", LOGOUT, [this] (Message message) { return accountController->logoutUser(message); });
    addCommand("/login", LOGIN, [this] (Message message) { return accountController->startLogin(message); });
    addCommand("/register", REGISTER, [this] (Message message) { return accountController->startRegister(message); });
    addCommand("/escape", ESCAPE, [this] (Message message) { return accountController->escapeLogin(message); });
    addCommand("/move", MOVE, [this] (Message message) { return gameController->move(message); });
    addCommand("/help", HELP, [this] (Message message) { return listAllowedCommands(message);});
    addCommand("/minigame", MINIGAME, [this] (Message message) { return gameController->startMiniGame(message); });
    addCommand("/answer", MINIGAME_ANSWER, [this] (Message message) { return gameController->verifyMinigameAnswer(message); });
}

