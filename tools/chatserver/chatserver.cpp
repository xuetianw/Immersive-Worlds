/////////////////////////////////////////////////////////////////////////////
//                         Single Threaded Networking
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////


#include "Server.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <vector>
#include <unordered_map>

using networking::Server;
using networking::Connection;
using networking::Message;
using namespace std;

enum class State{
    LOGGED_IN,
    CONNECTED,
    LOGGING_IN_USER,
    LOGGING_IN_PWD
};
struct User{
    string username;
    string password;
    State state;

    User( State state) : username(""), password(""),state(state) {}
};

std::vector<string> usernames{"John","Rex","Alex","Garfield"};
std::vector<string> passwords{"gsgfdgfd*","dbgdbvv#","ff","fvbdfsgvfcvbvxcbdfvdfvd"};


std::vector<Connection> clients;
std::unordered_map<uintptr_t, User > connectionMap;


void
onConnect(Connection c) {
    std::cout << "New connection found: " << c.id << "\n";
    clients.push_back(c);
    User user{State::CONNECTED};
    connectionMap.insert(std::make_pair(c.id,user));
}


void
onDisconnect(Connection c) {
    std::cout << "Connection lost: " << c.id << "\n";
    auto eraseBegin = std::remove(std::begin(clients), std::end(clients), c);
    clients.erase(eraseBegin, std::end(clients));
}


std::string
processMessages(Server &server,
                const std::deque<Message> &incoming,
                bool &quit) {
    std::ostringstream result;
    for (auto& message : incoming) {
        auto itr = connectionMap.find(message.connection.id);
        if (message.text == "quit") {
            server.disconnect(message.connection);
        } else if (message.text == "shutdown") {
            std::cout << "Shutting down.\n";
            quit = true;
        }
        else if(message.text =="/escape")
        {
            Message messagePassword;
            messagePassword.text = "Escaped from multi heartbeat process!\n";
            if(itr!=connectionMap.end()){
                itr->second.state = State::CONNECTED;
            }
            messagePassword.connection = message.connection;
            server.sendPrivateMessage(messagePassword);
        }
        else if(itr!=connectionMap.end() && itr->second.state==State::LOGGING_IN_PWD)
        {

            Message messageAutenthicate;

            //password check

            //TODO: add login fail condition, change state to connected
            if (std::find(usernames.begin(), passwords.end(),
                          message.text) == passwords.end()){
                messageAutenthicate.text = "password incorrect, try again\nEnter password\n";
            } else {
                itr->second.state = State::LOGGED_IN;
                messageAutenthicate.text = "*****\nYou are successfully logged in\n";
            }

            messageAutenthicate.connection = message.connection;
            server.sendPrivateMessage(messageAutenthicate);


        }
        else if(itr!=connectionMap.end() && itr->second.state==State::LOGGING_IN_USER) {

            Message messagePassword;

            //TODO: add username validation condition, change state to connected if failure
            if (std::find(usernames.begin(), usernames.end(),
                          message.text) == usernames.end()){
                messagePassword.text = "username not found\nEnter username\n";
            } else {
                itr->second.state = State::LOGGING_IN_PWD;
                messagePassword.text = message.text + "\nEnter password:\n";
            }

            messagePassword.connection = message.connection;
            server.sendPrivateMessage(messagePassword);

        }
        else if(message.text== "/login"){

            Message messageUsername;
            messageUsername.text = "Enter username:\n";

            if(itr!=connectionMap.end()){
                itr->second.state = State::LOGGING_IN_USER;
            }

            messageUsername.connection = message.connection;
            server.sendPrivateMessage(messageUsername);

        }
        else {
            result << message.connection.id << "> " << message.text << "\n";
        }
    }
    return result.str();
}


std::deque<Message>
buildOutgoing(const std::string& log) {
    std::deque<Message> outgoing;
    for (auto client : clients) {
        outgoing.push_back({client, log});
    }
    return outgoing;
}


std::string
getHTTPMessage(const char* htmlLocation) {
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


int
main(int argc, char* argv[]) {
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
        auto log      = processMessages(server, incoming, done);
        auto outgoing = buildOutgoing(log);
        server.send(outgoing);
        sleep(1);
    }

    return 0;
}
