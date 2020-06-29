//
// Created by vinshit on 29/01/19.
//

#ifndef WEBSOCKETNETWORKING_COMMANDPROCESSOR_H
#define WEBSOCKETNETWORKING_COMMANDPROCESSOR_H

#include <utility>
#include <sstream>
#include <unordered_map>
#include <string>

#include "AccountController.h"
#include "GameController.h"
#include "User.h"
#include "Message.h"



using string = std::string;
using stringstream = std::stringstream;

using function_ptr = std::function<std::vector<Message>(Message)> ;

class CommandProcessor {
    /*
     * Helper Class to avoid manual wiring of key commands to the Game/Account method calls
     */
public:
    CommandProcessor() : accountController(std::make_unique<AccountController>()),
                         gameController(std::make_unique<GameController>()){
        buildCommands();
    }

    /*
     * Finds the map value from the message's keyword and preforms the function with the message's remaining string
     */
    std::vector<Message> processCommand(const Message &message);

    /*
     * Adds a function to a keyword, the function has to be in format of ServerMessage _____(ServerMessage message)
     */
    void addCommand(const string& keyword, Command command, function_ptr);

    std::vector<Message> handleDefaultMessage(const Message& message);

    /*
     *  Lists the keywords of the allowed commands to the user
     */
    std::vector<Message> listAvailableCommands(const Message& message);

private:
    /*
     * Split a user message text to retrieve the command for processing
     */
    static std::pair<string, string> splitCommand(string messageText);

    /*
     * Map a command to a function ptr that executes it
     */
    void buildCommands();

    /*
     *  Holds all the commands added to the map
     */
    std::unordered_map<Command , function_ptr> _commands;
    std::unordered_map<string, Command> _keywords;

    // Manager for handling client connections and authentication
    std::unique_ptr<AccountController> accountController;

    // Manage Game actions
    std::unique_ptr<GameController> gameController;
};

#endif //WEBSOCKETNETWORKING_COMMANDPROCESSOR_H