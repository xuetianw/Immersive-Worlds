//
// Created by vinshit on 31/01/19.
//

#include "AccountController.h"
#include "DBUtil.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::Return;
using namespace std;

constexpr char DBNAME[] = "testAdventure.db";

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
    Message usernameExistsMessage{user, "Melody"};
    Message usernameNotExistsMessage{user, "username"};
    Message registerPasswordMessage{user, "random_password"};
    Message emptyPassword{user, ""};

    void SetUp() override {
        remove(DBNAME);
        DBUtil::openConnection(DBNAME);

        DBUtil::registerUser("Josh", "abcdefg");
        DBUtil::registerUser("Karan", "hijklmn");
        DBUtil::registerUser("Melody", "bafhsbsa");
    }

    void TearDown() override {
        remove(DBNAME);
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
    user.resetAllowedCommands();
    Message userPrompt = accountController.startLogin(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(loginUsernameMessage).front();
    Message accountControllerSecondResponse = accountController.respondToMessage(loginPasswordMessage).front();

    ASSERT_EQ(ID1, userPrompt.user.getConnection().id);
    ASSERT_EQ(LOGIN_USERNAME_PROMPT, userPrompt.text);

    EXPECT_EQ(LOGIN_PASSWORD_PROMPT, accountControllerFirstResponse.text);
    EXPECT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);

    ASSERT_TRUE(accountControllerSecondResponse.text.find(LOGGED_IN_PROMPT) != string::npos);
    ASSERT_TRUE(accountControllerSecondResponse.user.getConnection().id == ID1);
}

