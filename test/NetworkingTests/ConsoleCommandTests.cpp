#include "CommandProcessor.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

string loginStr{"Logged in!"}, logoutStr{"Logged out!"};



class ConsoleCommandTest : public ::testing::Test {
public:
    CommandProcessor commandProcessor;
    Connection loginConnection{0},logoutConnection{1};
    string loginCommand{"/login"}, logoutCommand{"/logout"};
    Message login{loginConnection, loginCommand};
    Message logout{logoutConnection, logoutCommand};
    Message dummy{Connection {99},"/HahaWhatAmI"};
protected:
    virtual void SetUp() override {
        commandProcessor.addCommand("defaultUserCommand", [](Command* command, Message message) {return message;});
        commandProcessor.addCommand(loginCommand, [](Command*, Message message){return Message{message.connection,::loginStr};});
        commandProcessor.addCommand(logoutCommand, [](Command*, Message message){return Message{message.connection,::logoutStr};});
    }

    virtual void TearDown() override { }
};


TEST_F(ConsoleCommandTest, commandsAreCalled){
    Message defaultResponse = commandProcessor.processCommand(dummy, false);
    Message loginResponse = commandProcessor.processCommand(login, false);
    Message logoutResponse = commandProcessor.processCommand(logout, false);

    EXPECT_TRUE(defaultResponse.text != loginStr && defaultResponse.text != logoutStr);
    EXPECT_TRUE(loginResponse.text == loginStr);
    EXPECT_TRUE(logoutResponse.text == logoutStr);
    EXPECT_TRUE(defaultResponse.connection.id != loginConnection.id && defaultResponse.connection.id != logoutConnection.id);
    EXPECT_TRUE(loginResponse.connection.id == loginConnection.id);
    EXPECT_TRUE(logoutResponse.connection.id == logoutConnection.id);
}


