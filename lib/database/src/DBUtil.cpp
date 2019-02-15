//
// Created by nirag on 12/02/19.
//
#include <DBUtil.h>

#include "DBUtil.h"
#include "sqlite3.h"

//declaring static field outside header file
sqlite3* DBUtil::database;

bool DBUtil::openConnection() {

    //DBUtil::dbName = "../adventure.db";

    //use DB path
    int status = sqlite3_open("/home/nirag/CLionProjects/adventure2019/lib/database/adventure.db",& (DBUtil::database));


    if(status!=SQLITE_OK){
        //error handling

        return false;
    }

    return true;
}

bool DBUtil::createTables() {


    DBUtil::dropTables();

    int status = sqlite3_exec( DBUtil::database,"CREATE TABLE IF NOT EXISTS User(id INT PRIMARY KEY, username VARCHAR(20), password VARCHAR(20));",
            DBUtil::my_special_callback, NULL , NULL );

    if(status!=0){
        //error handling
        return false;
    }

    sqlite3_close(DBUtil::database);

    return true;

}

bool DBUtil::dropTables() {
    int status = sqlite3_exec( DBUtil::database,"DROP TABLE IF EXISTS User;",
                                            DBUtil::my_special_callback, NULL , NULL );

    if(status!=0){
        return false;
    }
    return true;
}

/*
 * Arguments:
 *
 *   unused - Ignored in this case, see the documentation for sqlite3_exec
 *    count - The number of columns in the result set
 *     data - The row's data
 *  columns - The column names
 */
int DBUtil::my_special_callback(void *unused, int count, char **data, char **columns)
{
    int idx;

    printf("There are %d column(s)\n", count);

    for (idx = 0; idx < count; idx++) {
        printf("The data in column \"%s\" is: %s\n", columns[idx], data[idx]);
    }

    printf("\n");

    return 0;
}


DBUtil::DBUtil() {

}
