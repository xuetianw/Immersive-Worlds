#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <vector>

enum MessageType { say, yell, tell, error};

class Message {
private:
    int author_user_id;             // user_id
    MessageType type;               // type of message
    std::string message_text;       // text that user inputted
    std::vector<int> to_user_id;    // list of user id that the message will be sent to

public:
    /**
     * The constructor for the message class. Will call the getMessageType function to 
     * assing the object value type.
     * 
     * @param int author_user_id: the id of the user that send the message
     * @param std::string type: used to pass the variable to the getMessageType function
     * @param std::string message_text: the text that the user typed
     */
    Message(int author_user_id, std::string type, std::string message_text, std::vector<int> to_user_id);

    /**
     * Returns the message type based on the parameter given
     * 
     * @param type: "say", "yell", "tell", "error"
     */
    MessageType getMessageType(std::string type); 

    /** 
     * Add a user_id to the list
     * @param user_id: the id that will receive the message
     */  

    void addUser(int id);
};
#endif

