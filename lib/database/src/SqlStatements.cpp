//
// Created by nirag on 21/02/19.
//

#include "SqlStatements.h"
#include <stdio.h>
#include <SqlStatements.h>
#include <cstring>


//const char strings
const char* SqlStatements::createUserTableString = "CREATE TABLE IF NOT EXISTS User(id INTEGER PRIMARY KEY AUTOINCREMENT, username VARCHAR(20), password VARCHAR(20));";

//queries
sqlite3_stmt* SqlStatements::createUserTableStmt;
sqlite3_stmt* SqlStatements::registerUserStmt;

void SqlStatements::createUserTable() {

    int status = sqlite3_prepare_v2(DBUtil::database, createUserTableString, -1, &createUserTableStmt, NULL);

    if(status!=SQLITE_OK){
        printf("Failed to create User Table");
    }

}

void SqlStatements::registerUser(string username, string password) {

    string registerUserString = "INSERT INTO User(username , password) VALUES('"
                         + username + "','"
                         + password +
                         "');";

    int status = sqlite3_prepare_v2(DBUtil::database, registerUserString.c_str(), -1, &registerUserStmt, NULL);

    if(status!=SQLITE_OK){
        printf("Failed to register User");
    }
}


void SqlStatements::prepareSQLStatements() {

    //call all functions to prepare sql queries
    createUserTable();
}
