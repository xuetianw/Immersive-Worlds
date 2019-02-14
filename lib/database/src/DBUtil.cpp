//
// Created by nirag on 12/02/19.
//
#include <DBUtil.h>

#include "DBUtil.h"



bool DBUtil::openConnection() {

    //DBUtil::dbName = "../adventure.db";

    sqlite3* temp;

    //int status = sqlite3_open(dbName , &temp);

    //int status = sqlite3_open(dbName, &temp);

//    if(status!=SQLITE_OK){
//        //error handling
//        cout<<"Error occured";
//        return false;
//    }

    return true;
}



DBUtil::DBUtil() {

}
