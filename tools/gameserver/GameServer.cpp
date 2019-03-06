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

#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <vector>
#include <set>

#include "Server.h"
#include "CommandProcessor.h"
#include "User.h"
#include "Message.h"

using networking::Connection;
using networking::ConnectionHash;
using networking::ServerMessage;
using networking::Server;

using namespace std;

// Manager for handling client commands
unique_ptr<CommandProcessor> commandProcessor;

// Store User State
unordered_map<Connection, User, ConnectionHash> users;

///////////////////////////////////////////////////////////////////////////////////////////////////
void onConnect(Connection &c) {
    std::cout << "New connection found: " << c.id << endl;
    users[c] = User {c};
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void onDisconnect(Connection &c) {
    std::cout << "Connection lost: " << c.id << endl;
    users.erase(c);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
std::deque<ServerMessage> processMessages(CommandProcessor& commandProcessor,
                                    Server& server,
                                    const std::deque<ServerMessage>& incoming,
                                    bool& quit) {
    std::deque<ServerMessage> result;
    for (auto &serverMessage : incoming) {
        Message message{users[serverMessage.connection], serverMessage.text};
        if (message.text == "/quit") {
            server.disconnect(message.user.getConnection());
        } else if (message.text == "shutdown") {
            std::cout << "Shutting down.\n";
            quit = true;
        } else if (commandProcessor.isCommand(message)) {
            std::vector<Message> returnedMessages = commandProcessor.processCommand(message);
            for (auto& message: returnedMessages){
                result.push_back(message.convertToServerMessage());
            }

        } else {
            result.push_back(commandProcessor.handleDefaultMessage(message).convertToServerMessage());
        }
    }

    return result;
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

    commandProcessor = make_unique<CommandProcessor>();
    Server server{port, getHTTPMessage(argv[2]), onConnect, onDisconnect};

    while (!done) {
        try {
            server.update();
        } catch (std::exception &e) {
            std::cerr << "Exception from Server update:\n"
                      << " " << e.what() << "\n\n";
            done = true;
        }

        auto incoming = server.receive();
        auto outgoing = processMessages(*commandProcessor, server, incoming, done);
        server.send(outgoing);
        sleep(1);
    }

    return 0;
}
