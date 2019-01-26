//
// Created by on 25/01/19.
//

#ifndef WEBSOCKETNETWORKING_CLIENTMANAGER_H
#define WEBSOCKETNETWORKING_CLIENTMANAGER_H

#include <unordered_map>

#include "Server.h"

using networking::Connection;
using networking::Message;
using std::string;

enum class State {
    LOGGED_IN,
    CONNECTED,
    LOGGING_IN_USER,
    LOGGING_IN_PWD
};

struct User {
    string username;
    string password;
    State state;

    User( State state ) : username(""), password(""), state(state) {}
};

class ClientManager {
public:
    /*
    * desc: Default Constructor
    * 
    * Instantiates a ClientManager
    */
    ClientManager() {}

    /*
    * desc: Registers a client when connected
    * 
    * connection: a unique client connection id
    * 
    * returns the registered client, null if failed to register
    */
    bool registerClient(uintptr_t connectionId);

    /*
    * desc: Unregisters a client when disconnected
    * 
    * connection: a unique client connection id
    * 
    * returns the registered client, null if failed to register
    */
    bool unregisterClient(uintptr_t connectionId);

    /*
    * desc: Changes the current state of the client
    * 
    * connection: a unique client connection id
    * state: Sate of the client
    * 
    * returns the registered client, null if failed to register
    */
    User changeClientState(uintptr_t connectionId, State state);

    /*
    * desc: allows a client to login
    *
    * connection: a unique client connection id
    * username: unique username to identify a specific client
    * pwd: client password
    *
    * returns User if a client is able to login, null otherwise
    */
    User login(uintptr_t connectionId, string username, string pwd);

    /*
    * desc: Checks whether a client is logged in
    * 
    * connection: a unique client connection id
    * username: unique username to identify a specific client
    * 
    * returns true if the client exists, false otherwise
    */
    bool isLoggedIn(uintptr_t connectionId, string username = "");

    Message promptLogin(uintptr_t connection_id, const Message& message);

private:
    // A map to store currently registered users
    std::unordered_map<uintptr_t, User > connectedUserMap;

    // Mock dummy usernames and passwords for testing until database is added
    std::vector<string> usernames{"John","Rex","Alex","Garfield"};
    std::vector<string> passwords{"gsgfdgfd*","dbgdbvv#","ff","fvbdfsgvfcvbvxcbdfvdfvd"};
};


#endif //WEBSOCKETNETWORKING_CLIENTMANAGER_H
