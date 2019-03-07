//
// Created by vinshit on 31/01/19.
//

#include "AccountController.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::Return;
using namespace std;

struct UserServiceManagementTest : testing:: Test {
    AccountController accountController;
    const std::uintptr_t ID1 = static_cast<unsigned int>(rand()) % 1000000;
    Connection connection{ID1};
    Connection secondConnection{1};
    User user{connection};
    User secondUser{secondConnection};
    Message firstMessage{user,""};
    Message usernameMessage{user,"random_name"};
    Message passwordMessage{user,"random_passworld"};
};

// user logout without logging in
TEST_F(UserServiceManagementTest, LogoutWithoutLoggingInTest){
  Message message = accountController.logoutUser(firstMessage).front();
  EXPECT_EQ(ID1, message.user.getConnection().id);
  EXPECT_EQ(NOT_LOGIN_MESSAGE, message.text);
}

//user login
TEST_F(UserServiceManagementTest, LoginTest){
    user.reset();
    Message userPrompt = accountController.startLogin(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(usernameMessage);
    Message accountControllerSecondResponse = accountController.respondToMessage(passwordMessage);

    ASSERT_EQ(ID1, userPrompt.user.getConnection().id);
    ASSERT_EQ(LOGIN_USERNAME_PROMPT, userPrompt.text);

    EXPECT_EQ(LOGIN_PASSWORD_PROMPT, accountControllerFirstResponse.text);
    EXPECT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);

    ASSERT_TRUE(accountControllerSecondResponse.text.find(LOGGED_IN_PROMPT) != string::npos);
    ASSERT_TRUE(accountControllerSecondResponse.user.getConnection().id == ID1);
}

//same user login twice
TEST_F(UserServiceManagementTest, LoginTwiceTest){
    user.reset();
    Message userPrompt = accountController.startLogin(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(usernameMessage);
    Message accountControllerSecondResponse = accountController.respondToMessage(passwordMessage);

    ASSERT_EQ(ID1, userPrompt.user.getConnection().id);
    ASSERT_EQ(LOGIN_USERNAME_PROMPT, userPrompt.text);

    ASSERT_EQ(LOGIN_PASSWORD_PROMPT, accountControllerFirstResponse.text);
    ASSERT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);

    ASSERT_TRUE(accountControllerSecondResponse.text.find(LOGGED_IN_PROMPT) != string::npos);
    ASSERT_TRUE(accountControllerSecondResponse.user.getConnection().id == ID1);

    Message secondPrompt = accountController.startLogin(firstMessage).front();
    EXPECT_EQ(ID1, secondPrompt.user.getConnection().id);
    EXPECT_EQ(ALREADY_LOGIN_MESSAGE, secondPrompt.text);
}

//user login first and logout
TEST_F(UserServiceManagementTest, LoginLogoutSequenceTest){
    user.reset();
    Message userPrompt = accountController.startLogin(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(usernameMessage);
    Message accountControllerSecondResponse = accountController.respondToMessage(passwordMessage);

    ASSERT_EQ(ID1, userPrompt.user.getConnection().id);
    ASSERT_EQ(LOGIN_USERNAME_PROMPT, userPrompt.text);

    ASSERT_EQ(LOGIN_PASSWORD_PROMPT, accountControllerFirstResponse.text);
    ASSERT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);

    ASSERT_TRUE(accountControllerSecondResponse.text.find(LOGGED_IN_PROMPT) != string::npos);
    ASSERT_TRUE(accountControllerSecondResponse.user.getConnection().id == ID1);

    Message message = accountController.logoutUser(firstMessage).front();
    EXPECT_EQ(ID1, message.user.getConnection().id);
    EXPECT_EQ(LOGOUT_MESSAGE, message.text);
}

//register without logging in
TEST_F(UserServiceManagementTest, RegisterTest){
    user.reset();
    Message message = accountController.startRegister(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(usernameMessage);
    Message accountControllerSecondResponse = accountController.respondToMessage(passwordMessage);

    ASSERT_EQ(REGISTER_USERNAME_PROMPT, message.text);
    EXPECT_EQ(ID1, message.user.getConnection().id);

    ASSERT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);
    ASSERT_EQ(REGISTER_PASSWORD_PROMPT, accountControllerFirstResponse.text);

    EXPECT_EQ(ID1, accountControllerSecondResponse.user.getConnection().id);
    EXPECT_EQ(LOGIN_USERNAME_AFTER_REGISTRATION_PROMPT, accountControllerSecondResponse.text);
}

//register with invalid password



//register after logging in
TEST_F(UserServiceManagementTest, LoginRegisterTest){
    user.reset();
    Message userPrompt = accountController.startLogin(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(usernameMessage);
    Message accountControllerSecondResponse = accountController.respondToMessage(passwordMessage);


    ASSERT_EQ(ID1, userPrompt.user.getConnection().id);
    ASSERT_EQ(LOGIN_USERNAME_PROMPT, userPrompt.text);

    ASSERT_EQ(LOGIN_PASSWORD_PROMPT, accountControllerFirstResponse.text);
    ASSERT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);

    ASSERT_TRUE(accountControllerSecondResponse.text.find(LOGGED_IN_PROMPT) != string::npos);
    ASSERT_TRUE(accountControllerSecondResponse.user.getConnection().id == ID1);

    Message message = accountController.startRegister(firstMessage).front();
    EXPECT_EQ(LOGOUT_BEFORE_REGISTER_MESSAGE, message.text);
}


