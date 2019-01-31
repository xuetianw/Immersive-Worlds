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
bool parseCommand(Message message, ClientManager &clientManager, Server &server)
{
    string command = message.text;

    vector<string> words;

    //split multi word commands
    boost::split(words, command,boost::is_any_of(" "), boost::token_compress_on);

    if(words[0]=="/escape" && clientManager.isClientBeingPromptedByServer(message.connection.id)){
    //revert user login state
        handleEscape(message, clientManager);

        return true;
    }
    if(words[0]=="/login" ||  clientManager.isClientBeingPromptedByServer(message.connection.id)){
        Message responseMessage = clientManager.promptLogin(message);
        server.sendSingleMessage(responseMessage);

        return true;
    }
    //no command found
    else
        return false;
}

bool isCommand(Message message){
    string text = message.text;
    if(text[0]=='/')
        return true;
    else
        return false;
}

void handleEscape(const Message message, ClientManager &clientManager){
    if(clientManager.isClientBeingPromptedByServer(message.connection.id)){
        clientManager.logoutClient(message.connection.id);
    }
}
