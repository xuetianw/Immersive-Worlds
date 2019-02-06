//
// Created by vinshit on 31/01/19.
//

#include <utility>
#include "CommandProcessor.h"

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
    if(fnDescriptor != _commands.end()) {
        return fnDescriptor->second.functionPtr(Message{message.connection, commandMessagePair.second});
    }
    // TODO: Deal with default/non command functions through here;
    return Message{message.connection, "default"};
}

void CommandProcessor::addCommand(string commandKeyword, function_ptr fnPtr ) {
    _commands.insert(std::make_pair(commandKeyword, InputHandler { fnPtr, nullptr }));
}

