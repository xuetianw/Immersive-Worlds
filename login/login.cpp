#include <iostream>
#include <string>
//
// Created by nirag on 17/01/19.
//

//mock implementation of login system. Will change with requirements

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "login.h"
using namespace std;

std::string username;
std::string password;

const int SHORT_PASSWORD = 1;
const int LONG_PASSWORD = 2;
const int MISSING_SPECIAL_PASSWORD = 3;

std::vector<string> usernames{"John","Rex","Alex","Garfield"};
std::vector<string> passwords{"gsgfdgfd*","dbgdbvv#","ff","fvbdfsgvfcvbvxcbdfvdfvd"};

void login(string username, string password)
{



    //establish connection with browser

}

bool createUser()
{
    //mock up of login only
    cout<<"Enter a username for yourself";
    cin>>username;

    //check if username already exists
    //mock up using vector test
    //in actual implementation use parsed json file
    if(!checkUserNameExistence(username)){
         cout<<"User already exists";
         return false;
    }

    cout<<"Enter password";
    cin>>password;

    if(validatePassword(password)==1){
        //prompt user in GUI stating short password
    }
    else if(validatePassword( password)==2){

    }
    else if(validatePassword(password)==3){

    }
    else{
        cout<<"Congratulation! You have successfully created an account";
    }

    //store username and pass in json


}

int validatePassword(string password)
{
    if(password.length()<7)
        return SHORT_PASSWORD;
    else if(password.length()>15)
        return LONG_PASSWORD;
    else if(!checkSpecialCharacter(password))
        return MISSING_SPECIAL_PASSWORD;

    return 0;

    //verify username and password with json

}

bool checkUserNameExistence(std::string username)
{
    //mock up which checks if user exists or not within vector
    for(int i=0;i<usernames.size();i++)
    {
        if(usernames[i].compare(username)==0)
            return true;
    }
    return false;
}

bool checkSpecialCharacter(std::string password)
{
    for(int i=0; i<password.length();i++)
    {
        if(password[i]=='.' || password[i]=='*' || password[i]=='#')
            return true;
    }
    return false;
}
