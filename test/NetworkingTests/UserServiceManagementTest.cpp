//
// Created by vinshit on 31/01/19.
//

#include "AccountController.h"
#include "Server.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::Return;

struct UserServiceManagementTEST : testing:: Test {
    AccountController accountController;
    const std::uintptr_t ID1 = rand() % 1000000;
    Connection connection{ID1};
    Connection secondConnection{1};
    Message firstMessage{connection,""};
    Message usernameMessage{connection,"random_name"};
    Message passwordMessage{connection,"random_passworld"};
};

// user logout without logging in
TEST_F(UserServiceManagementTEST, LogoutTest){
  Message message = accountController.logoutUser(firstMessage);
  EXPECT_EQ(ID1, message.connection.id);
  EXPECT_EQ(NOT_LOGIN_MESSAGE, message.text);
}

//user login
TEST_F(UserServiceManagementTEST, LoginTest){
  accountController.connectClient(connection);
  Message userPrompt = accountController.startLogin(firstMessage);

    pair<bool, Message> accountControllerFirstResponse = accountController.respondToMessage(usernameMessage);
    pair<bool, Message> accountControllerSecondResponse = accountController.respondToMessage(passwordMessage);

    ASSERT_EQ(LOGIN_USERNAME_PROMPT, userPrompt.text);
    ASSERT_TRUE(accountControllerFirstResponse.first);
    EXPECT_EQ(LOGIN_PASSWORD_PROMPT, accountControllerFirstResponse.second.text);
    EXPECT_EQ(ID1, accountControllerFirstResponse.second.connection.id);
    ASSERT_TRUE(accountControllerSecondResponse.first);
    EXPECT_EQ(LOGGED_IN_PROMPT, accountControllerSecondResponse.second.text);
    ASSERT_TRUE(accountControllerSecondResponse.second.connection.id);
}

//same user login twice
TEST_F(UserServiceManagementTEST, LoginTwiceTest){
  accountController.connectClient(connection);
  Message userPrompt = accountController.startLogin(firstMessage);

  Message passwordPrompt = accountController.startLogin(usernameMessage);
  pair<bool, Message> accountControllerResponse = accountController.respondToMessage(passwordMessage);

  Message message = accountController.startLogin(usernameMessage);

  ASSERT_EQ(LOGIN_USERNAME_PROMPT, userPrompt.text);
  EXPECT_EQ(LOGIN_PASSWORD_PROMPT, passwordPrompt.text);
  ASSERT_TRUE(accountControllerResponse.first);
  EXPECT_EQ(ID1, accountControllerResponse.second.connection.id);
  EXPECT_EQ(LOGGED_IN_PROMPT, accountControllerResponse.second.text);
  EXPECT_EQ(ALREADY_LOGIN_MESSAGE, message.text);
}

