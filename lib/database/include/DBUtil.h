//
// Created by nirag on 12/02/19.
//

#ifndef WEBSOCKETNETWORKING_DBUTIL_H
#define WEBSOCKETNETWORKING_DBUTIL_H

#include <stdio.h>
#include "string"
#include "sqlite3.h"
using namespace std;


//db name
const char* DB_NAME = "adventure.db";

//create all SQL query here
const char* CREATE_USER = "CREATE TABLE IF NOT EXISTS User(id INT PRIMARY KEY, username VARCHAR(20), password VARCHAR(20));";
const char* DROP_USER_TABLE = "DROP TABLE IF EXISTS User;";


//database Utility class
class DBUtil{

//private:


public:

    static sqlite3* database;
    static char* dbName;
    static char* errorMessage;

    //creates non existent tables
    static int callback(void* data, int argc, char** argv, char** azColName);

    static bool openConnection();

    static void closeConnection();

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

    DBUtil();

};


//char* DBUtil::dbName = "lib/database/adventure.db";


#endif //WEBSOCKETNETWORKING_DBUTIL_H
