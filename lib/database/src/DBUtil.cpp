//
// Created by nirag on 12/02/19.
//
#include "DBUtil.h"
#include "SqlStatements.h"

#include "DBUtil.h"
#include "sqlite3.h"

//declaring static field outside header file
sqlite3* DBUtil::database;
char* DBUtil::dbName;
char* DBUtil::errorMessage;

bool DBUtil::openConnection() {

    //use DB path
    int status = sqlite3_open_v2("adventure.db", &(DBUtil::database), SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE , NULL);


    if(status!=SQLITE_OK){
        //error handling

        return false;
    }

    return true;
}

bool DBUtil::createTables() {

    SqlStatements::prepareSQLStatements();

    //for now we keep the tables to retain data
    DBUtil::dropTables();


    int status = sqlite3_step(SqlStatements::createUserTableStmt);

    if(status!=SQLITE_DONE){
        //error handling

        return false;
    }


    return true;

}

bool DBUtil::registerUser(string username, string password) {


    SqlStatements::registerUser(username, password);
    int status = sqlite3_step(SqlStatements::registerUserStmt);

    if(status!=SQLITE_DONE){
        //error handling

        return false;
    }


    return true;

}

bool DBUtil::deleteUser(string username) {

    string sqlStatement = "DELETE FROM User WHERE username ='" + username + "';";

    int status = sqlite3_exec( DBUtil::database, sqlStatement.c_str() ,
                               NULL, NULL , &DBUtil::errorMessage );

    if(status!=0){
        return false;
    }
    return true;


}

bool DBUtil::dropTables() {


    int status = sqlite3_exec( DBUtil::database,"DROP TABLE IF EXISTS User;",
                                            NULL, NULL , &DBUtil::errorMessage );

    if(status!=0)
        return false;

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


bool DBUtil::closeConnection() {

    int status = sqlite3_close_v2(DBUtil::database);

    if(status!=SQLITE_OK)
        return false;

    return true;
}


DBUtil::DBUtil() {

}
