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

TEST(BasicClientManagerTest, RegisterClientTest){
  ClientManager clientManager;
  Connection firstConnection{0};
  Connection secondConnection{1};
  clientManager.registerClient(firstConnection);
  EXPECT_FALSE(clientManager.registerClient(firstConnection));
  EXPECT_TRUE(clientManager.registerClient(secondConnection));
}

/*
 * Unregistering
 */

TEST(BasicClientManagerTest, UnregisterClientTest){
  ClientManager clientManager;
  Connection firstConnection{0};
  clientManager.registerClient(firstConnection);
  clientManager.unregisterClient(firstConnection);
  EXPECT_TRUE(clientManager.registerClient(firstConnection));
}

/*
 * Logging out
 */

TEST(BasicClientManagerTest, LogoutClientTest){
  ClientManager clientManager;
  Connection firstConnection{0};
  clientManager.registerClient(firstConnection);
  Message message = clientManager.logoutClient(firstConnection);
  EXPECT_EQ(message.connection, firstConnection);
  EXPECT_EQ(message.text, "User not logged in!\n");
}

/*
 * Login tests
 */

TEST(BasicClientManagerTest, LoginClientTestWithoutInitalParam){
  ClientManager clientManager;
  Connection firstConnection{0};
  Message firstMessage{firstConnection,""};
  Message usernameMessage{firstConnection,"Rex"};
  Message passwordMessage{firstConnection,"admin12345"};

  clientManager.registerClient(firstConnection);
  Message userPrompt = clientManager.promptLogin(firstMessage);
  EXPECT_TRUE(clientManager.isClientPromptingLogin(firstConnection));

  Message passwordPrompt = clientManager.promptLogin(usernameMessage);
  EXPECT_TRUE(clientManager.isClientPromptingLogin(firstConnection));

  Message loginSuccessful = clientManager.promptLogin(passwordMessage);

  EXPECT_EQ(userPrompt.text, "Please enter your username:\n");
  EXPECT_EQ(passwordPrompt.text, "Please enter your password:\n");
  EXPECT_EQ(loginSuccessful.text, "Successfully logged in!\n");
}


TEST(BasicClientManagerTest, LoginClientTestWithInitalParam){
  ClientManager clientManager;
  Connection firstConnection{0};
  Message firstMessage{firstConnection,"Rex"};
  Message passwordMessage{firstConnection,"admin12345"};

  clientManager.registerClient(firstConnection);
  Message passwordPrompt = clientManager.promptLogin(firstMessage);
  EXPECT_TRUE(clientManager.isClientPromptingLogin(firstConnection));

  Message loginSuccessful = clientManager.promptLogin(passwordMessage);

  EXPECT_EQ(passwordPrompt.text, "Please enter your password:\n");
  EXPECT_EQ(loginSuccessful.text, "Successfully logged in!\n");
}


TEST(BasicClientManagerTest, LoginClientTestWithWrongInfo){
  ClientManager clientManager;
  Connection firstConnection{0};
  Message firstMessage{firstConnection,"Rex"};
  Message passwordMessage{firstConnection,"admin123"};

  clientManager.registerClient(firstConnection);
  Message passwordPrompt = clientManager.promptLogin(firstMessage);
  EXPECT_TRUE(clientManager.isClientPromptingLogin(firstConnection));

  Message loginUnsuccessful = clientManager.promptLogin(passwordMessage);

  EXPECT_EQ(passwordPrompt.text, "Please enter your password:\n");
  EXPECT_EQ(loginUnsuccessful.text, "Login Unsuccessful\nPlease enter your username again:\n");
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

    clientManager.registerClient(firstConnection);
    Message passwordPrompt = clientManager.promptLogin(firstMessage);
    Message loginSuccessful = clientManager.promptLogin(passwordMessage);
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
