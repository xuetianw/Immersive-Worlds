///////////////////////////////////////////////////////////////////////////////////////////////////
// Authors: Asim, Nirag, Vincent
// Created On: January 26, 2019
//
// The file re-implements the chatserver with additional functionality
// to send individual messages to each client, manage clients and process login _commands
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "Server.h"
#include "ClientManager.h"
#include "CommandProcessor.h"
#include "Command.h"
#include "GameController.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <vector>

using networking::Connection;
using networking::Message;
using networking::Server;

using namespace std;

// Manager for handling client connections and authentication
ClientManager clientManager;

// Manage Game actions
GameController gameController;

///////////////////////////////////////////////////////////////////////////////////////////////////
void onConnect(Connection& c) {
    std::cout << "New connection found: " << c.id << endl;
    clientManager.registerClient(c);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void onDisconnect(Connection& c) {
    std::cout << "Connection lost: " << c.id << endl;
    clientManager.unregisterClient(c);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
std::deque<Message> processMessages(CommandProcessor &commandProcessor,
                            Server &server,
                            const std::deque<Message> &incoming,
                            bool &quit) {
    std::deque<Message> result;
    for (auto& message : incoming) {
        if (message.text == "/quit") {
            server.disconnect(message.connection);
        } else if (message.text == "shutdown") {
            std::cout << "Shutting down.\n";
            quit = true;
        } else if (commandProcessor.isCommand(message)){
            result.push_back(commandProcessor.processMessage(message));
        } else if (clientManager.isClientPromptingLogin(message.connection)) {
            result.push_back(clientManager.promptLogin(message));
        } else {
            result.push_back((message));
        }
    }
    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
CommandProcessor buildCommands(){
    CommandProcessor commandProcessor;
    commandProcessor.addCommand("default", [](Command* command, Message message) {return message;});
    commandProcessor.addCommand("/logout", [](Command* command, Message message) {return ::clientManager.logoutClient(message.connection);});
    commandProcessor.addCommand("/login", [](Command* command, Message message){return ::clientManager.promptLogin(message);});
    commandProcessor.addCommand("/escape", [](Command* command, Message message){return ::clientManager.escapeLogin(message);});
    commandProcessor.addCommand("yell", [](Command* command, Message message){return ::gameController.yell(command);});
    commandProcessor.addCommand("/attack", [](Command* command, Message message){return ::gameController.attack(command);});
    return std::move(commandProcessor);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
std::string getHTTPMessage(const char* htmlLocation) {
    if (access(htmlLocation, R_OK ) != -1) {
        std::ifstream infile{htmlLocation};
        return std::string{std::istreambuf_iterator<char>(infile),
                           std::istreambuf_iterator<char>()};

    } else {
        std::cerr << "Unable to open HTML index file:\n"
                  << htmlLocation << "\n";
        std::exit(-1);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage:\n  " << argv[0] << " <port> <html response>\n"
                  << "  e.g. " << argv[0] << " 4002 ./webchat.html\n";
        return 1;
    }

    bool done = false;
    unsigned short port = std::stoi(argv[1]);
    Server server{port, getHTTPMessage(argv[2]), onConnect, onDisconnect};
    CommandProcessor commandProcessor = buildCommands();

    //TODO: Improve this loop perhaps

    while (!done) {
        try {
            server.update();
        } catch (std::exception& e) {
            std::cerr << "Exception from Server update:\n"
                      << " " << e.what() << "\n\n";
            done = true;
        }

        auto incoming = server.receive();
        auto outgoing = processMessages(commandProcessor, server, incoming, done);
        server.send(outgoing);
        sleep(1);
    }

    return 0;
}
