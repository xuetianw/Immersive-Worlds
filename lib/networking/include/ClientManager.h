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
#include "User.h"

using networking::Connection;
using networking::ConnectionHasher;
using networking::Message;
using std::string;

class ClientManager {
public:
  /*
   * desc: Default Constructor
   *
   * Instantiates a ClientManager
   */
  ClientManager() = default;

  /*
   * desc: Recieves an input from the Server and determines the correct
   * Interaction with the message based on the User's current state.
   *
   * message: the message from the user, ideally before it has been processed by
   * anything else in the server, ! Should not be used if the client is logged
   * in via check from isLoggedIn() !
   *
   * returns: A message to reply back to the user describing its current
   * interaction
   */
  Message handleInput(Message &message);

  /*
   * desc: Checks if the given user submitted information is valid with the
   * given database of Account Information
   *
   * user: The class holding the username and passsword to be submitted
   *
   * returns true the information is correct
   */
  bool isLoginCredentialsCorrect(User &user);

  /*
   * desc: Prompt user for username and password during login
   *
   * message: Message from the user, may contain user parameter to pass in
   *
   * returns the response message to the client
   */
  Message promptLogin(Message &message);

  /*
   * desc: Prompt user for username and password during login
   *
   * message: Message from the user,
   *
   * returns the response message to the client
   */
  Message promptRegister(Message &message);

  /*
   * desc: Checks whether a client is logged in
   *
   * connectionId: a unique client connection id
   *
   * returns true if the client exists, false otherwise
   */
  bool isLoggedIn(const Connection &connection);

  /*
   * desc: This function is called to logoutconst a user
   *
   * connectionId: a unique client connection id
   *
   * returns true if user is able to successfully logout, false otherwise
   */

  Message logoutClient(const Connection &connection);

  /*
   * desc: Registers a client when connected
   *
   * connection: a unique client connection id
   *
   * returns the registered client, null if failed to register
   */

  bool connectClient(const Connection &connection);

  /*
   * desc: Unregisters a client when disconnected
   *
   * connection: a unique client connection id
   *
   * returns the registered client, null if failed to register
   */
  void disconnectClient(const Connection &connection);

  /*
   * desc: Lets the user esscape the process he is currently in
   */
  Message escapeLogin(const Message &message);

private:
  bool userExists(User &user) {
    return _userData.find(user.getUsername()) != _userData.end();
  }

  // A map to store currently registered users
  std::unordered_map<Connection, User, ConnectionHasher> _connectedUserMap;

  // Mock dummy usernames and passwords for testing until database is added
  // TODO: Remove the mock usernames and passwords once database is added
  std::unordered_map<string, string> _userData{
      {"John", "password123*"},
      {"Rex", "admin12345"},
      {"Alex", "myPassword!"},
      {"Garfield", "Pwd15081967@merci"}};
};

#endif // WEBSOCKETNETWORKING_CLIENTMANAGER_H
