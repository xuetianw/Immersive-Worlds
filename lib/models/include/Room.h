//
// Created by Jacky Lui on 2019-01-18.
//

#ifndef MODELS_ROOM_H
#define MODELS_ROOM_H

#include <utility>
#include <string>
#include <nlohmann/json.hpp>
#include <CusJson.h>
#include <MiniGame.h>

#include <unordered_map>
#include <vector>

#include "Avatar.h"
#include "ID.h"
#include "CusJson.h"
#include "InventoryItem.h"

using json = nlohmann::json;
using string = std::string;


namespace models {
    class Room {
        ID _id;

        string _name;

        std::vector<std::string> _description;

        std::unordered_map<ID, InventoryItem> _objects;

        std::unordered_map<ID, Room&> _doors;

    public:

        Room() : _id(ID()) {}

        Room(const ID& id, string name, std::vector<string> description) :
            _id(id),
            _name(move(name)),
            _description(move(description)) {}

        Room( string name, std::vector<string> description) :
            _name(move(name)),
            _description(move(description)) {}

        explicit Room(const CusJson::Room& jsonForm) :
            _id(ID(jsonForm._id)),
            _name(jsonForm._name),
            _description(jsonForm._jsonDesc) {}

        const ID& getId() const;

        void setName(string name);

        const string& getName() const;

        void set_description(const std::vector<string>& description);

        const std::vector<string>& getDescription() const;

        std::vector<InventoryItem> getAllObjects() const;

        void addObject(ID objectId, const InventoryItem& object);

        std::vector<Room> getAllDoors() const;
    };

    enum Direction {
        NORTH, SOUTH, EAST, WEST, DOWN, UP
    };

    enum DoorState {
        OPEN, CLOSED, LOCKED
    };

    struct NeighbourInfo {
        Direction direction;
        ID destinationRoomId;
        std::vector<string> descriptions;
        DoorState doorState = DoorState::OPEN;
    };

    // The strings are based on the keywords found in the json file
    static const std::unordered_map<std::string, Direction>  DIRECTION_STRING_TO_ENUM_MAP =
            {
                    {"north", Direction::NORTH},
                    {"east", Direction::EAST},
                    {"south", Direction::SOUTH},
                    {"west", Direction::WEST},
                    {"down", Direction::DOWN},
                    {"up", Direction::UP}
            };

    // The strings are based on the keywords found in the json file
    static const std::unordered_map<int, Direction>  DIRECTION_INDEX_TO_ENUM_MAP =
            {
                    {0, Direction::NORTH},
                    {1, Direction::EAST},
                    {2, Direction::SOUTH},
                    {3, Direction::WEST},
                    {4, Direction::UP},
                    {5, Direction::DOWN}
            };

    static const std::unordered_map<int, int> DIRECTION_INDEX_TO_INVERSE_MAP =
            {
                    {0,2},
                    {1,3},
                    {2,0},
                    {3,1}
            };
    static const std::unordered_map<std::string, DoorState> DOOR_STATE_STRING_ENUM_MAP =
            {
                    {"open", DoorState::OPEN},
                    {"closed", DoorState::CLOSED},
                    {"locked", DoorState::LOCKED}
            };
}

#endif //MODELS_ROOM_H