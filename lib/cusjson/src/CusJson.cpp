#include "string"
#include "vector"
#include <fstream>
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
        const json& sj = j.at("NPCS");
        p.NPCS.resize(sj.size());
        std::copy(sj.begin(), sj.end(), p.NPCS.begin());
    }

    void to_json(json& j, const NPC& p) {
        j = json{{"id", p.id}, {"keywords", p.keywords}, {"shortdesc", p.shortdesc}, {"longdesc", p.longdesc}, {"descriptions", p.description}};
    }

    void from_json(const json& j, NPC& p) {
        j.at("id").get_to(p.id);
        const json& keywordssj = j.at("keywords");
        p.keywords.resize(keywordssj.size());
        std::copy(keywordssj.begin(), keywordssj.end(), p.keywords.begin());
        j.at("shortdesc").get_to(p.shortdesc);
        const json& longdescsj = j.at("longdesc");
        p.longdesc.resize(longdescsj.size());
        std::copy(longdescsj.begin(), longdescsj.end(), p.longdesc.begin());
        const json& descriptionsj = j.at("description");
        p.description.resize(descriptionsj.size());
        std::copy(descriptionsj.begin(), descriptionsj.end(), p.description.begin());
    }
}