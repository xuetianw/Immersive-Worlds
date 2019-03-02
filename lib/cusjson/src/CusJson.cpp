#include "string"
#include "vector"
#include <fstream>
#include <nlohmann/json.hpp>
#include <CusJson.h>

using json = nlohmann::json;

namespace CusJson {

    JsonDoor::JsonDoor() {}

    ExtDesc::ExtDesc() {}

    void to_json(json &j, const JsonDoor &door) {
        //TODO implement
    }

    void from_json(const json &j, JsonDoor &door) {
        door._dir = j.at("dir");
        const json &descJson = j.at("desc");
        door._desc.resize(descJson.size());
        std::copy(descJson.begin(), descJson.end(), door._desc.begin());
        const json &keywordJson = j.at("keywords");
        door._keywords.resize(keywordJson.size());
        std::copy(keywordJson.begin(), keywordJson.end(), door._keywords.begin());
        door._to = j.at("to");
    }

    void to_json(json &j, const ExtDesc &extDesc) {
        //TODO implement
    }

    void from_json(const json &j, ExtDesc &extDesc) {
        const json &keywordJson = j.at("keywords");
        extDesc._keywords.resize(keywordJson.size());
        std::copy(keywordJson.begin(), keywordJson.end(), extDesc._keywords.begin());
        const json &descJson = j.at("desc");
        extDesc._desc.resize(descJson.size());
        std::copy(descJson.begin(), descJson.end(), extDesc._desc.begin());
    }

    void to_json(json &j, const NPC &p) {
        j = json{{"id",           p.id},
                 {"keywords",     p.keywords},
                 {"shortdesc",    p.shortdesc},
                 {"longdesc",     p.longdesc},
                 {"descriptions", p.description}};
    }

    void from_json(const json &j, NPC &p) {
        j.at("id").get_to(p.id);

        const json &keywordssj = j.at("keywords");
        p.keywords.resize(keywordssj.size());
        std::copy(keywordssj.begin(), keywordssj.end(), p.keywords.begin());

        j.at("shortdesc").get_to(p.shortdesc);

        const json &longdescsj = j.at("longdesc");
        p.longdesc.resize(longdescsj.size());
        std::copy(longdescsj.begin(), longdescsj.end(), p.longdesc.begin());

        const json &descriptionsj = j.at("description");
        p.description.resize(descriptionsj.size());
        std::copy(descriptionsj.begin(), descriptionsj.end(), p.description.begin());
    }

    void to_json(json &j, const Object &object) {
        //TODO implement
    }

    void from_json(const json &j, Object &object) {
        j.at("id").get_to(object.id);

        const json &keywordsjson = j.at("keywords");
        object.keywords.resize(keywordsjson.size());
        std::copy(keywordsjson.begin(), keywordsjson.end(), object.keywords.begin());

        j.at("shortdesc").get_to(object.shortdesc);

        const json &longdescjson = j.at("longdesc");
        object.longdesc.resize(longdescjson.size());
        std::copy(longdescjson.begin(), longdescjson.end(), object.longdesc.begin());

        const json &extraJson = j.at("extra");
        object._jsonExtDesc.resize(extraJson.size());
        std::copy(extraJson.begin(), extraJson.end(), object._jsonExtDesc.begin());
    }

    void to_json(json &j, const Room &room) {
        //TODO implement
    }

    void from_json(const json &j, Room &room) {
        // for some reason, it needs the cast
        j.at("id").get_to(room._id);
        j.at("name").get_to(room._name);
        const json &descJson = j.at("desc");
        room._jsonDesc.resize(descJson.size());
        std::copy(descJson.begin(), descJson.end(), room._jsonDesc.begin());
        const json &doorsJson = j.at("doors");
        room._jsonDoors.resize(doorsJson.size());
        std::copy(doorsJson.begin(), doorsJson.end(), room._jsonDoors.begin());
        const json &extDescJson = j.at("extended_descriptions");
        room._jsonExtDesc.resize(extDescJson.size());
        std::copy(extDescJson.begin(), extDescJson.end(), room._jsonExtDesc.begin());
    }

    void to_json(json &j, const Area &p) {
        j = json{{"name", p._name}};
    }

    void from_json(const json &j, Area &p) {
        const json &areaName = j.at("AREA");
        areaName.at("name").get_to(p._name);

        const json &npcJson = j.at("NPCS");
        p._npcs.resize(npcJson.size());
        std::copy(npcJson.begin(), npcJson.end(), p._npcs.begin());

        const json &objectson = j.at("OBJECTS");
        p._objects.resize(objectson.size());
        std::copy(objectson.begin(), objectson.end(), p._objects.begin());

        const json &roomJson = j.at("ROOMS");
        p._rooms.resize(roomJson.size());
        std::copy(roomJson.begin(), roomJson.end(), p._rooms.begin());

        const json &resetJson = j.at("RESETS");
    }
}