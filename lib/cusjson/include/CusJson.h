//
// Created by user on 1/18/19.
//

#ifndef WEBSOCKETNETWORKING_CUSJSON_H
#define WEBSOCKETNETWORKING_CUSJSON_H

#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace CusJson {


    class Area {
    public:
        std::string name;
    };
    class World {
    public:
        CusJson::Area area;
    };

    void to_json(json& j, const Area& p);

    void from_json(const json& j, Area& p);

    void to_json(json& j, const World& p);

    void from_json(const json& j, World& p);
}

#endif //WEBSOCKETNETWORKING_CUSJSON_H
