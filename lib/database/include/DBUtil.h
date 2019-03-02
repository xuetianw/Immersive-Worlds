//
// Created by nirag on 12/02/19.
//

#ifndef WEBSOCKETNETWORKING_DBUTIL_H
#define WEBSOCKETNETWORKING_DBUTIL_H

#include <stdio.h>
#include <unordered_map>
#include "string"
#include "sqlite3.h"
using namespace std;

//database Utility class
class DBUtil{
public:

    static sqlite3* database;
    static char* dbName;
    static char* errorMessage;

    //static functions to store, retrieve and delete data and tables

    /*
     * Register a user using username and password
     */
    static bool registerUser(const string& username, const string& password);

    /*
     * Deletes a User using their username
     */
    static bool deleteUser(const string& username);

    /*
     * Checks for the existence of a single User
     */
    static bool userExists(const string& username);

    /*
     * acquires all Users on server bootup and populates datastructure
     */
    static bool getAllUsers();

    /*
     * open connection to sqlite database
     */
    static bool openConnection();

    /*
     * close connection to sqlite database
     */
    static bool closeConnection();


private:
    /*
     * function to create new tables if need be
     */
    static bool createTables();

    /*
     *
     * Function to drop all pre existing tables
     * Modify if required
     */
    static bool dropTables();
};


#endif //WEBSOCKETNETWORKING_DBUTIL_H
