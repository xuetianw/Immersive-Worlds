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

    return true;
}


// TODO hash passwords
bool DBUtil::registerUser(const string& username, const string& password) {
    const string registerUserQueryString = "INSERT INTO User (username, password) VALUES (:username, :password);";
    sqlite3_stmt* registerUserStmt;

    sqlite3_prepare_v2(DBUtil::database,
                       registerUserQueryString.c_str(),
                       -1,
                       &registerUserStmt,
                       nullptr
    );

    sqlite3_bind_text(registerUserStmt,
                      sqlite3_bind_parameter_index(registerUserStmt, ":username"),
                      username.c_str(),
                      username.length(),
                      nullptr
    );

    sqlite3_bind_text(registerUserStmt,
                      sqlite3_bind_parameter_index(registerUserStmt, ":password"),
                      password.c_str(),
                      password.length(),
                      nullptr
    );

    int status = sqlite3_step(registerUserStmt);

    sqlite3_finalize(registerUserStmt);

    return status == SQLITE_DONE;
}

bool DBUtil::deleteUser(const string& username) {
    string deleteUserQueryString = "DELETE FROM User WHERE username = :username;";
    sqlite3_stmt* deleteUserStmt;

    sqlite3_prepare_v2(DBUtil::database,
                       deleteUserQueryString.c_str(),
                       -1,
                       &deleteUserStmt,
                       nullptr
    );

    sqlite3_bind_text(deleteUserStmt,
                      sqlite3_bind_parameter_index(deleteUserStmt, ":username"),
                      username.c_str(),
                      username.length(),
                      nullptr
    );

    int status = sqlite3_step(deleteUserStmt);

    sqlite3_finalize(deleteUserStmt);

    return status == SQLITE_DONE;
}

bool DBUtil::userExists(const string& username) {
    const string selectUserQueryString = "SELECT * FROM User WHERE username = :username";
    sqlite3_stmt* findUserStmt;

    sqlite3_prepare_v2(DBUtil::database,
                       selectUserQueryString.c_str(),
                       -1,
                       &findUserStmt,
                       nullptr
    );

    sqlite3_bind_text(findUserStmt,
                      sqlite3_bind_parameter_index(findUserStmt, ":username"),
                      username.c_str(),
                      username.length(),
                      nullptr
    );

    int status = sqlite3_step(findUserStmt);

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
    const string createUserTableQueryString = "CREATE TABLE IF NOT EXISTS User(id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT UNIQUE, password TEXT);";
    sqlite3_stmt* createTableStmt;

    sqlite3_prepare_v2(DBUtil::database,
                       createUserTableQueryString.c_str(),
                       -1,
                       &createTableStmt,
                       nullptr
    );

    int status = sqlite3_step(createTableStmt);

    sqlite3_finalize(createTableStmt);

    return status == SQLITE_DONE;
}

//add all tables to drop here
bool DBUtil::dropTables() {
    int status = sqlite3_step(SqlStatements::dropUserTableStmt);

    return status == SQLITE_DONE;
}