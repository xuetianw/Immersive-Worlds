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

public:

//define sqlite3 prepare statement pointers
    static sqlite3_stmt *createUserTableStmt;

    static sqlite3_stmt *registerUserStmt;
    static sqlite3_stmt *deleteUserStmt;

//methods to create the statements (both: User dependent and independent)
    static void createUserTable();

    static void prepareSQLStatements();

    static void registerUser(string username, string password);
    static void deleteUser(string username);


};

#endif //WEBSOCKETNETWORKING_SQLSTATEMENTS_H
