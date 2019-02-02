//
// Created by fred on 28/01/19.
//

#include <gtest/gtest.h>
#include "Message.h"


struct MessageTests : testing:: Test {
    int author_user_id = 12345;
    std::string typeSay = "say";
    std::string message_text = "hello there!";
    std::vector<int> to_user_id{3,2,1};
    Message message{author_user_id, typeSay, message_text, to_user_id,};
};


TEST_F(MessageTests, constructor_test) {
    EXPECT_EQ(author_user_id, message.getAuthor_user_id());
    EXPECT_EQ(Message::getMessageType(typeSay), message.getType());
    EXPECT_EQ(message_text, message.getMessage_text());
    EXPECT_EQ(to_user_id, message.getTo_user_id());
}

TEST(MessageTest, getCorrectMessageType) {
    EXPECT_EQ(yell, Message::getMessageType("yell"));
    EXPECT_EQ(tell, Message::getMessageType("tell"));
    EXPECT_EQ(error, Message::getMessageType("error"));
}

TEST_F(MessageTests, canAddUser) {
    message.addUser(5);
    std::vector<int> temp {3,2,1,5};
    EXPECT_EQ(temp, message.getTo_user_id());
}
