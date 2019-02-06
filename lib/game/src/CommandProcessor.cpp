//
// Created by vinshit on 31/01/19.
//

#include <utility>
#include "CommandProcessor.h"

std::pair<string,string> splitCommand(const string& message_text){
    stringstream msg_stream(message_text);
    string key_command, white_space, remainder;
    msg_stream >> key_command;
    getline(msg_stream >> std::ws, remainder);
    return std::pair<string,string>(key_command, remainder);
}

bool CommandProcessor::isCommand(const Message &message) {
    std::pair command_message_pair = splitCommand(message.text);
    return _commands.find(command_message_pair.first) != _commands.end();
}

Message CommandProcessor::processMessage(const Message &message) {
    std::pair command_message_pair = splitCommand(message.text);
    auto command_function = _commands.find(command_message_pair.first);
    if(command_function != _commands.end()){
        return command_function->second(Message{message.connection, command_message_pair.second});
    }
    // TODO: Deal with default/non command functions through here;
    return Message{message.connection, "default"};
}

void CommandProcessor::addCommand(string commandKeyword, Message (*command_function)(Message) ) {
    _commands.insert(std::make_pair(commandKeyword, *command_function));
}

