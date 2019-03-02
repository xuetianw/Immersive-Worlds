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
    _keywords[std::move(keyword)] = command;
    _commands[std::move(command)] =  fnPtr;
}

Message CommandProcessor::processCommand(const Message &message) {
    std::pair commandMessagePair = splitCommand(message.text);
    User& user = message.user;

    auto keywordIter = _keywords.find(commandMessagePair.first);
    auto commandsIter = keywordIter!=_keywords.end() ? _commands.find(keywordIter->second) : _commands.end();

    if(commandsIter != _commands.end()) {
        if(message.user.canPreformCommand(commandsIter->first)){
            return commandsIter->second(Message {message.user, commandMessagePair.second});
        }
        return Message{message.user, "You cannot preform: " + commandMessagePair.first};
    }

    return Message{message.user, "Attempted Command Not Found."};
}

std::pair<string,string> CommandProcessor::splitCommand(string messageText) {
    boost::trim(messageText);
    stringstream msgStream(messageText);
    string keyCommand, remainder;
    msgStream >> keyCommand;
    getline(msgStream >> std::ws, remainder);
    return std::pair<string,string>(keyCommand, remainder);
}

