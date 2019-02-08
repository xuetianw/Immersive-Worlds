//
// Created by vinshit on 05/02/19.
//

#ifndef WEBSOCKETNETWORKING_USER_H
#define WEBSOCKETNETWORKING_USER_H

#include "Server.h"
#include <string>
#include <variant>

using Message = networking::Message;
using string = std::string;

///////////////////////////////////////////USER-PROMPTS////////////////////////////////////////////
const string LOGIN_USERNAME_AFTER_REGISTRATION_PROMPT = "Account Created! Please re-enter your username: ";
const string LOGIN_USERNAME_PROMPT = "Please enter your username to login: ";
const string LOGIN_USERNAME_FAILED_PROMPT = "User does not exist!\nPlease enter a valid username: ";
const string LOGIN_PASSWORD_PROMPT = "Please enter your password: ";
const string LOGIN_PASSWORD_FAILED_PROMPT = "Login Unsuccessful\nPlease enter your username again: ";
const string REGISTER_USERNAME_PROMPT = "Please create your username: ";
const string REGISTER_USERNAME_FAILED_PROMPT = "Username unavailable!\nPlease enter a different username: ";
const string REGISTER_PASSWORD_PROMPT = "Please create your password: ";
const string REGISTER_PASSWORD_FAILED_PROMPT = "Invalid Password!\nPlease enter a different password: ";
const string LOGGED_IN_PROMPT = "Successfully logged in!\n";
const string LOGGED_OUT_PROMPT = "Logged out Successfully!\n";
const string NOT_SIGNED_IN_PROMPT = "Please enter login or register!\n";
const string EMPTY_INPUT_PROMPT = "Invalid String - \n";

//////////////////////////////////////////////HELPERS//////////////////////////////////////////////
// TODO: Add validity checks asides from empty string possibly move validation to DBUtility
bool invalid(const string &str) {
    return str.find_first_not_of(' ') == std::string::npos;
}

Message getResponseForInvalidInput(Message message, const string &prompt) {
    return Message{message.connection, EMPTY_INPUT_PROMPT + prompt};
}

///////////////////////////////////////////USER-STATES/////////////////////////////////////////////
struct UnRegisteredState {};
struct RegisterUsernameState {};
struct RegisterPasswordState {};
struct ConnectedState {};
struct LoginUsernameState {};
struct LoginPasswordState {};
struct LoggedInState {};

//////////////////////////////////////////////STATE-VARIANT////////////////////////////////////////
typedef std::variant<
        UnRegisteredState,
        RegisterUsernameState,
        RegisterPasswordState,
        ConnectedState,
        LoginUsernameState,
        LoginPasswordState,
        LoggedInState> UserStateVariant;

///////////////////////////////////////////////USER////////////////////////////////////////////////
struct User {
    std::string _username;
    std::string _password;
    UserStateVariant _state = ConnectedState {};
};

///////////////////////////////////////STATE-TRANSITIONS///////////////////////////////////////////
struct StateTransitions {
    Message operator()(UnRegisteredState& state, User& user, const Message& message) {
        user._state = RegisterUsernameState {};
        return Message { message.connection, REGISTER_USERNAME_PROMPT };
    }

    Message operator()(RegisterUsernameState& state, User& user, const Message& message) {
        // TODO: Add the username to persistent storage for future identification
        if (invalid(message.text)) {
            return getResponseForInvalidInput(message, REGISTER_USERNAME_FAILED_PROMPT);
        }

        user._state = RegisterPasswordState {};
        return Message{message.connection, REGISTER_PASSWORD_PROMPT};
    }

    Message operator()(RegisterPasswordState& state, User& user, const Message& message) {
        // TODO: Add the password to persistent storage for future authentication
        if (invalid(message.text)) {
            return getResponseForInvalidInput(message, REGISTER_PASSWORD_FAILED_PROMPT);
        }

        user._state = LoginUsernameState {};
        return Message{message.connection, LOGIN_USERNAME_AFTER_REGISTRATION_PROMPT};
    }

    Message operator()(ConnectedState& state, User& user, const Message& message) {
        user._state = LoginUsernameState{};
        return Message{message.connection, LOGIN_USERNAME_PROMPT};
    }

    Message operator()(LoginUsernameState& state, User& user, const Message& message) {
        // TODO: Verify username
        if(invalid(message.text)) {
            return getResponseForInvalidInput(message, LOGIN_USERNAME_FAILED_PROMPT);
        }

        user._username = message.text;
        user._state = LoginPasswordState {};
        return Message {message.connection, LOGIN_PASSWORD_PROMPT};
    }

    Message operator()(LoginPasswordState& state, User& user, const Message& message) {
        if(invalid(message.text)) {
            user._state = LoginUsernameState {};
            return getResponseForInvalidInput(message, LOGIN_PASSWORD_FAILED_PROMPT);
        }

        user._password = message.text;
        user._state = LoggedInState {};
        return Message {message.connection, LOGGED_IN_PROMPT};
    }

    Message operator()(LoggedInState& state, User& user, const Message& message) {
        user._username = "";
        user._password = "";
        user._state = ConnectedState {};
        return Message{message.connection, LOGGED_OUT_PROMPT};
    }
};

#endif // WEBSOCKETNETWORKING_USER_H
