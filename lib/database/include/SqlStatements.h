//
// Created by nirag on 21/02/19.
//

#ifndef WEBSOCKETNETWORKING_SQLSTATEMENTS_H
#define WEBSOCKETNETWORKING_SQLSTATEMENTS_H

#include "sqlite3.h"
#include "DBUtil.h"

class SqlStatements {

//define string values for sql statements
private:
    static const char *createUserTableString ;
    static const char *dropUserTableString ;
    static const char *getAllUsersString ;

public:

//define sqlite3 prepare statement pointers
    static sqlite3_stmt *createUserTableStmt;
    static sqlite3_stmt *dropUserTableStmt;
    static sqlite3_stmt *getAllUsersStmt;

//methods to create the statements (both: User dependent and independent)
    static void prepareCreateUserTableStmt();
    static void prepareDropUserTableStmt();

    static void prepareSQLStatements();
    static void destroySQLStatements();

    static void prepareGetAllUsersStmt();


};

#endif //WEBSOCKETNETWORKING_SQLSTATEMENTS_H