//user login first and logout
TEST_F(UserServiceManagementTEST, LoginlogoutSequenceTest){
  accountController.connectClient(connection);
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
TEST_F(UserServiceManagementTEST, RegisterTest){
    accountController.connectClient(connection);
    Message message = accountController.startRegister(firstMessage);

    pair<bool, Message> accountControllerFirstResponse = accountController.respondToMessage(usernameMessage);
    pair<bool, Message> accountControllerSecondResponse = accountController.respondToMessage(passwordMessage);

    ASSERT_EQ(REGISTER_USERNAME_PROMPT, message.text);
    EXPECT_EQ(ID1, message.connection.id);

    ASSERT_TRUE(accountControllerFirstResponse.first);
    ASSERT_EQ(ID1, accountControllerFirstResponse.second.connection.id);
    ASSERT_EQ(REGISTER_PASSWORD_PROMPT, accountControllerFirstResponse.second.text);

    ASSERT_TRUE(accountControllerSecondResponse.first);
    EXPECT_EQ(ID1, accountControllerSecondResponse.second.connection.id);
    EXPECT_EQ(LOGIN_USERNAME_AFTER_REGISTRATION_PROMPT, accountControllerSecondResponse.second.text);
}

//register withinvalid password



//register after logging in
TEST_F(UserServiceManagementTEST, LoginRegisterTest){
  accountController.connectClient(connection);
  Message userPrompt = accountController.startLogin(firstMessage);

  Message passwordPrompt = accountController.startLogin(usernameMessage);
  pair<bool, Message> accountControllerResponse = accountController.respondToMessage(passwordMessage);

  Message message = accountController.startRegister(usernameMessage);

  ASSERT_EQ(LOGIN_USERNAME_PROMPT, userPrompt.text);
  EXPECT_EQ(LOGIN_PASSWORD_PROMPT, passwordPrompt.text);
  ASSERT_TRUE(accountControllerResponse.first);
  EXPECT_EQ(connection.id, accountControllerResponse.second.connection.id);
  EXPECT_EQ(LOGGED_IN_PROMPT, accountControllerResponse.second.text);
  EXPECT_EQ(LOGOUT_BEFORE_REGISTER_MESSAGE, message.text);
}


//register and excape

TEST_F(UserServiceManagementTEST, RegisterEscapeTest){
    accountController.connectClient(connection);
    Message message = accountController.startRegister(firstMessage);

    Message passwordPrompt = accountController.startLogin(usernameMessage);
    pair<bool, Message> accountControllerResponse = accountController.respondToMessage(passwordMessage);
    Message escapeMessage = accountController.escapeLogin(passwordMessage);


    ASSERT_EQ(REGISTER_USERNAME_PROMPT, message.text);
    EXPECT_EQ(ID1, message.connection.id);
    ASSERT_TRUE(accountControllerResponse.first);
    EXPECT_EQ(ID1, accountControllerResponse.second.connection.id);
    EXPECT_EQ(LOGIN_USERNAME_AFTER_REGISTRATION_PROMPT, accountControllerResponse.second.text);

    EXPECT_EQ(ESCAPE_WHILE_REGISTERING_MESSAGE + to_string(ID1), escapeMessage.text);
}

//login and escape
TEST_F(UserServiceManagementTEST, LoginEscapeTest){
    accountController.connectClient(connection);
    Message userPrompt = accountController.startLogin(firstMessage);

    Message passwordPrompt = accountController.startLogin(usernameMessage);
    pair<bool, Message> accountControllerResponse = accountController.respondToMessage(passwordMessage);
    Message escapeMessage = accountController.escapeLogin(passwordMessage);

    ASSERT_EQ(LOGIN_USERNAME_PROMPT, userPrompt.text);
    EXPECT_EQ(LOGIN_PASSWORD_PROMPT, passwordPrompt.text);
    ASSERT_TRUE(accountControllerResponse.first);
    EXPECT_EQ(ID1, accountControllerResponse.second.connection.id);
    EXPECT_EQ(LOGGED_IN_PROMPT, accountControllerResponse.second.text);
    EXPECT_EQ(LOGGING_IN_ESCAPE_MESSAGE + to_string(ID1), escapeMessage.text);
}

//user escape without logingin
TEST_F(UserServiceManagementTEST, LoginEscape_WithoutLoginTest){
    accountController.connectClient(connection);
    Message userPrompt = accountController.escapeLogin(firstMessage);

    Message escapeMessage = accountController.escapeLogin(firstMessage);
    EXPECT_EQ(ID1, escapeMessage.connection.id);
    EXPECT_EQ(ESCAPE_WHILE_NOT_LOGIN_MESSAGE, escapeMessage.text);
}

//
//
//TEST_F(UserServiceManagementTEST, LoginClientTestWithInitalParam){
//  Message firstMessage{connection,"Rex"};
//  Message passwordMessage{connection,"admin12345"};
//
//  accountController.connectClient(connection);
//  Message passwordPrompt = accountController.promptLogin(firstMessage);
//
//  Message loginSuccessful = accountController.handleInput(passwordMessage);
//
//  EXPECT_TRUE(accountController.isLoggedIn(connection));
//
//  EXPECT_EQ("Please enter your password:", passwordPrompt.text);
//  EXPECT_EQ("Successfully logged in!", loginSuccessful.text);
//}
//
//
//TEST_F(UserServiceManagementTEST, LoginClientTestWithWrongInfo){
//  Message firstMessage{connection,"Rex"};
//  Message passwordMessage{connection,"admin123"};
//
//  accountController.connectClient(connection);
//  Message passwordPrompt = accountController.promptLogin(firstMessage);
//
//  Message loginUnsuccessful = accountController.handleInput(passwordMessage);
//
//  EXPECT_EQ("Please enter your password:", passwordPrompt.text);
//  EXPECT_EQ("Login Unsuccessful\nPlease enter your username again:", loginUnsuccessful.text);
//  EXPECT_FALSE(accountController.isLoggedIn(connection));
//}

///*
// *  isLoggedIn Tests
// */
//
//class LoggedInClientManagerTest : public ::testing::Test {
//public:
//  AccountController clientManager;
//  Connection connection{0};
//  Message firstMessage{connection, "Rex"};
//  Message passwordMessage{connection, "admin12345"};
//protected:
//  virtual void SetUp() override {
//
//    clientManager.connectClient(connection);
//    Message passwordPrompt = clientManager.promptLogin(firstMessage);
//    Message loginSuccessful = clientManager.handleInput(passwordMessage);
//  }
//
//  virtual void TearDown() override {
//  }
//};
//
//TEST_F(LoggedInClientManagerTest, isLoggedInTestTrue){
//  EXPECT_TRUE(clientManager.isLoggedIn(connection));
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
//TEST_F(UserServiceManagementTEST, UsernameTakenClientTest) {
//
//  Message newUsername{connection.id, "SecondBuddy"};
//
//  accountController.connectClient(connection);
//
//  Message userPrompt = accountController.promptRegister(firstMessage);
//  Message usernameTakenPrompt = accountController.handleInput(usernameMessage);
//  Message registerPasswordPrompt = accountController.handleInput(newUsername);
//  Message registerSucessful = accountController.handleInput(passwordMessage);
//
//  EXPECT_FALSE(accountController.isLoggedIn(connection));
//
//  EXPECT_EQ("Please create your username:", userPrompt.text);
//  EXPECT_EQ("Username already exists", usernameTakenPrompt.text);
//  EXPECT_EQ("Please create your password:", registerPasswordPrompt.text);
//  EXPECT_EQ("Account Created! Please re-enter your username:", registerSucessful.text);
//
//  Message passwordPrompt = accountController.promptLogin(newUsername);
//  Message loginSuccessful = accountController.handleInput(passwordMessage);
//
//  EXPECT_TRUE(accountController.isLoggedIn(connection));
//
//  EXPECT_EQ("Please enter your password:", passwordPrompt.text);
//  EXPECT_EQ("Successfully logged in!", loginSuccessful.text);
//}
