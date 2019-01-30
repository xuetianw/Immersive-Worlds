///////////////////////////////////////////////////////////////////////////////////////////////////
// Authors: Asim, Nirag
// Created On: January 25, 2019
///////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef WEBSOCKETNETWORKING_UTILITY_H
#define WEBSOCKETNETWORKING_UTILITY_H

#include <string>

#include "Server.h"

using networking::Server;
using networking::Message;
using namespace std;

class DBUtility {
public:
    // Default Constructor
    DBUtility() {}

    // A stub to validate if a user exists in the db
    static bool validateUserExists();

    // A stub to validate password
    static bool validatePassword();

    // A stub to validate user name
    static bool validateUserName();

    // A stub to find a user
    static void findUserByUserName(string username);

    // A stub to find the room from the db
    static void findRoomById(string id);
private:

};

#endif