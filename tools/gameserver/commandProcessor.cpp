//
// Created by Nirag Mehta on 2019-01-30.
//

#include "commandProcessor.h"
#include "ClientManager.h"
#include "Server.h"
#include "vector"
#include "boost/algorithm/string/split.hpp"
#include "boost/algorithm/string/classification.hpp"

#include "iostream"

using namespace networking;
using namespace std;

std::map<command , std::string> mapCommands;

//first we parse string using delimiter " "
void parseCommand(Message message)
{
    string command = message.text;

    vector<string> words;

    //split multi word commands
    boost::split(words, command,boost::is_any_of(" "), boost::token_compress_on);
}

bool isCommand(Message message){
    string text = message.text;
    if(text[0]=='/')
        return true;
    else
        return false;
}