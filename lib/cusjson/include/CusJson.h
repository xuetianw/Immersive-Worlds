//
// Created by user on 1/18/19.
//

#ifndef WEBSOCKETNETWORKING_CUSJSON_H
#define WEBSOCKETNETWORKING_CUSJSON_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "NPCJsonWrapper.h"
#include "DoorStateJsonWrapper.h"
#include "ContainerJsonWrapper.h"

using json = nlohmann::json;

namespace CusJson {

    class JsonDoor {
    public:
        std::string _dir;
        std::vector<std::string> _desc;
        std::vector<std::string> _keywords;
        int _to;
    };

    class ExtDesc {
    public:
        std::vector<std::string> _keywords;
        std::vector<std::string> _desc;
    };

    class NPC {
    public:
        int id;
        std::vector<std::string> keywords;
        std::string shortdesc;
        std::vector<std::string> longdesc;
        std::vector<std::string> description;
    };

    class Object {
    public:
        int id;
        std::vector<std::string> keywords;
        std::string shortdesc;
        std::vector<std::string> longdesc;
        std::vector<ExtDesc> _jsonExtDesc;
    };

    class Room {
    public:
        int _id = 0;
        std::string _name;
        std::vector<std::string> _jsonDesc;
        std::vector<JsonDoor> _jsonDoors;
        std::vector<ExtDesc> _jsonExtDesc;
    };

    class Area {
    public:
        std::string _name;
        std::vector<NPC> _npcs;
        std::vector<Object> _objects;
        std::vector<Room> _rooms;
        std::vector<NPCJsonWrapper> _npcsWrappers;
        std::vector<DoorStateJsonWrapper> _doorStateWrappers;
        std::vector<ContainerJsonWrapper> _containerWrappers;
    };

    class MiniGame {
    public:
        int _id;
        int _roomId;
        std::string _roomName;
        std::string _type;
        std::vector<std::string> _questions;
        std::vector<std::vector<std::string>> _possibleAnswers;
        std::vector<int> _correctAnswers;
    };

    class MiniGameList {
    public:
        std::vector<MiniGame> _minigames;
    };

    void to_json(json& j, const JsonDoor& door);

    void from_json(const json& j, JsonDoor& door);

    void to_json(json& j, const ExtDesc& extDesc);

    void from_json(const json& j, ExtDesc& extDesc);

    void to_json(json& j, const NPC& npc);

    void from_json(const json& j, NPC& npc);

    void to_json(json& j, const Object& object);

    void from_json(const json& j, Object& object);

    void to_json(json& j, const Room& room);

    void from_json(const json& j, Room& room);

    void to_json(json& j, const Area& p);

    void from_json(const json& j, Area& p);

    void parseResetJsonToArea(const json& resetJson, Area& area);

    void to_json(json& j, const MiniGame& p);

    void from_json(const json& j, MiniGame& p);

    void to_json(json& j, const MiniGameList& p);

    void from_json(const json& j, MiniGameList& p);
}

#endif //WEBSOCKETNETWORKING_CUSJSON_H
