///////////////////////////////////////////////////////////////////////////////////////////////////
// Authors: Asim, Nirag, Vincent
// Created On: January 26, 2019
//
// This file defines the interface for ClientManager.
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
///////////////////////////////////////////////////////////////////////////////////////////////////

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
    bool inProcess;

    User( State state ) : username(""), password(""), state(state), inProcess(false) {}
};

class ClientManager {
public:
    /*
     * desc: Default Constructor
     *
     * Instantiates a ClientManager
     */
    ClientManager() { }

    /*
     * desc: Checks whether a client is currently being served or is in process
     *       Indicates when a client is in the middle of login or other system state
     *
     * connection: a unique client connection id
     *
     * returns true if the client is being processed, false otherwise
     */
    bool isBeingProcessed(uintptr_t connectionId) const;

    /*
     * desc: Prompt user for username and password during login
     *
     * connectionId: a unique client connection id
     * message: request from the client, could be a system command, process message or char message
     *
     * returns the response message to the client
     */
    Message promptLogin(const Message& message);

    /*
     * desc: Checks whether a client is logged in
     *
     * connection: a unique client connection id
     * username: unique username to identify a specific client
     *
     * returns true if the client exists, false otherwise
     */
    bool isLoggedIn(uintptr_t connectionId) const;

    /*
     * desc: This function is called to logout a user
     *
     * connectionId: a unique client connection id
     *
     * returns true if user is able to successfully logout, false otherwise
     */
    bool logoutClient(uintptr_t connectionId);

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

private:
    // A map to store currently registered users
    std::unordered_map<uintptr_t, User > _connectedUserMap;

    // Mock dummy usernames and passwords for testing until database is added
    // TODO: Remove the mock usernames and passwords once database is added
    std::unordered_map<string, string> _userData {
        { "John", "password123*" },
        { "Rex", "admin12345" },
        { "Alex", "myPassword!" },
        { "Garfield", "Pwd15081967@merci" }
    };
};

#endif //WEBSOCKETNETWORKING_CLIENTMANAGER_H
