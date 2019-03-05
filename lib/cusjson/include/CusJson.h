//
// Created by user on 1/18/19.
//

#ifndef WEBSOCKETNETWORKING_CUSJSON_H
#define WEBSOCKETNETWORKING_CUSJSON_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

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

    class Room {
    public:
        int _id = 0;
        std::string _name;
        std::vector<std::string>_jsonDesc;
        std::vector<JsonDoor> _jsonDoors;
        std::vector<ExtDesc> _jsonExtDesc;
    };

    class Area {
    public:
        std::string _name;
        std::vector<NPC> _npcs;
        std::vector<Room> _rooms;
    };

    void to_json(json& j, const JsonDoor& door);

    void from_json(const json& j, JsonDoor& door);

    void to_json(json& j, const ExtDesc& extDesc);

    void from_json(const json& j, ExtDesc& extDesc);

    void to_json(json& j, const NPC& p);

    void from_json(const json& j, NPC& p);

    void to_json(json& j, const Room& room);

    void from_json(const json& j, Room& room);

    void to_json(json& j, const Area& p);

    void from_json(const json& j, Area& p);
}

#endif //WEBSOCKETNETWORKING_CUSJSON_H
