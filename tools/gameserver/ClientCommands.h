#include <utility>

//
// Created by vinshit on 29/01/19.
//

#include <sstream>
#include "string"
#include "deque"
#include "ClientManager.h"
#include "Server.h"

#ifndef WEBSOCKETNETWORKING_COMMANDPROCESSOR_H
#define WEBSOCKETNETWORKING_COMMANDPROCESSOR_H

#endif //WEBSOCKETNETWORKING_COMMANDPROCESSOR_H

using networking::Server;

using std::deque;
using std::string;
using std::stringstream;

class CommandProcessor{
  /*
   * Helper Class to avoid manual wiring of key commands to the Game/Account method calls
   */
public:
  bool isMessageCommand(const Message message);

  Message processMessage(const Message message);

  void addCommand(string commandKeyword, Message (*command_function)(Message));

  CommandProcessor(){}

private:
  std::unordered_map<string, Message(*)(Message)> _commands;
};