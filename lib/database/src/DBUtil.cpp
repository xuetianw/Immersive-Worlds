//
// Created by nirag on 12/02/19.
//
#include <DBUtil.h>

#include "DBUtil.h"



bool DBUtil::openConnection() {

    char * filename = "../adventure.db";
    int status = sqlite3_open(filename,&database);

    if(status!=SQLITE_OK){
        //error handling
        cout<<"Error occured";
        return false;
    }

    return true;
}
