//
// Created by user on 1/18/19.
//

#ifndef WEBSOCKETNETWORKING_CUSJSON_H
#define WEBSOCKETNETWORKING_CUSJSON_H

#include <string>
#include <vector>
#include <NPCJsonWrapper.h>
#include <DoorStateJsonWrapper.h>
#include <ContainerJsonWrapper.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace CusJson {

    class JsonDoor {
    public:
        JsonDoor();

        std::string _dir;
        std::vector<std::string> _desc;
        std::vector<std::string> _keywords;
        int _to;
    };

    class ExtDesc {
    public:
        ExtDesc();

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

    void to_json(json &j, const JsonDoor &door);

    void from_json(const json &j, JsonDoor &door);

    void to_json(json &j, const ExtDesc &extDesc);

    void from_json(const json &j, ExtDesc &extDesc);

    void to_json(json &j, const NPC &npc);

    void from_json(const json &j, NPC &npc);

    void to_json(json &j, const Object &object);

    void from_json(const json &j, Object &object);

    void to_json(json &j, const Room &room);

    void from_json(const json &j, Room &room);

    void to_json(json &j, const Area &area);

    void from_json(const json &j, Area &area);
}

#endif //WEBSOCKETNETWORKING_CUSJSON_H
