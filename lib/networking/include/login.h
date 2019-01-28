//
// Created by nirag on 17/01/19.
//

#ifndef ADVENTURE2019_LOGIN_H
#define ADVENTURE2019_LOGIN_H


#include <string>

void login(std::string username, std::string password);
static int validatePassword(std::string password);
bool checkUserNameExistence(std::string username);
bool checkSpecialCharacter(std::string password);
bool createUser();


#endif //ADVENTURE2019_LOGIN_H
