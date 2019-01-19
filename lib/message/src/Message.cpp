#include <Message.h>
#include <string>

Message::Message(int author_user_id, std::string type, std::string message_text) {
    this->author_user_id    = author_user_id;
    this->message_text      = message_text;
    this->type              = getMessageType(type);
}

MessageType Message::getMessageType(std::string type) {
    MessageType result;

    if(type == "say") {
        result = say;
    } else if(type == "yell") {
        result = yell;
    } else if(type == "tell") {
        result = tell;
    } else {
        result = error;
    }

    return result;
}  

