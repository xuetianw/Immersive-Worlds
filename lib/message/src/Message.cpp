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

int Message::getAuthor_user_id() const {
    return author_user_id;
}

void Message::setAuthor_user_id(int author_user_id) {
    Message::author_user_id = author_user_id;
}

MessageType Message::getType() const {
    return type;
}

void Message::setType(MessageType type) {
    Message::type = type;
}

const std::string &Message::getMessage_text() const {
    return message_text;
}

void Message::setMessage_text(const std::string &message_text) {
    Message::message_text = message_text;
}

const std::vector<int> &Message::getTo_user_id() const {
    return to_user_id;
}

void Message::setTo_user_id(const std::vector<int> &to_user_id) {
    Message::to_user_id = to_user_id;
}

