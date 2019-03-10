//
// Created by vinshit on 05/02/19.
//

#ifndef WEBSOCKETNETWORKING_USERSTATE_H
#define WEBSOCKETNETWORKING_USERSTATE_H

#include <string>
#include <variant>
#include <optional>

#include "DBUtil.h"

using string = std::string;

///////////////////////////////////////////USER-PROMPTS////////////////////////////////////////////
constexpr char LOGIN_USERNAME_AFTER_REGISTRATION_PROMPT[] = "Account Created! Please enter your new username: ";
constexpr char LOGIN_USERNAME_PROMPT[] = "Please enter your username to login: ";
constexpr char LOGIN_USERNAME_FAILED_PROMPT[] = "Account does not exist!\nPlease enter a valid username: ";
constexpr char LOGIN_PASSWORD_PROMPT[] = "Please enter your password: ";
constexpr char LOGIN_PASSWORD_FAILED_PROMPT[] = "Login Unsuccessful\nPlease enter your username again: ";
constexpr char REGISTER_USERNAME_PROMPT[] = "Please create your username: ";
constexpr char REGISTER_USERNAME_FAILED_PROMPT[] = "Username unavailable!\nPlease enter a different username: ";
constexpr char REGISTER_PASSWORD_PROMPT[] = "Please create your password: ";
constexpr char REGISTER_PASSWORD_FAILED_PROMPT[] = "Invalid Password!\nPlease enter a different password: ";
constexpr char LOGGED_IN_PROMPT[] = "Successfully logged in!\n";
constexpr char LOGGED_OUT_PROMPT[] = "Logged out Successfully!\n";
constexpr char NOT_SIGNED_IN_PROMPT[] = "Please enter login or register!\n";
constexpr char EMPTY_INPUT_PROMPT[] = "Invalid String - \n";

///////////////////////////////////////////USER-STATES/////////////////////////////////////////////
struct RegisterUsernameState {};
struct RegisterPasswordState {};
struct ConnectedState {};
struct LoginUsernameState {};
struct LoginPasswordState {};
struct LoggedInState {};

///////////////////////////////////////////USER-EVENTS/////////////////////////////////////////////
struct RegisterEvent {};
struct LoginEvent {};
struct UpdateEvent {};
struct EscapeEvent {};
struct LogoutEvent {};

//////////////////////////////////////////////STATE-VARIANT////////////////////////////////////////
typedef std::variant<
        RegisterUsernameState,
        RegisterPasswordState,
        ConnectedState,
        LoginUsernameState,
        LoginPasswordState,
        LoggedInState> UserStateVariant;

//////////////////////////////////////////////EVENT-VARIANT////////////////////////////////////////
typedef std::variant<
        RegisterEvent,
        LoginEvent,
        UpdateEvent,
        EscapeEvent,
        LogoutEvent> UserEventVariant;

///////////////////////////////////////////////USER////////////////////////////////////////////////
struct Account {
    std::string _username;
    std::string _password;
    std::string _registerUsername;
    std::string _registerPassword;
    bool isLoggingIn = false;
    bool isSubmittingLogin = false;
    bool isRegistering = false;
    bool isSubmittingRegistration = false;
    bool isLoggedIn = false;
    UserStateVariant _state = ConnectedState {};
};

///////////////////////////////////////STATE-TRANSITIONS///////////////////////////////////////////
struct StateTransitions {
    string _currentUserResponseMessage;

    /////////////////////////////////////////////HELPERS///////////////////////////////////////////
    // TODO: Add validity checks asides from empty string possibly move validation to DBUtility
    bool invalid(const string& str) {
        return str.find_first_not_of(' ') == std::string::npos;
    }

    string getResponseForInvalidInput(const string& prompt) {
        return EMPTY_INPUT_PROMPT + prompt;
    }

    ////////////////////////////////////////////VISITORS///////////////////////////////////////////
    std::optional<UserStateVariant> operator()(ConnectedState& state, RegisterEvent& event, Account& account, const string& message) {

        if(!(account.isLoggingIn || account.isRegistering)){
            _currentUserResponseMessage = NOT_SIGNED_IN_PROMPT;
            return ConnectedState {};
        }
        _currentUserResponseMessage = account.isLoggingIn ? LOGIN_USERNAME_PROMPT : REGISTER_USERNAME_PROMPT;

        if (account.isLoggingIn) {
            return LoginUsernameState{};
        } else {
            return RegisterUsernameState{};
        }
    }

