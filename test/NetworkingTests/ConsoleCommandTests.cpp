#include "ConsoleCommands.h"
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
  Message dummy{99,"/HahaWhatAmI"};
protected:
  virtual void SetUp() override {
    commandProcessor.addCommand(loginCommand, [](Message message){return Message{message.connection,::loginStr};});
    commandProcessor.addCommand(logoutCommand, [](Message message){return Message{message.connection,::logoutStr};});
  }

  virtual void TearDown() override {
  }
};


TEST_F(ConsoleCommandTest, commandsAreCalled){
  Message defaultResponse = commandProcessor.processMessage(dummy);
  Message loginResponse = commandProcessor.processMessage(login);
  Message logoutResponse = commandProcessor.processMessage(logout);

  EXPECT_TRUE(defaultResponse.text != loginStr && defaultResponse.text != logoutStr);
  EXPECT_TRUE(loginResponse.text == loginStr);
  EXPECT_TRUE(logoutResponse.text == logoutStr);
  EXPECT_TRUE(defaultResponse.connection.id != loginConnection.id && defaultResponse.connection.id != logoutConnection.id);
  EXPECT_TRUE(loginResponse.connection.id == loginConnection.id);
  EXPECT_TRUE(logoutResponse.connection.id == logoutConnection.id);


}


