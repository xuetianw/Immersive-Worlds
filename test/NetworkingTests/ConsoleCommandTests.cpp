#include "CommandProcessor.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using networking::Connection;

string loginStr{"Logged in!"}, logoutStr{"Logged out!"};



class ConsoleCommandTest : public ::testing::Test {
public:
    CommandProcessor commandProcessor;
    Connection loginConnection{0},logoutConnection{1}, dummyConnection{99};
    User loginUser{loginConnection};
    User logoutUser{logoutConnection};
    User dummyUser{dummyConnection};


    string loginCommand{"/login"}, logoutCommand{"/logout"};
    Message login{loginUser, loginCommand};
    Message logout{logoutUser, logoutCommand};
    Message dummy{dummyUser,"/HahaWhatAmI"};
protected:
    virtual void SetUp() override {
        commandProcessor.addCommand(loginCommand, LOGIN, [](Message message){return Message{message.user,::loginStr};});
        commandProcessor.addCommand(logoutCommand, LOGOUT, [](Message message){return Message{message.user,::logoutStr};});
    }

    virtual void TearDown() override { }
};


TEST_F(ConsoleCommandTest, commandsAreCalled){

    loginUser.addCommand(LOGIN);
    logoutUser.addCommand(LOGOUT);

    Message defaultResponse = commandProcessor.processCommand(dummy);
    Message loginResponse = commandProcessor.processCommand(login);
    Message logoutResponse = commandProcessor.processCommand(logout);

    EXPECT_TRUE(defaultResponse.text != loginStr && defaultResponse.text != logoutStr);
    EXPECT_TRUE(loginResponse.text == loginStr);
    EXPECT_TRUE(logoutResponse.text == logoutStr);
    EXPECT_TRUE(defaultResponse.user.getConnection().id != loginConnection.id && defaultResponse.user.getConnection().id != logoutConnection.id);
    EXPECT_TRUE(loginResponse.user.getConnection().id == loginConnection.id);
    EXPECT_TRUE(logoutResponse.user.getConnection().id == logoutConnection.id);
}

TEST_F(ConsoleCommandTest, userCallsForbiddenCommands){

    Message loginResponse = commandProcessor.processCommand(login);
    Message logoutResponse = commandProcessor.processCommand(logout);

    EXPECT_TRUE(loginResponse.text != loginStr);
    EXPECT_TRUE(logoutResponse.text != logoutStr);
    EXPECT_TRUE(loginResponse.user.getConnection().id == loginConnection.id);
    EXPECT_TRUE(logoutResponse.user.getConnection().id == logoutConnection.id);
}

