//
// Created by asim on 07/02/19.
//
#include "GameController.h"

Message GameController::respondToMessage(const Message& message) {
    User& user = message.user;
    ID avatarId = ID{};

    user.setCommandType(new GameCommands());

    //Assign account a new avatar ID
    user.getAccount().avatarId = avatarId;

    //TODO make user a unique_ptr
    _avatarIdToUser.try_emplace(avatarId, &user);

    string responseText = message.text + spawnAvatarInStartingRoom(avatarId);
    return Message{user, responseText};
}

std::vector<Message> GameController::move(const Message& message) {
    Message newMessage = Message(message.user);
    if (!checkIsDirectionMessage(message)) {
        newMessage.text = WRONG_DIRECTION_MESSAGE;
        return std::vector<Message>{newMessage};
    }

    std::string beforeMoveRoomName = _gameService.getCurrentRoomName(message.user.getConnection());
    if (_gameService.moveUser(message.user, message.text)) {
        std::string afterMoveRoomName = _gameService.getCurrentRoomName(message.user.getConnection());
        std::string output = "command /move " + message.text + " called\n" + "before move: " + beforeMoveRoomName + "\nafter move: " + afterMoveRoomName;
        newMessage.text = output;
    } else {
        newMessage.text = "user did not move";
    }

    return std::vector<Message>{newMessage};
}

//TODO pass in avatar name
const std::string GameController::spawnAvatarInStartingRoom(const ID& avatarId) {
    if (_gameService.spawnAvatarInStartingRoom(avatarId)) {
        return INITIAL_ROOM_START_MESSAGE;
    } else {
        return ROOM_SPAWN_FAIL_MESSAGE;
    }
}

std::vector<Message> GameController::startMiniGame(const Message& message) {
    bool hasMiniGame = _gameService.roomHaveMiniGame(message.user);

    Message newMessage = Message(message.user);
    if(hasMiniGame) {
        auto minigame = _gameService.getMiniGame(message.user, message.text);

        newMessage.text = minigame.printQuestion();
    } else {
        newMessage.text = "MiniGame not available for this room";
    }

    return std::vector<Message>{newMessage};
}


std::vector<Message> GameController::verifyMinigameAnswer(const Message& message) {
    // TODO: figure out a better way to get the input. EX. maybe they type a number, should throw error or something
    char letter = (message.text).at(0);
    int input = letter - 'a';

    bool result = _gameService.verifyAnswer(message.user, input);

    Message newMessage = Message(message.user, (result) ? "Correct" : "WRONG");
    return std::vector<Message>{newMessage};
}


void GameController::spawnUserInRoom(User& user, ID roomId) {
    _gameService.spawnUserInRoom(user.getConnection(), roomId);
}

bool GameController::checkIsDirectionMessage(const Message& message) {
    std::vector<std::string>::iterator it;
    it = std::find(directions.begin(), directions.end(), message.text);
    return it != directions.end();
}

std::vector<Message> GameController::outputCurrentLocationInfo(const Message& message) {
    const Connection& currentConnection = message.user.getConnection();
    string currentRoom = _gameService.getCurrentRoomName(currentConnection);
    string responseText = USER_CURRENTLY_LOCATED_MESSAGE + currentRoom;

    std::vector<Message> response { Message{message.user, responseText} };

    return response;
}
