//
// Created by vinshit on 31/01/19.
//

#include "AccountController.h"
#include "DBUtil.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::Return;
using namespace std;

struct AccountControllerTests : testing:: Test {
    AccountController accountController;
    const std::uintptr_t ID1 = static_cast<unsigned int>(rand()) % 1000000;
    Connection connection{ID1};
    Connection secondConnection{1};
    User user{connection};
    User secondUser{secondConnection};
    Message firstMessage{user,"/login"};
    Message loginUsernameMessage{user,"Josh"};
    Message loginPasswordMessage{user,"abcdefg"};
    Message registerUsernameMessage{user, "random_username"};
    Message registerUsernameExistsMessage{user, "Melody"};
    Message registerPasswordMessage{user, "random_password"};
    Message registerWithEmptyPassword{user, ""};

    void SetUp() override {
        remove("testAdventure.db");
        DBUtil::openConnection("testAdventure.db");

        DBUtil::registerUser("Josh", "abcdefg");
        DBUtil::registerUser("Karan", "hijklmn");
        DBUtil::registerUser("Melody", "bafhsbsa");
        DBUtil::registerUser("Link", "masterSword");
        DBUtil::registerUser("abc", "abc");
    }

    void TearDown() override {
        remove("testAdventure.db");
        DBUtil::closeConnection();
    }
};

// user logout without logging in
TEST_F(AccountControllerTests, LogoutWithoutLoggingInTest){
  Message message = accountController.logoutUser(firstMessage).front();
  EXPECT_EQ(ID1, message.user.getConnection().id);
  EXPECT_EQ(INVALID_INPUT_PROMPT, message.text);
}

//user login
TEST_F(AccountControllerTests, LoginTest){
    user.reset();
    Message userPrompt = accountController.startLogin(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(loginUsernameMessage);
    Message accountControllerSecondResponse = accountController.respondToMessage(loginPasswordMessage);

    ASSERT_EQ(ID1, userPrompt.user.getConnection().id);
    ASSERT_EQ(LOGIN_USERNAME_PROMPT, userPrompt.text);

    EXPECT_EQ(LOGIN_PASSWORD_PROMPT, accountControllerFirstResponse.text);
    EXPECT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);

    ASSERT_TRUE(accountControllerSecondResponse.text.find(LOGGED_IN_PROMPT) != string::npos);
    ASSERT_TRUE(accountControllerSecondResponse.user.getConnection().id == ID1);
}

//same user login twice
TEST_F(AccountControllerTests, LoginTwiceTest){
    user.reset();
    Message userPrompt = accountController.startLogin(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(loginUsernameMessage);
    Message accountControllerSecondResponse = accountController.respondToMessage(loginPasswordMessage);

    ASSERT_EQ(ID1, userPrompt.user.getConnection().id);
    ASSERT_EQ(LOGIN_USERNAME_PROMPT, userPrompt.text);

    ASSERT_EQ(LOGIN_PASSWORD_PROMPT, accountControllerFirstResponse.text);
    ASSERT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);

    ASSERT_TRUE(accountControllerSecondResponse.text.find(LOGGED_IN_PROMPT) != string::npos);
    ASSERT_TRUE(accountControllerSecondResponse.user.getConnection().id == ID1);

    Message secondPrompt = accountController.startLogin(firstMessage).front();
    EXPECT_EQ(ID1, secondPrompt.user.getConnection().id);
    EXPECT_EQ(INVALID_INPUT_PROMPT, secondPrompt.text);
}

//user login first and logout
TEST_F(AccountControllerTests, LoginLogoutSequenceTest){
    user.reset();
    Message userPrompt = accountController.startLogin(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(loginUsernameMessage);
    Message accountControllerSecondResponse = accountController.respondToMessage(loginPasswordMessage);

    ASSERT_EQ(ID1, userPrompt.user.getConnection().id);
    ASSERT_EQ(LOGIN_USERNAME_PROMPT, userPrompt.text);

    ASSERT_EQ(LOGIN_PASSWORD_PROMPT, accountControllerFirstResponse.text);
    ASSERT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);

    ASSERT_TRUE(accountControllerSecondResponse.text.find(LOGGED_IN_PROMPT) != string::npos);
    ASSERT_TRUE(accountControllerSecondResponse.user.getConnection().id == ID1);

    Message message = accountController.logoutUser(firstMessage).front();
    EXPECT_EQ(ID1, message.user.getConnection().id);
    EXPECT_EQ(LOGGED_OUT_PROMPT, message.text);
}

