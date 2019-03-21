//
// Created by vinshit on 26/02/19.
//

#ifndef WEBSOCKETNETWORKING_COMMAND_H
#define WEBSOCKETNETWORKING_COMMAND_H

enum Command {
    LOGIN,
    REGISTER,
    ESCAPE,
    LOGOUT,
    MOVE,
    SAY,
    WHEREAMI,
    HELP,
    MINIGAME,
    MINIGAME_ANSWER,
    DIRECTIONS
};

class CommandType {
public:
    virtual std::unordered_set<Command> getCommands() = 0;
};

class AccountCommands : public CommandType {
public:
    std::unordered_set<Command> getCommands() override {
        return {
            LOGIN,
            REGISTER,
            ESCAPE,
            HELP
        };
    }
};

class GameCommands : public CommandType {
public:
    std::unordered_set<Command> getCommands() override {
        return {
            MOVE,
            WHEREAMI,
            SAY,
            LOGOUT,
            HELP,
            DIRECTIONS
        };
    }
};

class CombatCommands : public CommandType {
public:
    std::unordered_set<Command> getCommands() override {
        return {
            LOGOUT,
            HELP
        };
    }
};

class MinigameCommands : public CommandType {
public:
    std::unordered_set<Command> getCommands() override {
        return {
            LOGOUT,
            HELP
        };
    }
};

#endif //WEBSOCKETNETWORKING_COMMAND_H
