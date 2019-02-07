//
// Created by vinshit on 05/02/19.
//

#ifndef WEBSOCKETNETWORKING_USER_H
#define WEBSOCKETNETWORKING_USER_H

#include "Server.h"
#include <string>

using networking::Message;
using std::string;

class User;

class UserState;

class User {
  string username;
  string password;
  UserState *_state;

public:
  void promptLogin();

  void setToLoggedIn();

  void promptRegistration();

  Message handleInput(Message &message);

  bool isLoggedIn();

  bool isSubmittingLoginInfo();

  bool isSubmittingRegistration();

  bool isLoggingIn();

  bool isRegistering();

  void setUsername(const string &usernavirtualme);

  void setPassword(const string &password);

  void setState(UserState *state);

  const string &getUsername() const;

  const string &getPassword() const;

  User();
};

#endif // WEBSOCKETNETWORKING_USER_H
