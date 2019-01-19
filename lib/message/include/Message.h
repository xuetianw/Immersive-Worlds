#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

enum MessageType { say, yell, tell, error};

class Message {
private:
    int author_user_id;         // user_id
    MessageType type;           // type of message
    std::string message_text;   // text that user inputted

public:
    Message(int author_user_id, std::string type, std::string message_text);
    MessageType getMessageType(std::string type);   
};
#endif

