//
// Created by nirag on 12/02/19.
//
#include <DBUtil.h>

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

//add all tables to create here
bool DBUtil::createTables() {

    //for now we keep the tables to retain data
    SqlStatements::prepareSQLStatements();

    int status = sqlite3_step(SqlStatements::createUserTableStmt);

    if(status != SQLITE_DONE){
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

    SqlStatements::deleteUser(username);
    int status = sqlite3_step(SqlStatements::deleteUserStmt);

    if(status!=SQLITE_DONE){
        //error handling

        return false;
    }

    return true;

}

bool DBUtil::userExists(string username) {

    SqlStatements::findUser(username);
    int status = sqlite3_step(SqlStatements::findUserStmt);

    if(status == SQLITE_ROW)
        return true;

    return false;

}

//on server bootup acquires all users
bool DBUtil::getAllUsers() {

    int status;
    std::unordered_map<string, string> userData;
    while((status = sqlite3_step(SqlStatements::getAllUsersStmt)) == SQLITE_ROW){

        string username(reinterpret_cast<const char*>( sqlite3_column_text(SqlStatements::getAllUsersStmt,0)) );
        string passsword(reinterpret_cast<const char*>( sqlite3_column_text(SqlStatements::getAllUsersStmt,1)) );

        userData.insert(make_pair(  username,passsword));
    }


    //free memory because strdup will malloc the copy -> prevents memory leakage

    if(status!=SQLITE_DONE){
        //error with sql
        return false;
    }
    return true;

}

//add all tables to drop here
bool DBUtil::dropTables() {

    int status = sqlite3_step(SqlStatements::dropUserTableStmt);

    if(status!=SQLITE_DONE){
        //error handling
        return false;
    }
    return true;

}

bool DBUtil::closeConnection() {

    //destroy all prepared SQL statements to prevent memory leaks
    SqlStatements::destroySQLStatements();

    int status = sqlite3_close_v2(DBUtil::database);

    if(status!=SQLITE_OK)
        return false;

    return true;
}