//register without logging in
TEST_F(AccountControllerTests, RegisterTest){
    user.reset();
    Message message = accountController.startRegister(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(registerUsernameMessage);
    Message accountControllerSecondResponse = accountController.respondToMessage(registerPasswordMessage);

    ASSERT_EQ(REGISTER_USERNAME_PROMPT, message.text);
    EXPECT_EQ(ID1, message.user.getConnection().id);

    ASSERT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);
    ASSERT_EQ(REGISTER_PASSWORD_PROMPT, accountControllerFirstResponse.text);

    EXPECT_EQ(ID1, accountControllerSecondResponse.user.getConnection().id);
    EXPECT_EQ(LOGIN_USERNAME_AFTER_REGISTRATION_PROMPT, accountControllerSecondResponse.text);
}

//register with already existing username
TEST_F(AccountControllerTests, RegisterWith) {
    user.reset();
    Message message = accountController.startRegister(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(registerUsernameExistsMessage);

    ASSERT_EQ(REGISTER_USERNAME_PROMPT, message.text);
    EXPECT_EQ(ID1, message.user.getConnection().id);

    ASSERT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);
    ASSERT_EQ(REGISTER_USERNAME_FAILED_PROMPT, accountControllerFirstResponse.text);
}

//register with invalid password
TEST_F(AccountControllerTests, RegisterWithEmptyPassword) {
    user.reset();
    Message message = accountController.startRegister(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(registerWithEmptyPassword);

    ASSERT_EQ(REGISTER_USERNAME_PROMPT, message.text);
    EXPECT_EQ(ID1, message.user.getConnection().id);

    ASSERT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);
    ASSERT_EQ(REGISTER_USERNAME_FAILED_PROMPT, accountControllerFirstResponse.text);
}

//register after logging in
TEST_F(AccountControllerTests, LoginRegisterTest){
    user.reset();
    Message userPrompt = accountController.startLogin(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(loginUsernameMessage);
    Message accountControllerSecondResponse = accountController.respondToMessage(loginPasswordMessage);


    ASSERT_EQ(ID1, userPrompt.user.getConnection().id);
    ASSERT_EQ(LOGIN_USERNAME_PROMPT, userPrompt.text);

    ASSERT_EQ(LOGIN_PASSWORD_PROMPT, accountControllerFirstResponse.text);
    ASSERT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);

    ASSERT_TRUE(accountControllerSecondResponse.text.find(LOGGED_IN_PROMPT) != string::npos);
    ASSERT_TRUE(accountControllerSecondResponse.user.getConnection().id == ID1);

    Message message = accountController.startRegister(firstMessage).front();
    EXPECT_EQ(INVALID_INPUT_PROMPT, message.text);
}


//register and escape
TEST_F(AccountControllerTests, RegisterEscapeTest){
    user.reset();
    Message message = accountController.startRegister(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(registerUsernameMessage);

    ASSERT_EQ(REGISTER_USERNAME_PROMPT, message.text);
    ASSERT_EQ(ID1, message.user.getConnection().id);

    ASSERT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);
    ASSERT_EQ(REGISTER_PASSWORD_PROMPT, accountControllerFirstResponse.text);

    Message escapeMessage = accountController.escapeLogin(loginPasswordMessage).front();
    EXPECT_EQ(ESCAPE_WHILE_REGISTERING_MESSAGE, escapeMessage.text);
}

//login and escape
TEST_F(AccountControllerTests, LoginEscapeTest){
    user.reset();
    Message userPrompt = accountController.startLogin(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(loginUsernameMessage);

    ASSERT_EQ(ID1, userPrompt.user.getConnection().id);
    ASSERT_EQ(LOGIN_USERNAME_PROMPT, userPrompt.text);

    ASSERT_EQ(LOGIN_PASSWORD_PROMPT, accountControllerFirstResponse.text);
    ASSERT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);

    Message escapeMessage = accountController.escapeLogin(loginPasswordMessage).front();
    EXPECT_EQ(LOGGING_IN_ESCAPE_MESSAGE, escapeMessage.text);
}

//user escape without logingin
TEST_F(AccountControllerTests, LoginEscape_WithoutLoginTest){
    user.reset();
    Message escapeMessage = accountController.escapeLogin(firstMessage).front();
    EXPECT_EQ(ID1, escapeMessage.user.getConnection().id);
    EXPECT_EQ(INVALID_INPUT_PROMPT, escapeMessage.text);
}
