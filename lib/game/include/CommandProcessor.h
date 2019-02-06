//
// Created by vinshit on 29/01/19.
//

#include <utility>
#include <sstream>
#include "string"
#include "deque"
#include "ClientManager.h"
#include "Server.h"

#ifndef WEBSOCKETNETWORKING_COMMANDPROCESSOR_H
#define WEBSOCKETNETWORKING_COMMANDPROCESSOR_H

#endif //WEBSOCKETNETWORKING_COMMANDPROCESSOR_H

using networking::Server;

using std::string;
using std::stringstream;

class CommandProcessor {
    /*
     * Helper Class to avoid manual wiring of key commands to the Game/Account method calls
     */
public:
    /*
     * Determines if the message is a command prompt by checking if the first word is mapped to a command
     *
     *
     */
    bool isCommand(const Message &message);

    /*
     * Finds the map value from the message's keyword and preforms the function with the message's remaining string
     */
    Message processMessage(const Message &message);

    /*
     * Adds a function to a keyword, the function has to be in format of Message _____(Message message)
     */
    void addCommand(string commandKeyword, Message (*command_function)(Message));

    /*
     *
     */
    string displayCommands();

    CommandProcessor(){}

private:
    std::unordered_map<string, Message(*)(Message)> _commands;
};