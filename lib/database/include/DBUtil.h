//
// Created by nirag on 12/02/19.
//

#ifndef WEBSOCKETNETWORKING_DBUTIL_H
#define WEBSOCKETNETWORKING_DBUTIL_H

#include <stdio.h>
#include "string"
#include "sqlite3.h"
using namespace std;

//database Utility class
class DBUtil{

//private:


public:

    static sqlite3* database;
    static char* dbName;
    static char* errorMessage;

    //creates non existent tables
    static int callback(void* data, int argc, char** argv, char** azColName);

    static bool registerUser(string username, string password);

    static bool deleteUser(string username);

    static bool userExists(string username);

    static bool openConnection();

    static bool closeConnection();

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


//char* DBUtil::dbName = "lib/database/adventure.db";


#endif //WEBSOCKETNETWORKING_DBUTIL_H
