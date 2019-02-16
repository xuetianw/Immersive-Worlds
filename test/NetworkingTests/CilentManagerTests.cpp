//
// Created by vinshit on 31/01/19.
//

#include "AccountController.h"
#include "Server.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::Return;

struct BasicClientManagerTest : testing:: Test {
    AccountController accountController;
    const std::uintptr_t ID1 = 1233;
    Connection firstConnection{ID1};
    Connection secondConnection{1};
    Message firstMessage{firstConnection,""};
    Message usernameMessage{firstConnection,"random_name"};
    Message passwordMessage{firstConnection,"random_passworld"};
};

// user logout without logging in
TEST_F(BasicClientManagerTest, LogoutTest){
  Message message = accountController.logoutUser(firstMessage);
  EXPECT_EQ(ID1, message.connection.id);
  EXPECT_EQ(NOT_LOGIN_MESSAGE, message.text);
}

//user login
TEST_F(BasicClientManagerTest, LoginTest){
  accountController.connectClient(firstConnection);
  Message userPrompt = accountController.startLogin(firstMessage);

  Message passwordPrompt = accountController.startLogin(usernameMessage);
  pair<bool, Message> accountControllerResponse = accountController.respondToMessage(passwordMessage);

  ASSERT_EQ(LOGIN_USERNAME_PROMPT, userPrompt.text);
  EXPECT_EQ(LOGIN_PASSWORD_PROMPT, passwordPrompt.text);
  ASSERT_TRUE(accountControllerResponse.first);
  EXPECT_EQ(ID1, accountControllerResponse.second.connection.id);
  EXPECT_EQ(LOGGED_IN_PROMPT, accountControllerResponse.second.text);
}

//user login first and logout
TEST_F(BasicClientManagerTest, LoginlogoutSequenceTest){
  accountController.connectClient(firstConnection);
  Message userPrompt = accountController.startLogin(firstMessage);

  Message passwordPrompt = accountController.startLogin(usernameMessage);
  pair<bool, Message> accountControllerResponse = accountController.respondToMessage(passwordMessage);

  Message message = accountController.logoutUser(firstMessage);

  ASSERT_EQ(LOGIN_USERNAME_PROMPT, userPrompt.text);
  EXPECT_EQ(LOGIN_PASSWORD_PROMPT, passwordPrompt.text);
  ASSERT_TRUE(accountControllerResponse.first);
  EXPECT_EQ(ID1, accountControllerResponse.second.connection.id);
  EXPECT_EQ(LOGGED_IN_PROMPT, accountControllerResponse.second.text);
  EXPECT_EQ(LOGOUT_MESSAGE, message.text);
}

//register without logging in
TEST_F(BasicClientManagerTest, RegisterTest){
    accountController.connectClient(firstConnection);
    Message message = accountController.startRegister(firstMessage);

  Message passwordPrompt = accountController.startLogin(usernameMessage);
  pair<bool, Message> accountControllerResponse = accountController.respondToMessage(passwordMessage);

    ASSERT_EQ(REGISTER_USERNAME_PROMPT, message.text);
    EXPECT_EQ(ID1, message.connection.id);
    ASSERT_TRUE(accountControllerResponse.first);
    EXPECT_EQ(ID1, accountControllerResponse.second.connection.id);
    EXPECT_EQ(LOGIN_USERNAME_AFTER_REGISTRATION_PROMPT, accountControllerResponse.second.text);
}

//register withinvalid password



////register after logging in
//TEST_F(BasicClientManagerTest, LoginTest){
//  accountController.connectClient(firstConnection);
//  Message userPrompt = accountController.startLogin(firstMessage);
//
//  Message passwordPrompt = accountController.startLogin(usernameMessage);
//  pair<bool, Message> accountControllerResponse = accountController.respondToMessage(passwordMessage);
//
//  ASSERT_EQ(LOGIN_USERNAME_PROMPT, userPrompt.text);
//  EXPECT_EQ(LOGIN_PASSWORD_PROMPT, passwordPrompt.text);
//  ASSERT_TRUE(accountControllerResponse.first);
//  EXPECT_EQ(firstConnection.id, accountControllerResponse.second.connection.id);
//  EXPECT_EQ(LOGGED_IN_PROMPT, accountControllerResponse.second.text);
//}


