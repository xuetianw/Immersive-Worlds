//
// Created by nirag on 12/02/19.
//
#include <utility>

#include "DBUtil.h"
#include "SqlStatements.h"
#include "sqlite3.h"

//declaring static field outside header file
sqlite3* DBUtil::database;
char* DBUtil::dbName;
char* DBUtil::errorMessage;

bool DBUtil::openConnection() {
    // Open the database for reading and writing.
    // Create the database if it doesn't exist
    int databaseFlags = SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE;

    int status = sqlite3_open_v2("adventure.db", &(DBUtil::database), databaseFlags,
                                 nullptr);

    if (status != SQLITE_OK) {
        //TODO error handling
        return false;
    }

    createTables();
    prepareSQLStatements();

    return true;
}





bool DBUtil::registerUser(string username, string password) {


    SqlStatements::registerUser(std::move(username), std::move(password));
    int status = sqlite3_step(SqlStatements::registerUserStmt);

    return status == SQLITE_DONE;

}

bool DBUtil::deleteUser(string username) {

    SqlStatements::deleteUser(std::move(username));
    int status = sqlite3_step(SqlStatements::deleteUserStmt);

    return status == SQLITE_DONE;

}

bool DBUtil::userExists(string username) {

    SqlStatements::findUser(std::move(username));
    int status = sqlite3_step(SqlStatements::findUserStmt);

    return status == SQLITE_ROW;

}

//on server bootup acquires all users
bool DBUtil::getAllUsers() {

    int status;
    std::unordered_map<string, string> userData;
    while((status = sqlite3_step(SqlStatements::getAllUsersStmt)) == SQLITE_ROW){

        string username(reinterpret_cast<const char*>( sqlite3_column_text(SqlStatements::getAllUsersStmt,0)) );
        string password(reinterpret_cast<const char*>( sqlite3_column_text(SqlStatements::getAllUsersStmt,1)) );

        userData.insert(make_pair(username,password));
    }


    //free memory because strdup will malloc the copy -> prevents memory leakage

    return status == SQLITE_DONE;

}



bool DBUtil::closeConnection() {

    //destroy all prepared SQL statements to prevent memory leaks
    SqlStatements::destroySQLStatements();

    int status = sqlite3_close_v2(DBUtil::database);

    return status == SQLITE_OK;

}


/*
 *
 * PRIVATE
 *
 */

bool DBUtil::createTables() {
    SqlStatements::prepareCreateUserTableStmt();
    int status = sqlite3_step(SqlStatements::createUserTableStmt);

    return status == SQLITE_DONE;
}

void DBUtil::prepareSQLStatements() {
    SqlStatements::prepareSQLStatements();
}

//add all tables to drop here
bool DBUtil::dropTables() {
    int status = sqlite3_step(SqlStatements::dropUserTableStmt);

    return status == SQLITE_DONE;
}