//register and excape

TEST_F(UserServiceManagementTest, RegisterEscapeTest){
    user.reset();
    Message message = accountController.startRegister(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(usernameMessage);

    ASSERT_EQ(REGISTER_USERNAME_PROMPT, message.text);
    ASSERT_EQ(ID1, message.user.getConnection().id);

    ASSERT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);
    ASSERT_EQ(REGISTER_PASSWORD_PROMPT, accountControllerFirstResponse.text);

    Message escapeMessage = accountController.escapeLogin(passwordMessage).front();
    EXPECT_EQ(ESCAPE_WHILE_REGISTERING_MESSAGE + to_string(ID1), escapeMessage.text);
}

//login and escape
TEST_F(UserServiceManagementTest, LoginEscapeTest){
    user.reset();
    Message userPrompt = accountController.startLogin(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(usernameMessage);

    ASSERT_EQ(ID1, userPrompt.user.getConnection().id);
    ASSERT_EQ(LOGIN_USERNAME_PROMPT, userPrompt.text);

    ASSERT_EQ(LOGIN_PASSWORD_PROMPT, accountControllerFirstResponse.text);
    ASSERT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);

    Message escapeMessage = accountController.escapeLogin(passwordMessage).front();
    EXPECT_EQ(LOGGING_IN_ESCAPE_MESSAGE + to_string(ID1), escapeMessage.text);
}

//user escape without logingin
TEST_F(UserServiceManagementTest, LoginEscape_WithoutLoginTest){
    user.reset();
    Message escapeMessage = accountController.escapeLogin(firstMessage).front();
    EXPECT_EQ(ID1, escapeMessage.user.getConnection().id);
    EXPECT_EQ(ESCAPE_WHILE_NOT_LOGIN_MESSAGE, escapeMessage.text);
}

//
//
//TEST_F(UserServiceManagementTest, LoginClientTestWithInitalParam){
//  ServerMessage firstMessage{connection,"Rex"};
//  ServerMessage passwordMessage{connection,"admin12345"};
//
//  accountController.connectClient(connection);
//  ServerMessage passwordPrompt = accountController.promptLogin(firstMessage);
//
//  ServerMessage loginSuccessful = accountController.handleInput(passwordMessage);
//
//  EXPECT_TRUE(accountController.isLoggedIn(connection));
//
//  EXPECT_EQ("Please enter your password:", passwordPrompt.text);
//  EXPECT_EQ("Successfully logged in!", loginSuccessful.text);
//}
//
//
//TEST_F(UserServiceManagementTest, LoginClientTestWithWrongInfo){
//  ServerMessage firstMessage{connection,"Rex"};
//  ServerMessage passwordMessage{connection,"admin123"};
//
//  accountController.connectClient(connection);
//  ServerMessage passwordPrompt = accountController.promptLogin(firstMessage);
//
//  ServerMessage loginUnsuccessful = accountController.handleInput(passwordMessage);
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
//  ServerMessage firstMessage{connection, "Rex"};
//  ServerMessage passwordMessage{connection, "admin12345"};
//protected:
//  virtual void SetUp() override {
//
//    clientManager.connectClient(connection);
//    ServerMessage passwordPrompt = clientManager.promptLogin(firstMessage);
//    ServerMessage loginSuccessful = clientManager.handleInput(passwordMessage);
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
//TEST_F(UserServiceManagementTest, UsernameTakenClientTest) {
//
//  ServerMessage newUsername{getConnection().id, "SecondBuddy"};
//
//  accountController.connectClient(connection);
//
//  ServerMessage userPrompt = accountController.promptRegister(firstMessage);
//  ServerMessage usernameTakenPrompt = accountController.handleInput(usernameMessage);
//  ServerMessage registerPasswordPrompt = accountController.handleInput(newUsername);
//  ServerMessage registerSucessful = accountController.handleInput(passwordMessage);
//
//  EXPECT_FALSE(accountController.isLoggedIn(connection));
//
//  EXPECT_EQ("Please create your username:", userPrompt.text);
//  EXPECT_EQ("Username already exists", usernameTakenPrompt.text);
//  EXPECT_EQ("Please create your password:", registerPasswordPrompt.text);
//  EXPECT_EQ("Account Created! Please re-enter your username:", registerSucessful.text);
//
//  ServerMessage passwordPrompt = accountController.promptLogin(newUsername);
//  ServerMessage loginSuccessful = accountController.handleInput(passwordMessage);
//
//  EXPECT_TRUE(accountController.isLoggedIn(connection));
//
//  EXPECT_EQ("Please enter your password:", passwordPrompt.text);
//  EXPECT_EQ("Successfully logged in!", loginSuccessful.text);
//}