//
//
//TEST_F(BasicClientManagerTest, LoginClientTestWithInitalParam){
//  Message firstMessage{firstConnection,"Rex"};
//  Message passwordMessage{firstConnection,"admin12345"};
//
//  accountController.connectClient(firstConnection);
//  Message passwordPrompt = accountController.promptLogin(firstMessage);
//
//  Message loginSuccessful = accountController.handleInput(passwordMessage);
//
//  EXPECT_TRUE(accountController.isLoggedIn(firstConnection));
//
//  EXPECT_EQ("Please enter your password:", passwordPrompt.text);
//  EXPECT_EQ("Successfully logged in!", loginSuccessful.text);
//}
//
//
//TEST_F(BasicClientManagerTest, LoginClientTestWithWrongInfo){
//  Message firstMessage{firstConnection,"Rex"};
//  Message passwordMessage{firstConnection,"admin123"};
//
//  accountController.connectClient(firstConnection);
//  Message passwordPrompt = accountController.promptLogin(firstMessage);
//
//  Message loginUnsuccessful = accountController.handleInput(passwordMessage);
//
//  EXPECT_EQ("Please enter your password:", passwordPrompt.text);
//  EXPECT_EQ("Login Unsuccessful\nPlease enter your username again:", loginUnsuccessful.text);
//  EXPECT_FALSE(accountController.isLoggedIn(firstConnection));
//}

///*
// *  isLoggedIn Tests
// */
//
//class LoggedInClientManagerTest : public ::testing::Test {
//public:
//  AccountController clientManager;
//  Connection firstConnection{0};
//  Message firstMessage{firstConnection, "Rex"};
//  Message passwordMessage{firstConnection, "admin12345"};
//protected:
//  virtual void SetUp() override {
//
//    clientManager.connectClient(firstConnection);
//    Message passwordPrompt = clientManager.promptLogin(firstMessage);
//    Message loginSuccessful = clientManager.handleInput(passwordMessage);
//  }
//
//  virtual void TearDown() override {
//  }
//};
//
//TEST_F(LoggedInClientManagerTest, isLoggedInTestTrue){
//  EXPECT_TRUE(clientManager.isLoggedIn(firstConnection));
//}
//
//TEST_F(LoggedInClientManagerTest, isLoggedInTestWrongConnection){
//  Connection falseConnection{1};
//  EXPECT_FALSE(clientManager.isLoggedIn(falseConnection));
//}
//
///*
// * Registering Test
// */
//
//
//
//TEST_F(BasicClientManagerTest, UsernameTakenClientTest) {
//
//  Message newUsername{firstConnection.id, "SecondBuddy"};
//
//  accountController.connectClient(firstConnection);
//
//  Message userPrompt = accountController.promptRegister(firstMessage);
//  Message usernameTakenPrompt = accountController.handleInput(usernameMessage);
//  Message registerPasswordPrompt = accountController.handleInput(newUsername);
//  Message registerSucessful = accountController.handleInput(passwordMessage);
//
//  EXPECT_FALSE(accountController.isLoggedIn(firstConnection));
//
//  EXPECT_EQ("Please create your username:", userPrompt.text);
//  EXPECT_EQ("Username already exists", usernameTakenPrompt.text);
//  EXPECT_EQ("Please create your password:", registerPasswordPrompt.text);
//  EXPECT_EQ("Account Created! Please re-enter your username:", registerSucessful.text);
//
//  Message passwordPrompt = accountController.promptLogin(newUsername);
//  Message loginSuccessful = accountController.handleInput(passwordMessage);
//
//  EXPECT_TRUE(accountController.isLoggedIn(firstConnection));
//
//  EXPECT_EQ("Please enter your password:", passwordPrompt.text);
//  EXPECT_EQ("Successfully logged in!", loginSuccessful.text);
//}
