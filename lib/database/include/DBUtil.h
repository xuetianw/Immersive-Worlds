//
// Created by nirag on 12/02/19.
//

#ifndef WEBSOCKETNETWORKING_DBUTIL_H
#define WEBSOCKETNETWORKING_DBUTIL_H

#include <stdio.h>
#include "iostream";
#include "sqlite3.h"
using namespace std;

//database Utility class
class DBUtil{

private:
    static sqlite3* database;
    static char* dbName;

public:
    //creates non existent tables
    void createTables();

    bool openConnection();

};


#endif //WEBSOCKETNETWORKING_DBUTIL_H
