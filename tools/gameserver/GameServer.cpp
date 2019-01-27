///////////////////////////////////////////////////////////////////////////////////////////////////
// Authors: Asim, Nirag, Vincent
// Created On: January 26, 2019
//
// The file re-implements the chatserver with additional functionality
// to send individual messages to each client, manage clients and process login commands
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "Server.h"
#include "ClientManager.h"

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

///////////////////////////////////////////////////////////////////////////////////////////////////
void onConnect(Connection c) {
    std::cout << "New connection found: " << c.id << endl;
    clientManager.registerClient(c.id);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void onDisconnect(Connection c) {
    std::cout << "Connection lost: " << c.id << endl;
    clientManager.unregisterClient(c.id);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
std::deque<Message> processMessages(Server &server,
                            const std::deque<Message> &incoming,
                            bool &quit) {
    std::ostringstream result;
    for (auto& message : incoming) {
        if (message.text == "quit") {
            server.disconnect(message.connection);
        } else if (message.text == "shutdown") {
            std::cout << "Shutting down.\n";
            quit = true;
        } else if(message.text == "/logout") {
            string response;
            if(clientManager.isLoggedIn(message.connection.id)) {
                clientManager.logoutClient(message.connection.id);
                response = "User successfully logged out!\n";
            } else {
                response = "User not logged in!\n";
            }
        } else if(message.text == "/login" || clientManager.isBeingProcessed(message.connection.id)) {
            Message responseMessage = clientManager.promptLogin(message);
            server.sendSingleMessage(responseMessage);
        } else {
            result << message.connection.id << "> " << message.text << endl;
        }
    }

    return std::deque<Message>();
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

    while (!done) {
        try {
            server.update();
        } catch (std::exception& e) {
            std::cerr << "Exception from Server update:\n"
                      << " " << e.what() << "\n\n";
            done = true;
        }

        auto incoming = server.receive();
        auto outgoing = processMessages(server, incoming, done);
        server.send(outgoing);
        sleep(1);
    }

    return 0;
}
