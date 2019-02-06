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

    virtual bool isSubmittingResgistration() { return false; };

    virtual bool isSubittingLoginInfo() { return false; }
};

class LoggingInState : public UserState {
    Message handleInput(User &user, Message &message) override;
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

    void setUsername(const string &username);

    void setPassword(const string &password);

    void set_state(UserState *_state);

    const string &getUsername() const;

    const string &getPassword() const;

    User();

};


#endif //WEBSOCKETNETWORKING_USER_H
