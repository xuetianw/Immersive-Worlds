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
#include "AccountController.h"
#include "CommandProcessor.h"
#include "GameController.h"
#include "User.h"
#include "Message.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <vector>
#include <set>

using networking::Connection;
using networking::ConnectionHasher;
using networking::ServerMessage;
using networking::Server;

using namespace std;

// Manager for handling client connections and authentication
unique_ptr<AccountController> accountController;

// Manage Game actions
unique_ptr<GameController> gameController;

unordered_map<Connection , User, ConnectionHasher> users;

///////////////////////////////////////////////////////////////////////////////////////////////////
void onConnect(Connection &c) {
    std::cout << "New connection found: " << c.id << endl;
    User newUser(c);
    users[c] = newUser;
    accountController->connectClient(users[c]);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void onDisconnect(Connection &c) {
    std::cout << "Connection lost: " << c.id << endl;
    accountController->disconnectClient(users[c]);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
std::deque<ServerMessage> processMessages(CommandProcessor &commandProcessor,
                                    Server &server,
                                    std::deque<ServerMessage> &incoming,
                                    bool &quit) {
    std::deque<ServerMessage> result;
    for (auto &serverMessage : incoming) {
        Message message{users[serverMessage.connection], serverMessage.text};
        if (message.text == "/quit") {
            server.disconnect(message.user.getConnection());
        } else if (message.text == "shutdown") {
            std::cout << "Shutting down.\n";
            quit = true;
        } else if (commandProcessor.isCommand(message)) {
            result.push_back(commandProcessor.processCommand(message).convertToServerMessage());
        } else {
            // If we can put the controllers into a set and lamda 'if( responseToMessage() -> first ) { push_back && break }
            // It would be nice and we could make a serverController and move its commands in there (:

            pair<bool, Message> accountControllerResponse = accountController->respondToMessage(message);
            if (accountControllerResponse.first) {
                result.push_back(accountControllerResponse.second.convertToServerMessage());
            } else {
                pair<bool, Message> gameControllerResponse = gameController->respondToMessage(message);
                result.push_back(gameControllerResponse.second.convertToServerMessage());
            }
        }
    }
    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
CommandProcessor buildCommands() {
    CommandProcessor commandProcessor;


    commandProcessor.addCommand("/whereami", WHEREAMI, [](Message message) { return ::gameController->outputCurrentLocationInfo(message); });
    commandProcessor.addCommand("/logout", LOGOUT, [](Message message) { return ::accountController->logoutUser(message); });
    commandProcessor.addCommand("/login", LOGIN, [](Message message) { return ::accountController->startLogin(message); });
    commandProcessor.addCommand("/register", REGISTER, [](Message message) { return ::accountController->startRegister(message); });
    commandProcessor.addCommand("/escape", ESCAPE, [](Message message) { return ::accountController->escapeLogin(message); });
    commandProcessor.addCommand("/move", MOVE, [](Message message) { return ::gameController->move(message); });
//    commandProcessor.addCommand("/yell", [](ServerMessage message){return ::gameController->yell(message);});

    return move(commandProcessor);
}



///////////////////////////////////////////////////////////////////////////////////////////////////
std::string getHTTPMessage(const char *htmlLocation) {
    if (access(htmlLocation, R_OK) != -1) {
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
int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage:\n  " << argv[0] << " <port> <html response>\n"
                  << "  e.g. " << argv[0] << " 4002 ./webchat.html\n";
        return 1;
    }

    bool done = false;
    unsigned short port = static_cast<unsigned short>(std::stoi(argv[1]));

    accountController = make_unique<AccountController>();
    gameController = make_unique<GameController>();

    accountController->setup_function_pointer([](Message message) {return ::gameController->spawnUserInStartRoom(message.user);});

    Server server{port, getHTTPMessage(argv[2]), onConnect, onDisconnect};
    CommandProcessor commandProcessor = buildCommands();

    //TODO: Improve this loop perhaps

    while (!done) {
        try {
            server.update();
        } catch (std::exception &e) {
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
