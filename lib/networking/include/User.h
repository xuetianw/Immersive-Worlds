//
// Created by vinshit on 05/02/19.
//

#ifndef WEBSOCKETNETWORKING_USER_H
#define WEBSOCKETNETWORKING_USER_H

#include <string>
#include "Server.h"

using networking::Message;
using std::string;

class User;

class UserState {
public:
    virtual Message handleInput(User &user, Message &message){
        return message;
    }

    virtual bool isLoggedInState() { return false; }

    virtual bool isSubmittingRegistration() { return false; };

    virtual bool isSubmittingLoginInfo() { return false; }

    virtual bool isLoggingIn(){ return false; };

    virtual bool isRegistering(){ return false; };
};

class LoggedInState : public UserState {
    Message handleInput(User &user, Message &message) override{
        return Message{};
    };

    bool isLoggedInState() override { return true; }
};

class User {
    string username;
    string password;
    UserState *_state;
public:

    void promptLogin();

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


#endif //WEBSOCKETNETWORKING_USER_H
