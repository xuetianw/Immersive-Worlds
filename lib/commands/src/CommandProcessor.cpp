//
// Created by vinshit on 31/01/19.
//

#include <utility>
#include <boost/algorithm/string.hpp>
#include "CommandProcessor.h"
#include "YellCommand.h"

bool CommandProcessor::isCommand(const Message &message) {
    std::pair commandMessagePair = splitCommand(message.text);
    return _commands.find(commandMessagePair.first) != _commands.end();
}

void CommandProcessor::addCommand(string commandKeyword, function_ptr fnPtr) {
    _commands.insert(std::make_pair(std::move(commandKeyword), InputHandler { fnPtr, commandFactory(commandKeyword, isGameCommand) }));
}

Message CommandProcessor::processCommand(const Message &message, bool isGameCommand) {
    std::pair commandMessagePair = splitCommand(message.text);
    auto commandsIter = _commands.find(commandMessagePair.first);

    if(commandsIter != _commands.end()) {
        return commandsIter->second.functionPtr(commandsIter->second.argCmd.get(), Message {message.connection, commandMessagePair.second});
    }

    // Assumption: default handler is always registered in the commands map
    InputHandler& defaultHandler = isGameCommand ? _commands["gameDefault"] : _commands["clientDefault"];
    return defaultHandler.functionPtr(nullptr, message);
}

std::pair<string,string> CommandProcessor::splitCommand(string messageText) {
    boost::trim(messageText);
    stringstream msgStream(messageText);
    string keyCommand, remainder;
    msgStream >> keyCommand;
    getline(msgStream >> std::ws, remainder);
    return std::pair<string,string>(keyCommand, remainder);
}

std::unique_ptr<Command> CommandProcessor::commandFactory(const string& commandKey) {
    if(commandKey == "yell") {
        return std::make_unique<YellCommand>();
    }

    return nullptr;
}

