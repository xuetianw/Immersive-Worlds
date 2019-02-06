//
// Created by vinshit on 05/02/19.
//

#include "User.h"
#include <sstream>

using std::stringstream;

const string LOGIN_USERNAME_PROMPT = "Please enter your username:";
const string LOGIN_PASSWORD_PROMPT = "Please enter your password:";
const string REGISTER_USERNAME_PROMPT = "Please create your username:";
const string REGISTER_PASSWORD_PROMPT = "Please create your password:";
const string NOT_SIGNED_IN_PROMPT = "Please enter login or register!";

class SubmitLoginState : public UserState {
    bool isSubittingLoginInfo() override {return true;}
};

class LoginPasswordState : public UserState {
    Message handleInput(User &user, Message &message) override {
        stringstream response;
        user.setPassword(message.text);
        user.set_state(new SubmitLoginState{});
        return Message{message.connection};
    }
};

class LoginUsernameState : public UserState {
    Message handleInput(User &user, Message &message) override {
        user.setUsername(message.text);
        user.set_state(new LoginPasswordState{});
        return Message{message.connection, LOGIN_PASSWORD_PROMPT};
    }
};

Message LoggingInState::handleInput(User &user, Message &message) {
    stringstream response;
    if (message.text.empty()) {
        user.set_state(new LoginUsernameState{});
        return Message{message.connection, LOGIN_USERNAME_PROMPT};
    } else {
        user.setUsername(message.text);
        user.set_state(new LoginPasswordState{});
        return Message{message.connection, LOGIN_PASSWORD_PROMPT};
    }
}

class SubmitRegistrationState : public UserState{
    bool isSubmittingResgistration() override { return true;}
};

class ResgisterPasswordState: public UserState{
    Message handleInput(User &user, Message &message) override {
        user.setPassword(message.text);
        user.set_state(new SubmitRegistrationState{});
        return Message{message.connection, REGISTER_PASSWORD_PROMPT};
    }
};

class ResgisterLoginState: public UserState{
    Message handleInput(User &user, Message &message) override {
        user.setUsername(message.text);
        user.set_state(new ResgisterPasswordState);
        return Message{message.connection, REGISTER_PASSWORD_PROMPT};
    }
};

class RegisteringState: public UserState{
    Message handleInput(User &user, Message &message) override {
        user.set_state(new ResgisterLoginState{});
        return Message{message.connection, REGISTER_USERNAME_PROMPT};
     }
};

class LoggedOutState : public UserState {
    Message handleInput(User &user, Message &message) override {
    return Message{message.connection, NOT_SIGNED_IN_PROMPT};
  }
};

void User::promptLogin() {
  _state = new LoggingInState;
}

void User::promptRegistration() {
  _state = new RegisteringState;
}

Message User::handleInput(Message &message) {
  return _state->handleInput(*this, message);
}

bool User::isLoggedIn() {
  return _state->isLoggedInState();
}

bool User::isSubmittingLoginInfo(){
  return _state->isSubittingLoginInfo();
}

bool User::isSubmittingRegistration(){
  return _state->isSubmittingResgistration();
}

void User::setUsername(const string &username) {
  User::username = username;
}

void User::setPassword(const string &password) {
  User::password = password;
}

void User::set_state(UserState *_state) {
  User::_state = _state;
}

User::User() : username(""), password(""), _state(new LoggedOutState{}) {}

const string &User::getUsername() const {
  return username;
}

const string &User::getPassword() const {
  return password;
}
