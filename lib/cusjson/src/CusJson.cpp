#include "string"
#include <fstream>
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

    void to_json(json& j, const Area& p) {
        j = json{{"name", p.name}};
    }

    void from_json(const json& j, Area& p) {
        j.at("name").get_to(p.name);
    }

    void to_json(json& j, const World& p) {
        j = json{{"AREA", p.area}};
    }

    void from_json(const json& j, World& p) {
        j.at("AREA").get_to(p.area);
    }
}