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
const string EMPTY_INPUT_PROMPT = "Invalid String - ";

////////////////////HELPERS//////////////////////////////////

//TODO: Add validity checks asides from empty string

bool invalidString(const string &str){
    return str.find_first_not_of(' ') == std::string::npos;
}

Message invalidStringMessage(Message oringalMessage, string prompt){
    return Message{oringalMessage.connection, EMPTY_INPUT_PROMPT+prompt};
}

////////////////////////////////////////////////////////////

class SubmitLoginState : public UserState {
    bool isSubittingLoginInfo() override {return true;}
};

class LoginPasswordState : public UserState {
    Message handleInput(User &user, Message &message) override {
        if (invalidString(message.text)){
            return invalidStringMessage(message, LOGIN_PASSWORD_PROMPT);
        }
        user.setPassword(message.text);
        user.set_state(new SubmitLoginState{});
        return Message{message.connection};
    }

    bool isLoggingIn() { return true; }
};

class LoginUsernameState : public UserState {
    Message handleInput(User &user, Message &message) override {
        if (invalidString(message.text)){
            return invalidStringMessage(message, LOGIN_USERNAME_PROMPT);
        }
        user.setUsername(message.text);
        user.set_state(new LoginPasswordState{});
        return Message{message.connection, LOGIN_PASSWORD_PROMPT};
    }

    bool isLoggingIn() { return true; }
};

class LoggingInState : public UserState {
    Message handleInput(User &user, Message &message) {
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

    bool isLoggingIn() { return true; }
};


class SubmitRegistrationState : public UserState{
    bool isSubmittingResgistration() override { return true;}
};

class ResgisterPasswordState: public UserState{
    Message handleInput(User &user, Message &message) override {
        if (invalidString(message.text)){
            return invalidStringMessage(message, REGISTER_PASSWORD_PROMPT);
        }
        user.setPassword(message.text);
        user.set_state(new SubmitRegistrationState{});
        return Message{message.connection};
    }

    bool isRegistering() override { return true; };
};

class ResgisterLoginState: public UserState{
    Message handleInput(User &user, Message &message) override {
        if (invalidString(message.text)){
            return invalidStringMessage(message, REGISTER_USERNAME_PROMPT);
        }
        user.setUsername(message.text);
        user.set_state(new ResgisterPasswordState);
        return Message{message.connection, REGISTER_PASSWORD_PROMPT};
    }

    bool isRegistering() override { return true; };
};

class RegisteringState: public UserState{
    Message handleInput(User &user, Message &message) override {
        user.set_state(new ResgisterLoginState{});
        return Message{message.connection, REGISTER_USERNAME_PROMPT};
     }

    bool isRegistering() override { return true; };
};

class LoggedOutState : public UserState {
    Message handleInput(User &user, Message &message) override {
    return Message{message.connection, NOT_SIGNED_IN_PROMPT};
  }
};

void User::promptLogin() {
  _state = new LoggingInState{};
}

void User::promptRegistration() {
  _state = new RegisteringState{};
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

bool User::isLoggingIn() {
    return _state->isLoggingIn();
}

bool User::isRegistering() {
    return _state->isRegistering();
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
