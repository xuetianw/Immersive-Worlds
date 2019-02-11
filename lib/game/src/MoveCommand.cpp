#include <iostream>
#include "MoveCommand.h"

//find a way to access details of the character to be attacked
networking::Message MoveCommand::execute(GameService &service, const networking::Message& message)  {
    networking::Message newMessage = networking::Message();
    newMessage.connection = message.connection;
    std::string beforeMoveRoomName = service.getCurrentRoomName(message.connection);
    service.moveUser(message.connection, message.text);
    std::string afterMoveRoomName = service.getCurrentRoomName(message.connection);
    std::string output = "command /move " + message.text + " called\n" + "before move: " + beforeMoveRoomName + "\nafter move: " + afterMoveRoomName;
    newMessage.text = output;
    return newMessage;
}
