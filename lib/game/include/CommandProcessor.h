//
// Created by vinshit on 29/01/19.
//

#include <utility>
#include <sstream>
#include <unordered_map>
#include "string"
#include "ClientManager.h"
#include "Server.h"
#include "Command.h"

#ifndef WEBSOCKETNETWORKING_COMMANDPROCESSOR_H
#define WEBSOCKETNETWORKING_COMMANDPROCESSOR_H

typedef Message (*function_ptr)(Command*, Message message);

struct InputHandler {
    function_ptr functionPtr;
    std::unique_ptr<Command> argCmd;
};

class CommandProcessor {
    /*
     * Helper Class to avoid manual wiring of key commands to the Game/Account method calls
     */
public:
    using string = std::string;
    using stringstream = std::stringstream;

    CommandProcessor() = default;

    /*
     * Determines if the message is a command prompt by checking if the first word is mapped to a command
     */
    bool isCommand(const Message &message);

    /*
     * Finds the map value from the message's keyword and preforms the function with the message's remaining string
     */
    Message processMessage(const Message &message);

    /*
     * Adds a function to a keyword, the function has to be in format of Message _____(Message message)
     */
    void addCommand(string commandKeyword, function_ptr);

private:
    /*
     * Split a user message text to retrieve the command for processing
     */
    std::pair<string, string> splitCommand(string messageText);

    /*
     * Map a command to a class that executes
     */
    std::unique_ptr<Command> commandFactory(const string& commandKey);

    /*
     *  Holds all the commands added to the map
     */
    std::unordered_map<string, InputHandler> _commands;
};

#endif //WEBSOCKETNETWORKING_COMMANDPROCESSOR_H