//same user login twice
TEST_F(AccountControllerTests, LoginTwiceTest){
    user.resetAllowedCommands();
    Message userPrompt = accountController.startLogin(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(loginUsernameMessage).front();
    Message accountControllerSecondResponse = accountController.respondToMessage(loginPasswordMessage).front();

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
    user.resetAllowedCommands();
    Message userPrompt = accountController.startLogin(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(loginUsernameMessage).front();
    Message accountControllerSecondResponse = accountController.respondToMessage(loginPasswordMessage).front();

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
    user.resetAllowedCommands();
    Message message = accountController.startRegister(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(registerUsernameMessage).front();
    Message accountControllerSecondResponse = accountController.respondToMessage(registerPasswordMessage).front();

    ASSERT_EQ(REGISTER_USERNAME_PROMPT, message.text);
    EXPECT_EQ(ID1, message.user.getConnection().id);

    ASSERT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);
    ASSERT_EQ(REGISTER_PASSWORD_PROMPT, accountControllerFirstResponse.text);

    EXPECT_EQ(ID1, accountControllerSecondResponse.user.getConnection().id);
    EXPECT_EQ(ENTER_AVATAR_NAME_AFTER_REGISTRATION_PROMPT, accountControllerSecondResponse.text);
}

//login with non-existing username
TEST_F(AccountControllerTests, LoginWhenUsernameExists) {
    user.resetAllowedCommands();
    Message message = accountController.startLogin(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(usernameNotExistsMessage).front();

    ASSERT_EQ(LOGIN_USERNAME_PROMPT, message.text);
    EXPECT_EQ(ID1, message.user.getConnection().id);

    ASSERT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);
    string expected;
    expected = expected + EMPTY_INPUT_PROMPT + LOGIN_USERNAME_FAILED_PROMPT;
    ASSERT_EQ(expected, accountControllerFirstResponse.text);
}

//login with invalid password
TEST_F(AccountControllerTests, LoginWithEmptyPassword) {
    user.resetAllowedCommands();
    Message message = accountController.startLogin(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(loginUsernameMessage).front();
    Message accountControllerSecondResponse = accountController.respondToMessage(emptyPassword).front();

    ASSERT_EQ(LOGIN_USERNAME_PROMPT, message.text);
    EXPECT_EQ(ID1, message.user.getConnection().id);

    ASSERT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);
    ASSERT_EQ(LOGIN_PASSWORD_PROMPT, accountControllerFirstResponse.text);

    EXPECT_EQ(ID1, accountControllerSecondResponse.user.getConnection().id);
    string expected;
    expected = expected + EMPTY_INPUT_PROMPT + LOGIN_PASSWORD_FAILED_PROMPT;
    EXPECT_EQ(expected, accountControllerSecondResponse.text);
}

//register with already existing username
TEST_F(AccountControllerTests, RegisterWhenUsernameExists) {
    user.resetAllowedCommands();
    Message message = accountController.startRegister(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(usernameExistsMessage).front();

    ASSERT_EQ(REGISTER_USERNAME_PROMPT, message.text);
    EXPECT_EQ(ID1, message.user.getConnection().id);

    ASSERT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);
    ASSERT_EQ(REGISTER_USERNAME_FAILED_PROMPT, accountControllerFirstResponse.text);
}

//register with invalid password
TEST_F(AccountControllerTests, RegisterWithEmptyPassword) {
    user.resetAllowedCommands();
    Message message = accountController.startRegister(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(registerUsernameMessage).front();
    Message accountControllerSecondResponse = accountController.respondToMessage(emptyPassword).front();

    ASSERT_EQ(REGISTER_USERNAME_PROMPT, message.text);
    EXPECT_EQ(ID1, message.user.getConnection().id);

    ASSERT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);
    ASSERT_EQ(REGISTER_PASSWORD_PROMPT, accountControllerFirstResponse.text);

    EXPECT_EQ(ID1, accountControllerSecondResponse.user.getConnection().id);
    string expected;
    expected = expected + EMPTY_INPUT_PROMPT + REGISTER_PASSWORD_FAILED_PROMPT;
    EXPECT_EQ(expected, accountControllerSecondResponse.text);
}

//register after logging in
TEST_F(AccountControllerTests, LoginRegisterTest){
    user.resetAllowedCommands();
    Message userPrompt = accountController.startLogin(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(loginUsernameMessage).front();
    Message accountControllerSecondResponse = accountController.respondToMessage(loginPasswordMessage).front();


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
    user.resetAllowedCommands();
    Message message = accountController.startRegister(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(registerUsernameMessage).front();

    ASSERT_EQ(REGISTER_USERNAME_PROMPT, message.text);
    ASSERT_EQ(ID1, message.user.getConnection().id);

    ASSERT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);
    ASSERT_EQ(REGISTER_PASSWORD_PROMPT, accountControllerFirstResponse.text);

    Message escapeMessage = accountController.escapeLogin(loginPasswordMessage).front();
    EXPECT_EQ(ESCAPE_WHILE_REGISTERING_MESSAGE, escapeMessage.text);
}

//login and escape
TEST_F(AccountControllerTests, LoginEscapeTest){
    user.resetAllowedCommands();
    Message userPrompt = accountController.startLogin(firstMessage).front();

    Message accountControllerFirstResponse = accountController.respondToMessage(loginUsernameMessage).front();

    ASSERT_EQ(ID1, userPrompt.user.getConnection().id);
    ASSERT_EQ(LOGIN_USERNAME_PROMPT, userPrompt.text);

    ASSERT_EQ(LOGIN_PASSWORD_PROMPT, accountControllerFirstResponse.text);
    ASSERT_EQ(ID1, accountControllerFirstResponse.user.getConnection().id);

    Message escapeMessage = accountController.escapeLogin(loginPasswordMessage).front();
    EXPECT_EQ(LOGGING_IN_ESCAPE_MESSAGE, escapeMessage.text);
}

//user escape without loggingin
TEST_F(AccountControllerTests, LoginEscape_WithoutLoginTest){
    user.resetAllowedCommands();
    Message escapeMessage = accountController.escapeLogin(firstMessage).front();
    EXPECT_EQ(ID1, escapeMessage.user.getConnection().id);
    EXPECT_EQ(INVALID_INPUT_PROMPT, escapeMessage.text);
}
