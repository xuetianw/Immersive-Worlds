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
        NORTH, SOUTH, EAST, WEST
    };

    struct NeighbourInfo {
        Direction direction;
        ID destinationRoomId;
        std::vector<string> descriptions;
    };

    // The strings are based on the keywords found in the json file
    static const std::unordered_map<std::string, Direction>  DIRECTION_STRING_TO_ENUM_MAP =
            {
                    {"north", Direction::NORTH},
                    {"east", Direction::EAST},
                    {"south", Direction::SOUTH},
                    {"west", Direction::WEST}
            };

    static const std::unordered_map<int, Direction>  DIRECTION_INDEX_TO_ENUM_MAP =
            {
                    {0, Direction::NORTH},
                    {1, Direction::EAST},
                    {2, Direction::SOUTH},
                    {3, Direction::WEST}
            };
}

#endif //MODELS_ROOM_H