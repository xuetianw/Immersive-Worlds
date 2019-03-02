//
// Created by nirag on 21/02/19.
//

#include "SqlStatements.h"
#include <stdio.h>
#include <SqlStatements.h>
#include <cstring>


//const char strings

const char* SqlStatements::dropUserTableString = "DROP TABLE IF EXISTS User;";
const char* SqlStatements::getAllUsersString = "SELECT username, password FROM User;";

//queries
sqlite3_stmt* SqlStatements::dropUserTableStmt;
sqlite3_stmt* SqlStatements::getAllUsersStmt;


void SqlStatements::prepareDropUserTableStmt() {
    int status = sqlite3_prepare_v2(DBUtil::database, dropUserTableString, -1, &dropUserTableStmt, nullptr);

    if(status!=SQLITE_OK){
        printf("Failed to prepare Statement");
    }
}

void SqlStatements::prepareGetAllUsersStmt() {
    int status = sqlite3_prepare_v2(DBUtil::database, getAllUsersString, -1, &getAllUsersStmt, nullptr);

    if(status!=SQLITE_OK){
        printf("Failed to prepare Statement");
    }
}

void SqlStatements::destroySQLStatements() {
    sqlite3_finalize(dropUserTableStmt);
    sqlite3_finalize(getAllUsersStmt);
}
