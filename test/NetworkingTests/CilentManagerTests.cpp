//
// Created by vinshit on 31/01/19.
//

#include "UserController.h"
#include "Server.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::Return;

//struct BasicClientManagerTest : testing:: Test {
//    UserController userController;
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
//  userController.connectClient(firstConnection);
//  Message message = userController.logoutClient(firstConnection);
//  EXPECT_EQ(firstConnection, message.connection);
//  EXPECT_EQ("User not logged in!\n", message.text);
//}
//
///*
// * Login tests
// */
//
//TEST_F(BasicClientManagerTest, LoginClientTestWithoutInitalParam){
//  userController.connectClient(firstConnection);
//  Message userPrompt = userController.promptLogin(firstMessage);
//
//  Message passwordPrompt = userController.promptLogin(usernameMessage);
//  Message loginSuccessful = userController.handleInput(passwordMessage);
//
//  EXPECT_TRUE(userController.isLoggedIn(firstConnection));
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
//  userController.connectClient(firstConnection);
//  Message passwordPrompt = userController.promptLogin(firstMessage);
//
//  Message loginSuccessful = userController.handleInput(passwordMessage);
//
//  EXPECT_TRUE(userController.isLoggedIn(firstConnection));
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
//  userController.connectClient(firstConnection);
//  Message passwordPrompt = userController.promptLogin(firstMessage);
//
//  Message loginUnsuccessful = userController.handleInput(passwordMessage);
//
//  EXPECT_EQ("Please enter your password:", passwordPrompt.text);
//  EXPECT_EQ("Login Unsuccessful\nPlease enter your username again:", loginUnsuccessful.text);
//  EXPECT_FALSE(userController.isLoggedIn(firstConnection));
//}

///*
// *  isLoggedIn Tests
// */
//
//class LoggedInClientManagerTest : public ::testing::Test {
//public:
//  UserController clientManager;
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
//  userController.connectClient(firstConnection);
//
//  Message userPrompt = userController.promptRegister(firstMessage);
//  Message usernameTakenPrompt = userController.handleInput(usernameMessage);
//  Message registerPasswordPrompt = userController.handleInput(newUsername);
//  Message registerSucessful = userController.handleInput(passwordMessage);
//
//  EXPECT_FALSE(userController.isLoggedIn(firstConnection));
//
//  EXPECT_EQ("Please create your username:", userPrompt.text);
//  EXPECT_EQ("Username already exists", usernameTakenPrompt.text);
//  EXPECT_EQ("Please create your password:", registerPasswordPrompt.text);
//  EXPECT_EQ("Account Created! Please re-enter your username:", registerSucessful.text);
//
//  Message passwordPrompt = userController.promptLogin(newUsername);
//  Message loginSuccessful = userController.handleInput(passwordMessage);
//
//  EXPECT_TRUE(userController.isLoggedIn(firstConnection));
//
//  EXPECT_EQ("Please enter your password:", passwordPrompt.text);
//  EXPECT_EQ("Successfully logged in!", loginSuccessful.text);
//}
