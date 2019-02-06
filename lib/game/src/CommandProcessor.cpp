//
// Created by vinshit on 31/01/19.
//

#include <utility>
#include "CommandProcessor.h"
#include "YellCommand.h"

std::pair<string,string> CommandProcessor::splitCommand(const string& message_text){
    stringstream msg_stream(message_text);
    string key_command, white_space, remainder;
    msg_stream >> key_command;
    getline(msg_stream >> std::ws, remainder);
    return std::pair<string,string>(key_command, remainder);
}

bool CommandProcessor::isCommand(const Message &message) {
    std::pair commandMessagePair = splitCommand(message.text);
    return _commands.find(commandMessagePair.first) != _commands.end();
}

Message CommandProcessor::processMessage(const Message &message) {
    std::pair commandMessagePair = splitCommand(message.text);
    auto fnDescriptor = _commands.find(commandMessagePair.first);
    InputHandler inHandler;
    string cmd;

    if(fnDescriptor != _commands.end()) {
        cmd = commandMessagePair.first;
        inHandler = fnDescriptor->second;
    } else {
        cmd = "default";
        inHandler = _commands[cmd];
    }

    if(inHandler.argCmd == nullptr) {
        inHandler.argCmd = getCommand(cmd);
    }

    // return fnDescriptor->second.functionPtr(fnDescriptor->second.argCmd);
    return fnDescriptor->second.functionPtr(Message {message.connection, commandMessagePair.second});
}

void CommandProcessor::addCommand(string commandKeyword, function_ptr fnPtr ) {
    _commands.insert(std::make_pair(commandKeyword, InputHandler { fnPtr, nullptr }));
}

Command* CommandProcessor::getCommand(const string &commandKey) {
    if(commandKey == "yell") {
        return new YellCommand();
    }

    return nullptr;
}

