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

    //static sqlite3* database;
    static char* dbName;

    //creates non existent tables
    void createTables();

    static bool openConnection();

    DBUtil();

};

char* DBUtil::dbName = "lib/database/adventure.db";


#endif //WEBSOCKETNETWORKING_DBUTIL_H
