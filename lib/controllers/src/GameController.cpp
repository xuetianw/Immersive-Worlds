//
// Created by asim on 07/02/19.
//

#include "GameController.h"
#include "Helper.h"

//Upon successful login
std::vector<Message> GameController::onLogin(Message& message) {
    User& user = message.user;

    //For now, generate avatar id
    //TODO the avatar id should be retrieved from the database
    ID avatarId = ID();
    user.getAccount().avatarId = avatarId;

    // TODO make user a unique_ptr
    _avatarIdToUser.try_emplace(avatarId, &user);

    // Transition from AccountState to GameState allowing the user to perform game commands
    user.setCommandType(new GameCommands());

    message.text += spawnAvatarInStartingRoom(avatarId);
    return std::vector<Message> { message };
}

std::vector<Message> GameController::respondToMessage(const Message& message) {
    return std::vector<Message> { Message {message.user, INVALID_GAME_COMMAND} };
}

std::vector<Message> GameController::move(const Message& message) {
    const ID& avatarId = message.user.getAccount().avatarId;
    const std::string& directionString = message.text;
    Message responseMessage{message.user};

    bool didMoveAvatar = _gameActions.moveAvatar(avatarId, directionString);

    if (didMoveAvatar) {
        std::optional<std::string> newAvatarRoomName = _gameActions.getAvatarRoomName(avatarId);
        responseMessage.text = "Successfully moved " + directionString + " to room: " + newAvatarRoomName.value();
    } else {
        responseMessage.text = "Failed to move avatar " + directionString;
    }

    return std::vector<Message>{responseMessage};
}

std::vector<Message> GameController::listDirections(const Message& message) {
    const ID& avatarId = message.user.getAccount().avatarId;
    Message responseMessage{message.user};
    string responseText = "Available directions are: ";

    std::vector<string> directionStrings = _gameActions.getDirectionsForAvatarId(avatarId);

    responseText += helper::convertListToString(directionStrings);

    responseMessage.text = responseText;

    return std::vector<Message>{responseMessage};
};

const std::string GameController::spawnAvatarInStartingRoom(const ID& avatarId) {
    if (_gameActions.spawnAvatarInStartingRoom(avatarId)) {
        return INITIAL_ROOM_START_MESSAGE;
    } else {
        return ROOM_SPAWN_FAIL_MESSAGE;
    }
}

std::vector<Message> GameController::startMiniGame(const Message& message) {
    User& user = message.user;
    auto roomID = _gameActions.getRoomId(message.user.getAvatarId());
    bool hasMiniGame = _miniGameActions.roomHaveMiniGame(roomID);

    Message newMessage = Message(message.user);
    if(hasMiniGame) {
        auto minigame = _miniGameActions.getMiniGame(roomID);
        newMessage.text = minigame.printQuestion();
        user.setCommandType(new MinigameCommands());
    } else {
        newMessage.text = "MiniGame not available for this room";
    }

    return std::vector<Message>{newMessage};
}

std::vector<Message> GameController::nextRound(const Message& message) {
    // for testing purposes
    User& user = message.user;
    auto roomID = _gameActions.getRoomId(message.user.getAvatarId());
    _miniGameActions.nextRound(roomID);

    std::vector<Message> response;
    auto minigame = _miniGameActions.getMiniGame(roomID);
    if(minigame.hasMoreRounds()) {
        response.push_back(Message{message.user, minigame.printQuestion()});
    } else {
        response.push_back(Message{message.user, "No More Questions"});
        _miniGameActions.resetMiniGame(roomID);
        user.setCommandType(new GameCommands());
    }

    return response;
}

std::vector<Message> GameController::verifyMinigameAnswer(const Message& message) {
    // TODO: figure out a better way to get the input. EX. maybe they type a number, should throw error or something
    char letter = (message.text).at(0);
    int input = letter - 'a';

    auto roomID = _gameActions.getRoomId(message.user.getAvatarId());
    bool result = _miniGameActions.verifyAnswer(roomID, input);

    Message newMessage = Message(message.user, (result) ? "Correct" : "WRONG");
    return std::vector<Message>{newMessage};
}

std::vector<Message> GameController::outputCurrentLocationInfo(const Message& message) {
    Message responseMessage{message.user};
    const ID& avatarId = message.user.getAccount().avatarId;
    std::optional<std::string> roomName = _gameActions.getAvatarRoomName(avatarId);

    responseMessage.text = roomName.has_value() ? "Currently located in room: " + roomName.value()
                                                : "Error locating avatar";

    return std::vector<Message>{responseMessage};
}

std::vector<Message> GameController::attackNPC(const Message &message) {

    Message combatResponse = Message(message.user);

    ID userAvatar = message.user.getAccount().avatarId;


    return std::vector<Message>();
}

std::vector<Message> GameController::fleeCombat(const Message &message) {
    return std::vector<Message>();
}

std::vector<Message> GameController::say(const Message& message) {

    std::string sayMessage = message.user.getAccount()._username + " says: " + message.text;

    //retrieve the room the sender avatar is in.
    ID roomId = _gameActions.getRoomId(message.user.getAccount().avatarId);

    std::vector<ID> avatarIds = _gameActions.getAllAvatarIds(roomId);

    return constructMessageToAvatars(sayMessage, avatarIds);
}

std::vector<Message> GameController::yell(const Message& message) {

    std::string yellMessage = message.user.getAccount()._username + " yells: " + message.text;

    //retrieve the room the sender avatar is in.
    ID roomId = _gameActions.getRoomId(message.user.getAccount().avatarId);

    std::vector<ID> avatarIds = _gameActions.getAllAvatarIdsInNeighbourAndCurrent(roomId);

    return constructMessageToAvatars(yellMessage, avatarIds);
}

std::vector<Message> GameController::constructMessageToAvatars(std::string message, const std::vector<ID>& avatarIds){

    std::vector<Message> responses;

    for(const ID& id : avatarIds) {
        User* user = findUser(id);
        if(user == nullptr) continue;
        responses.emplace_back(Message{*user, message});
    }

    return responses;
}


std::vector<Message> GameController::displayAvatarInfo(const Message& message) {
    return  _gameActions.displayAvatarinfo(message);
}


/*
 * PRIVATE
 */
User* GameController::findUser(const ID& avatarId){
    if(_avatarIdToUser.count(avatarId) == 0){
        return nullptr;
    }
    //return user associated with ID
    return _avatarIdToUser[avatarId];
}