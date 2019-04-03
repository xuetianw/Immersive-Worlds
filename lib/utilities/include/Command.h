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
    YELL,
    TELL,
    LOOK,
    HELP,
    MINIGAME,
    MINIGAME_ANSWER,
    MINIGAME_NEXTROUND,
    DIRECTIONS,
    AVATAR_INFO,
    SWAP_AVATAR,
    AVATARS_IN_ROOM,
    ATTACK,
    FLEE
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
            YELL,
            TELL,
            LOGOUT,
            HELP,
            DIRECTIONS,
            MINIGAME,
            AVATAR_INFO,
            SWAP_AVATAR,
            AVATARS_IN_ROOM
            ATTACK
        };
    }
};

class CombatCommands : public CommandType {
public:
    std::unordered_set<Command> getCommands() override {
        return {
            ATTACK,
            FLEE,
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