    std::optional<UserStateVariant> operator()(ConnectedState& state, LoginEvent& event, Account& account, const string& message) {
        return std::nullopt;
    }

    std::optional<UserStateVariant> operator()(RegisterUsernameState& state, UpdateEvent& event, Account& account, const string& message) {
        if (invalid(message)) {
            _currentUserResponseMessage = REGISTER_USERNAME_FAILED_PROMPT;
            return RegisterUsernameState {};
        }

        //check if username exists in DB
        account._registerUsername = message;

        //if username already exists, send a message saying username already taken
        if(DBUtil::userExists(account._registerUsername)) {
            _currentUserResponseMessage = REGISTER_USERNAME_FAILED_PROMPT;
            return RegisterUsernameState {};
        }

        _currentUserResponseMessage = REGISTER_PASSWORD_PROMPT;
        return RegisterPasswordState {};
    }

    std::optional<UserStateVariant> operator()(RegisterUsernameState& state, EscapeEvent& event, Account& account, const string& message) {
        return std::nullopt;
    }

    std::optional<UserStateVariant> operator()(RegisterPasswordState& state, UpdateEvent& event, Account& account, const string& message) {
        // TODO: Check is password is valid or not i.e meets the criteria of a password
        if (invalid(message)) {
            _currentUserResponseMessage = getResponseForInvalidInput(REGISTER_PASSWORD_FAILED_PROMPT);
            return RegisterPasswordState {};
        }

        account._registerPassword = message;

        if(!DBUtil::registerUser(account._registerUsername, account._registerPassword)){
            _currentUserResponseMessage = getResponseForInvalidInput(REGISTER_PASSWORD_FAILED_PROMPT);
            return RegisterPasswordState {};
        }

        account.isSubmittingRegistration = true;
        _currentUserResponseMessage = LOGIN_USERNAME_AFTER_REGISTRATION_PROMPT;
        return LoginUsernameState {};
    }

    std::optional<UserStateVariant> operator()(RegisterPasswordState& state, EscapeEvent& event, Account& account, const string& message) {
        return std::nullopt;
    }

    std::optional<UserStateVariant> operator()(LoginUsernameState& state, UpdateEvent& event, Account& account,  const string& message) {
        if(invalid(message)) {
            _currentUserResponseMessage = getResponseForInvalidInput(LOGIN_USERNAME_FAILED_PROMPT);
            return LoginUsernameState {};
        }

        account._username = message;
        _currentUserResponseMessage = LOGIN_PASSWORD_PROMPT;
        return LoginPasswordState {};
    }

    std::optional<UserStateVariant> operator()(LoginUsernameState& state, EscapeEvent& event, Account& account,  const string& message) {
        return std::nullopt;
    }

    std::optional<UserStateVariant> operator()(LoginPasswordState& state, UpdateEvent& event, Account& account, const string& message) {
        if(invalid(message)) {
            _currentUserResponseMessage = getResponseForInvalidInput(LOGIN_PASSWORD_FAILED_PROMPT);
            return LoginUsernameState {};
        }

        account._password = message;

        //verify username and password with DB

        if(DBUtil::isValidCredential(account._username, account._password)){
            account.isSubmittingLogin = true;
            _currentUserResponseMessage = LOGGED_IN_PROMPT;
            return LoggedInState {};
        } else{
            _currentUserResponseMessage = getResponseForInvalidInput(LOGIN_PASSWORD_FAILED_PROMPT);
            return LoginUsernameState {};
        }

    }

    std::optional<UserStateVariant> operator()(LoginPasswordState& state, EscapeEvent& event, Account& account, const string& message) {
        return std::nullopt;
    }

    std::optional<UserStateVariant> operator()(LoggedInState& state, LogoutEvent& event, Account& account, const string& message) {
        account._username = "";
        account._password = "";
        _currentUserResponseMessage = LOGGED_OUT_PROMPT;
        return ConnectedState {};
    }

    template<typename State, typename Event>
    std::optional<UserStateVariant> operator()(State& state, Event& event, Account& account, const string& message) {
        return std::nullopt;
    }
};

#endif // WEBSOCKETNETWORKING_USERSTATE_H
