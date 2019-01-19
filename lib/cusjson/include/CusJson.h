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

    class Area {
    public:
        std::string name;
    };
    class NPC {
    public:
        int id;
        std::vector<std::string> keywords;
        std::string shortdesc;
        std::vector<std::string> longdesc;
        std::vector<std::string> description;
    };
    class World {
    public:
        CusJson::Area area;
        std::vector<NPC> NPCS;
    };

    void to_json(json& j, const Area& p);

    void from_json(const json& j, Area& p);

    void to_json(json& j, const World& p);

    void from_json(const json& j, World& p);

    void to_json(json& j, const NPC& p);

    void from_json(const json& j, NPC& p);
}

#endif //WEBSOCKETNETWORKING_CUSJSON_H
