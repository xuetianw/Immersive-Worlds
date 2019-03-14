//
// Created by asim on 07/02/19.
//
#include "GameController.h"

//Upon successful login
Message GameController::respondToMessage(const Message& message) {
    User& user = message.user;

    //For now, generate avatar id
    //TODO the avatar id should be retrieved from the database
    ID avatarId = ID{};
    user.getAccount().avatarId = avatarId;

    user.setCommandType(new GameCommands());

    //TODO make user a unique_ptr
    _avatarIdToUser.try_emplace(avatarId, &user);

    string responseText = message.text + spawnAvatarInStartingRoom(avatarId);
    return Message{user, responseText};
}

std::vector<Message> GameController::move(const Message& message) {
    const ID& avatarId = message.user.getAccount().avatarId;
    const std::string& directionString = message.text;
    Message responseMessage{message.user};

    bool didMoveAvatar = _gameService.moveAvatar(avatarId, directionString);

    if (didMoveAvatar) {
        std::optional<std::string> newAvatarRoomName = _gameService.getAvatarRoomName(avatarId);
        responseMessage.text = "Successfully moved " + directionString + " to room: " + newAvatarRoomName.value();
    } else {
        responseMessage.text = "Failed to move avatar " + directionString;
    }

    return std::vector<Message>{responseMessage};
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


std::vector<Message> GameController::say(const Message& message) {

    std::string sayMessage = message.user.getAccount()._username + " says: " + message.text;

    //retrieve the room the sender avatar is in.
    ID roomId = _gameService.getRoomId(message.user.getAccount().avatarId);

    std::vector<Message> responses;
    std::vector<ID> avatarIds = _gameService.getAllAvatarIds(roomId);
    for(const ID& id : avatarIds) {
        User* user = findUser(id);
        if(user == nullptr) continue;
        responses.push_back(Message{*user, sayMessage});
    }
    return responses;
}


User* GameController::findUser(const ID& avatarId){
    if(_avatarIdToUser.count(avatarId) == 0){
        return nullptr;
    }
    //return user associated with ID
    return _avatarIdToUser[avatarId];
};