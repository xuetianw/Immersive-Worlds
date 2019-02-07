//
// Created by vinshit on 31/01/19.
//

#include "ClientManager.h"
#include "Server.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::Return;

/*
 * Registering
 */


struct BasicClientManagerTest : testing:: Test {
    ClientManager clientManager;
    Connection firstConnection{0};
    Connection secondConnection{1};
    Message firstMessage{firstConnection,""};
    Message usernameMessage{firstConnection,"Rex"};
    Message passwordMessage{firstConnection,"admin12345"};
};

TEST_F(BasicClientManagerTest, RegisterClientTest){
  clientManager.connectClient(firstConnection);
    EXPECT_FALSE(clientManager.connectClient(firstConnection));
    EXPECT_TRUE(clientManager.connectClient(secondConnection));
}

/*
 * Unregistering
 */

TEST_F(BasicClientManagerTest, UnregisterClientTest){
  clientManager.disconnectClient(firstConnection);
  EXPECT_TRUE(clientManager.connectClient(firstConnection));
}

/*
 * Logging out
 */

TEST_F(BasicClientManagerTest, LogoutClientTest){
  clientManager.connectClient(firstConnection);
  Message message = clientManager.logoutClient(firstConnection);
  EXPECT_EQ(firstConnection, message.connection);
  EXPECT_EQ("User not logged in!\n", message.text);
}

/*
 * Login tests
 */

TEST_F(BasicClientManagerTest, LoginClientTestWithoutInitalParam){
  clientManager.connectClient(firstConnection);
  Message userPrompt = clientManager.promptLogin(firstMessage);

  Message passwordPrompt = clientManager.promptLogin(usernameMessage);
  Message loginSuccessful = clientManager.handleInput(passwordMessage);

  EXPECT_TRUE(clientManager.isLoggedIn(firstConnection));

  EXPECT_EQ("Please enter your username:", userPrompt.text);
  EXPECT_EQ("Please enter your password:", passwordPrompt.text);
  EXPECT_EQ("Successfully logged in!", loginSuccessful.text);
}


TEST_F(BasicClientManagerTest, LoginClientTestWithInitalParam){
  Message firstMessage{firstConnection,"Rex"};
  Message passwordMessage{firstConnection,"admin12345"};

  clientManager.connectClient(firstConnection);
  Message passwordPrompt = clientManager.promptLogin(firstMessage);

  Message loginSuccessful = clientManager.handleInput(passwordMessage);

  EXPECT_TRUE(clientManager.isLoggedIn(firstConnection));

  EXPECT_EQ("Please enter your password:", passwordPrompt.text);
  EXPECT_EQ("Successfully logged in!", loginSuccessful.text);
}


TEST_F(BasicClientManagerTest, LoginClientTestWithWrongInfo){
  Message firstMessage{firstConnection,"Rex"};
  Message passwordMessage{firstConnection,"admin123"};

  clientManager.connectClient(firstConnection);
  Message passwordPrompt = clientManager.promptLogin(firstMessage);

  Message loginUnsuccessful = clientManager.handleInput(passwordMessage);

  EXPECT_EQ("Please enter your password:", passwordPrompt.text);
  EXPECT_EQ("Login Unsuccessful\nPlease enter your username again:", loginUnsuccessful.text);
  EXPECT_FALSE(clientManager.isLoggedIn(firstConnection));
}

/*
 *  isLoggedIn Tests
 */

class LoggedInClientManagerTest : public ::testing::Test {
public:
  ClientManager clientManager;
  Connection firstConnection{0};
  Message firstMessage{firstConnection, "Rex"};
  Message passwordMessage{firstConnection, "admin12345"};
protected:
  virtual void SetUp() override {

    clientManager.connectClient(firstConnection);
    Message passwordPrompt = clientManager.promptLogin(firstMessage);
    Message loginSuccessful = clientManager.handleInput(passwordMessage);
  }

  virtual void TearDown() override {
  }
};

TEST_F(LoggedInClientManagerTest, isLoggedInTestTrue){
  EXPECT_TRUE(clientManager.isLoggedIn(firstConnection));
}

TEST_F(LoggedInClientManagerTest, isLoggedInTestWrongConnection){
  Connection falseConnection{1};
  EXPECT_FALSE(clientManager.isLoggedIn(falseConnection));
}

/*
 * Registering Test
 */



TEST_F(BasicClientManagerTest, UsernameTakenClientTest) {

  Message newUsername{firstConnection.id, "SecondBuddy"};

  clientManager.connectClient(firstConnection);

  Message userPrompt = clientManager.promptRegister(firstMessage);
  Message usernameTakenPrompt = clientManager.handleInput(usernameMessage);
  Message registerPasswordPrompt = clientManager.handleInput(newUsername);
  Message registerSucessful = clientManager.handleInput(passwordMessage);

  EXPECT_FALSE(clientManager.isLoggedIn(firstConnection));

  EXPECT_EQ("Please create your username:", userPrompt.text);
  EXPECT_EQ("Username already exists", usernameTakenPrompt.text);
  EXPECT_EQ("Please create your password:", registerPasswordPrompt.text);
  EXPECT_EQ("Account Created!", registerSucessful.text);

  Message passwordPrompt = clientManager.promptLogin(newUsername);
  Message loginSuccessful = clientManager.handleInput(passwordMessage);

  EXPECT_TRUE(clientManager.isLoggedIn(firstConnection));

  EXPECT_EQ("Please enter your password:", passwordPrompt.text);
  EXPECT_EQ("Successfully logged in!", loginSuccessful.text);
}
