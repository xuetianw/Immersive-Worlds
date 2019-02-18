//
// Created by vinshit on 31/01/19.
//

#include "AccountController.h"
#include "Server.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::Return;

//struct BasicClientManagerTest : testing:: Test {
//    AccountController accountController;
//    Connection firstConnection{0};
//    Connection secondConnection{1};
//    Message firstMessage{firstConnection,""};
//    Message usernameMessage{firstConnection,"Rex"};
//    Message passwordMessage{firstConnection,"admin12345"};
//};

///*
// * Logging out
// */
//
//TEST_F(BasicClientManagerTest, LogoutClientTest){
//  accountController.connectClient(firstConnection);
//  Message message = accountController.logoutClient(firstConnection);
//  EXPECT_EQ(firstConnection, message.connection);
//  EXPECT_EQ("User not logged in!\n", message.text);
//}
//
///*
// * Login tests
// */
//
//TEST_F(BasicClientManagerTest, LoginClientTestWithoutInitalParam){
//  accountController.connectClient(firstConnection);
//  Message userPrompt = accountController.promptLogin(firstMessage);
//
//  Message passwordPrompt = accountController.promptLogin(usernameMessage);
//  Message loginSuccessful = accountController.handleInput(passwordMessage);
//
//  EXPECT_TRUE(accountController.isLoggedIn(firstConnection));
//
//  EXPECT_EQ("Please enter your username:", userPrompt.text);
//  EXPECT_EQ("Please enter your password:", passwordPrompt.text);
//  EXPECT_EQ("Successfully logged in!", loginSuccessful.text);
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
