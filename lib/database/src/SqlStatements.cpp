//
// Created by nirag on 21/02/19.
//

#include "SqlStatements.h"
#include <stdio.h>
#include <SqlStatements.h>
#include <cstring>


//const char strings

const char* SqlStatements::getAllUsersString = "SELECT username, password FROM User;";

//queries
sqlite3_stmt* SqlStatements::getAllUsersStmt;

void SqlStatements::prepareGetAllUsersStmt() {
    int status = sqlite3_prepare_v2(DBUtil::database, getAllUsersString, -1, &getAllUsersStmt, nullptr);

    if(status!=SQLITE_OK){
        printf("Failed to prepare Statement");
    }
}

void SqlStatements::destroySQLStatements() {
    sqlite3_finalize(getAllUsersStmt);
}
