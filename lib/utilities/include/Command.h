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
    LOOK,
    HELP,
    MINIGAME,
    MINIGAME_ANSWER,
    MINIGAME_NEXTROUND,
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
            LOOK,
            SAY,
            LOGOUT,
            HELP,
            DIRECTIONS,
            MINIGAME
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
            HELP,
            MINIGAME_ANSWER,
            MINIGAME_NEXTROUND
        };
    }
};

#endif //WEBSOCKETNETWORKING_COMMAND_H
