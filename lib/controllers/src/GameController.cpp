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
    return std::vector<Message>{message};
}

std::vector<Message> GameController::respondToMessage(const Message& message) {
    return std::vector<Message>{Message{message.user, INVALID_GAME_COMMAND}};
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
    if (hasMiniGame) {
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
    if (minigame.hasMoreRounds()) {
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
    const ID& roomId = _gameActions.getRoomId(avatarId);
    std::optional<std::string> roomName = _gameActions.getAvatarRoomName(avatarId);

    responseMessage.text = roomName.has_value() ? "Currently located in room: " + roomName.value()
                                                : "Error locating room";

    std::vector<std::string> avatarNames = _gameActions.getAllAvatarsNamesForRoomId(roomId);

    responseMessage.text += "\n" + helper::convertListToString(avatarNames);

    return std::vector<Message>{responseMessage};
}

std::vector<Message> GameController::outputAvatarsInCurrentRoom(const Message& message) {
    auto avatarInfo = _gameActions.getAllAvatarInfoInCurrentRoom(message.user.getAvatarId());
    return std::vector<Message> { Message{message.user, avatarInfo}};
}

std::vector<Message> GameController::attackNPC(const Message& message) {
    User& user = message.user;
    Message combatResponse = Message(user);
    ID playerID = message.user.getAccount().avatarId;

    ID NPCID = _combatActions.getNPCID();

    if (_combatActions.checkAndCreateCombat(playerID, NPCID)) {
        //state transition from game commands to combat commands
        user.setCommandType(new CombatCommands());
    } else {
        combatResponse.text = "The NPC you want to fight does not exist";
        return std::vector<Message>{combatResponse};
    }

    if (_combatActions.performCombatRound(playerID)) {
        //display combat round message
        combatResponse.text = _combatActions.displayCombatDetails(playerID);
    } else {
        combatResponse.text += "The NPC you want to fight is not located in the same room as you";
        return std::vector<Message>{combatResponse};
    }

    if (!_combatActions.isCombatActive(playerID)) {
        combatResponse.text += "You have finished the combat phase";
        user.setCommandType(new GameCommands());
    }

    return std::vector<Message>{combatResponse};
}

std::vector<Message> GameController::fleeCombat(const Message& message) {

    User& user = message.user;
    Message fleeResponse = Message(user);
    ID playerID = message.user.getAccount().avatarId;
    if (_combatActions.destroyCombat(playerID)) {
        fleeResponse.text = "You have successfully fled combat";
        user.setCommandType(new GameCommands());
    } else {
        fleeResponse.text = "You have failed to flee combat";
    }

    return std::vector<Message>{fleeResponse};
}

std::vector<Message> GameController::say(const Message& message) {

    std::string sayHeader = message.user.getAccount()._username + " says: ";
    std::string sayBody = message.text;

    const ID& senderAvatarId = message.user.getAccount().avatarId;

    //retrieve the room the sender avatar is in.
    ID roomId = _gameActions.getRoomId(senderAvatarId);

    std::vector<ID> avatarIds = _gameActions.getAllAvatarIds(roomId);

    return constructMessageToAvatars(sayHeader, sayBody, senderAvatarId, avatarIds);
}

std::vector<Message> GameController::yell(const Message& message) {

    std::string yellHeader = message.user.getAccount()._username + " yells: ";
    std::string yellBody = message.text;

    const ID& senderAvatarId = message.user.getAccount().avatarId;

    //retrieve the room the sender avatar is in.
    ID roomId = _gameActions.getRoomId(senderAvatarId);

    std::vector<ID> avatarIds = _gameActions.getAllAvatarIdsInNeighbourAndCurrent(roomId);

    return constructMessageToAvatars(yellHeader, yellBody, senderAvatarId, avatarIds);
}

std::vector<Message> GameController::tell(const Message& message) {

    std::vector<Message> response{};

    std::string userInput = message.text;

    //split user input after command name by space
    std::string receiver = userInput.substr(0, userInput.find(' '));
    std::string sender = message.user.getAccount()._username;
    const ID& senderAvatarId = message.user.getAccount().avatarId;

    if (receiver == sender) {
        response.emplace_back(message.user, "You cannot send private message to yourself!");
        return response;
    }

    std::string userMessage = userInput.substr(userInput.find(' ') + 1);

    if (userInput.find(' ') == std::string::npos || userMessage == "") {
        response.emplace_back(message.user, "Please enter a message to send");
        return response;
    }

    User* user = findUser(receiver);

    if (user != nullptr) {
        //if user is online
        response.emplace_back(*user, constructMessageStringToAvatar(sender + " whispers: ", userMessage, senderAvatarId));
        response.emplace_back(message.user, constructMessageStringToAvatar("You whispered to " + receiver + ": ", userMessage, senderAvatarId));
    } else {
        response.emplace_back(message.user, constructMessageStringToAvatar("User is not online or does not exist", "", senderAvatarId));
    }

    return response;

}



std::vector<Message> GameController::displayAvatarInfo(const Message& message) {
    auto response = _gameActions.displayAvatarinfoFromID(message.user.getAvatarId());
    return std::vector<Message>{Message(message.user, response)};
}



std::vector<Message> GameController::swapAvatar(const Message& message) {
    return  _gameActions.swapAvatar(message);
}


std::vector<Message> GameController::confuseAvatar(const Message& message){

    std::vector<Message> response{};

    std::string recipient = message.text;

    User* user = findUser(recipient);

    if (user != nullptr) {
        //if user is online
        if(setAvatarConfuseState(user->getAccount().avatarId, true)){
            response.emplace_back(*user, USER_CONFUSED_MESSAGE);
            response.emplace_back(message.user, recipient + " has been confused!");
        } else {
            response.emplace_back(*user, "User is not online");
        }

    } else {
        response.emplace_back(message.user, "User does not exist");
    }

    return response;
}

std::vector<Message> GameController::unconfuseAvatar(const Message& message) {

    const ID& avatarId = message.user.getAccount().avatarId;

    if (getAvatarConfuseState(avatarId)) {
        setAvatarConfuseState(avatarId, false);
        return std::vector<Message>{Message{message.user, "You have been released from the confuse state"}};
    } else {
        return std::vector<Message>{Message{message.user, "You are not confused"}};
    }
}

bool GameController::getAvatarConfuseState(const ID &avatarId) {
    return _avatarService.getAvatarConfuseState(avatarId);
}

void GameController::scrambleMessages(std::vector<Message>& messages) {
    for (Message& msg: messages) {
        scrambleMessage(msg);
    }
}

void GameController::scrambleMessage(Message& message) {
    message.text = scrambleMessage(message.text);
}



/*
 * PRIVATE
 */

std::string GameController::constructMessageStringToAvatar(std::string messageHeader, std::string messageBody,
                                                           const ID& senderAvatarId) {
    bool senderIsConfused = getAvatarConfuseState(senderAvatarId);
    if (senderIsConfused){
        messageBody = scrambleMessage(messageBody);
    }
    return messageHeader+messageBody;
}

std::vector<Message> GameController::constructMessageToAvatars(std::string messageHeader, std::string messageBody,
                                                               const ID& senderAvatarId, const std::vector<ID>& avatarIds) {

    bool senderIsConfused = getAvatarConfuseState(senderAvatarId);

    std::vector<Message> responses;

    if (senderIsConfused){
        messageBody = scrambleMessage(messageBody);
    }

    for (const ID& avatarId : avatarIds) {
        User* user = findUser(avatarId);
        if (user == nullptr) continue;
        responses.emplace_back( Message {*user, messageHeader+messageBody});

    }

    return responses;
}

std::string GameController::scrambleMessage(std::string message) {
    for(char& c: message){
        c++;
    }
    return message;
}

bool GameController::setAvatarConfuseState(const ID& avatarId, bool isConfused) {
    return _avatarService.setAvatarConfuseState(avatarId, isConfused);
}

User* GameController::findUser(const ID& avatarId) {
    if (_avatarIdToUser.count(avatarId) == 0) {
        return nullptr;
    }
    //return user associated with ID
    return _avatarIdToUser[avatarId];
}


User* GameController::findUser(std::string username) {

    //find user with matching username
    auto it = std::find_if(
            _avatarIdToUser.begin(),
            _avatarIdToUser.end(),
            [&username](const auto& it) {
                return it.second->getAccount()._username == username;
            }
    );

    if (_avatarIdToUser.end() != it) {
        return it->second;
    } else {
        return nullptr;
    }
}