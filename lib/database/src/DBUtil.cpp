//
// Created by nirag on 12/02/19.
//

#include <DBUtil.h>

#include "DBUtil.h"

//declaring static field outside header file
sqlite3* DBUtil::database;
char* DBUtil::dbName;
char* DBUtil::errorMessage;

bool DBUtil::openConnection(const string& databaseFullFilePath) {
    // Open the database for reading and writing.
    // Create the database if it doesn't exist
    int databaseFlags = SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE;

    int status = sqlite3_open_v2(databaseFullFilePath.c_str(),
                                 &DBUtil::database,
                                 databaseFlags,
                                 nullptr
    );

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
    const string selectUserQueryString = "SELECT * FROM User WHERE username = :username;";
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

bool DBUtil::findUserExistence(string &username, string &password) {

    const string getUserQueryString = "SELECT * FROM User WHERE username = :username AND password = :password;";
    sqlite3_stmt* findUserStmt;

    sqlite3_prepare_v2(DBUtil::database,
                       getUserQueryString.c_str(),
                       -1,
                       &findUserStmt,
                       nullptr
            );

    sqlite3_bind_text(findUserStmt,
            sqlite3_bind_parameter_index(findUserStmt,":username"),
            username.c_str(),
            username.length(),
            nullptr);

    sqlite3_bind_text(findUserStmt,
                      sqlite3_bind_parameter_index(findUserStmt,":password"),
                      password.c_str(),
                      password.length(),
                      nullptr);

    int status = sqlite3_step(findUserStmt);

    return status == SQLITE_ROW;
}

//on server bootup acquires all users
QueryResults DBUtil::getAllUsers() {
    const string getAllUsersQueryString = "SELECT username, password FROM User;";
    sqlite3_stmt* getAllUsersStmt;
    QueryResults results;
    int status;

    sqlite3_prepare_v2(DBUtil::database,
                       getAllUsersQueryString.c_str(),
                       -1,
                       &getAllUsersStmt,
                       nullptr
    );

    //execute query and build results row by row
    while ((status = sqlite3_step(getAllUsersStmt)) == SQLITE_ROW) {
        RowResult rowResult;

        const string usernameColumn(sqlite3_column_name(getAllUsersStmt, 0));
        const string usernameValue(reinterpret_cast<const char*>( sqlite3_column_text(getAllUsersStmt, 0)));

        const string passwordColumn(sqlite3_column_name(getAllUsersStmt, 1));
        const string passwordValue(reinterpret_cast<const char*>( sqlite3_column_text(getAllUsersStmt, 1)));

        rowResult.try_emplace(usernameColumn, usernameValue);
        rowResult.try_emplace(passwordColumn, passwordValue);

        results.emplace_back(rowResult);
    }

    sqlite3_finalize(getAllUsersStmt);

    //return empty results of query fails
    if (status != SQLITE_DONE) {
        return QueryResults{};
    }

    return results;
}

bool DBUtil::closeConnection() {
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
    const string dropUserTableQueryString = "DROP TABLE IF EXISTS User;";
    sqlite3_stmt* dropTableStmt;

    sqlite3_prepare_v2(DBUtil::database,
                       dropUserTableQueryString.c_str(),
                       -1,
                       &dropTableStmt,
                       nullptr
    );

    int status = sqlite3_step(dropTableStmt);

    sqlite3_finalize(dropTableStmt);

    return status == SQLITE_DONE;
}