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

// User State during a system command such as '/login'
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
    ClientManager() { }

    /*
     * desc: Checks whether a client is currently being served or is in process.
     *       A system command (/login) requires multiple requests and responses before
     *       a client is logged in.
     *       This function indicates whether a client is responding
     *       to a server prompt or sending a separate request.
     *
     * connectionId: a unique client connection id
     *
     * returns true if the client is responding to a previous server prompt, false otherwise
     */
    bool isClientPromptingLogin(const Connection& connection);

    /*
     * desc: Prompt user for username and password during login
     *
     * connectionId: a unique client connection id
     *
     * returns the response message to the client
     */
    Message promptLogin(const Message &message);

    /*
     * desc: Checks whether a client is logged in
     *
     * connectionId: a unique client connection id
     *
     * returns true if the client exists, false otherwise
     */
    bool isLoggedIn(const Connection& connection);

    /*
     * desc: This function is called to logoutconst a user
     *
     * connectionId: a unique client connection id
     *
     * returns true if user is able to successfully logout, false otherwise
     */
    Message logoutClient(const Connection& connection);

    /*
     * desc: Registers a client when connected
     *
     * connection: a unique client connection id
     *
     * returns the registered client, null if failed to register
     */
    bool registerClient(const Connection& connection);

    /*
     * desc: Unregisters a client when disconnected
     *
     * connection: a unique client connection id
     *
     * returns the registered client, null if failed to register
     */
    void unregisterClient(const Connection& connection);

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
