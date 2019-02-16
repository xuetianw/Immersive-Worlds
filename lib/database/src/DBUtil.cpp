//
// Created by nirag on 12/02/19.
//
#include <DBUtil.h>

#include "DBUtil.h"
#include "sqlite3.h"

//declaring static field outside header file
sqlite3* DBUtil::database;
char* DBUtil::dbName = const_cast<char *>(DB_NAME);
char* DBUtil::errorMessage;

bool DBUtil::openConnection() {

    //DBUtil::dbName = "../adventure.db";

    //use DB path
    int status = sqlite3_open_v2("adventure.db",& (DBUtil::database), SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE , NULL);


    if(status!=SQLITE_OK){
        //error handling

        return false;
    }

    return true;
}

bool DBUtil::createTables() {


    //for now we keep the tables to retain data
    DBUtil::dropTables();


    int status = sqlite3_exec( DBUtil::database,"CREATE TABLE IF NOT EXISTS User(id INT PRIMARY KEY, username VARCHAR(20), password VARCHAR(20));",
            NULL, NULL , &DBUtil::errorMessage );

    if(status!=0){
        //error handling

        return false;
    }

    DBUtil::closeConnection();

    return true;

}

bool DBUtil::dropTables() {


    int status = sqlite3_exec( DBUtil::database,"DROP TABLE IF EXISTS User;",
                                            NULL, NULL , &DBUtil::errorMessage );

    if(status!=0){
        return false;
    }
    return true;
}

/*
 * Arguments:
 *
 *   data - pointer
 *   argc - The number of columns in the result set
 *   data - The row's data
 *   azColName - The column names
 */
int DBUtil::callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);

    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}

//implement callbacak functionss to retrieve data from DB


void DBUtil::closeConnection() {

    sqlite3_close(DBUtil::database);
}


DBUtil::DBUtil() {

}
