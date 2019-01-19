#include <Message.h>
#include <string>

Message::Message(int author_user_id, std::string type, std::string message_text, std::vector<int> to_user_id) {
    this->author_user_id    = author_user_id;
    this->message_text      = message_text;
    this->type              = getMessageType(type);
    this->to_user_id        = to_user_id;
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

void Message::addUser(int id) {
    this->to_user_id.push_back(id);
}

