//
// Created by nirag on 12/02/19.
//

#ifndef WEBSOCKETNETWORKING_DBUTIL_H
#define WEBSOCKETNETWORKING_DBUTIL_H

#include <stdio.h>
#include "string"
#include "sqlite3.h"
using namespace std;

//create all SQL query here

//database Utility class
class DBUtil{

//private:


public:

    static sqlite3* database;
    static char* dbName;

    //creates non existent tables
    static int my_special_callback(void *unused, int count, char **data, char **columns);

    static bool openConnection();

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
