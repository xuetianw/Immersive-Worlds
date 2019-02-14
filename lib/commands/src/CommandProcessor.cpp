//
// Created by vinshit on 31/01/19.
//

#include <utility>
#include <boost/algorithm/string.hpp>
#include "CommandProcessor.h"

bool CommandProcessor::isCommand(const Message &message) {
    std::pair commandMessagePair = splitCommand(message.text);
    return _commands.find(commandMessagePair.first) != _commands.end();
}

void CommandProcessor::addCommand(string commandKeyword, function_ptr fnPtr) {
    _commands[std::move(commandKeyword)] = InputHandler { fnPtr };
}

Message CommandProcessor::processCommand(const Message &message) {
    std::pair commandMessagePair = splitCommand(message.text);
    auto commandsIter = _commands.find(commandMessagePair.first);

    if(commandsIter != _commands.end()) {
        return commandsIter->second.functionPtr(Message {message.connection, commandMessagePair.second});
    }

    return Message{message.connection, "Internal error: isCommand Check Failed!"};
}

std::pair<string,string> CommandProcessor::splitCommand(string messageText) {
    boost::trim(messageText);
    stringstream msgStream(messageText);
    string keyCommand, remainder;
    msgStream >> keyCommand;
    getline(msgStream >> std::ws, remainder);
    return std::pair<string,string>(keyCommand, remainder);
}

