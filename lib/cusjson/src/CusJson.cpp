#include <string>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>

#include "CusJson.h"

using json = nlohmann::json;

namespace CusJson {
    void to_json(json& j, const JsonDoor& door) {
        //TODO implement
    }

    void from_json(const json& j, JsonDoor& door) {
        door._dir = j.at("dir");
        const json& descJson = j.at("desc");
        door._desc.resize(descJson.size());
        std::copy(descJson.begin(), descJson.end(), door._desc.begin());
        const json& keywordJson = j.at("keywords");
        door._keywords.resize(keywordJson.size());
        std::copy(keywordJson.begin(), keywordJson.end(), door._keywords.begin());
        door._to = j.at("to");
    }

    void to_json(json& j, const ExtDesc& extDesc) {
        //TODO implement
    }

    void from_json(const json& j, ExtDesc& extDesc) {
        const json& keywordJson = j.at("keywords");
        extDesc._keywords.resize(keywordJson.size());
        std::copy(keywordJson.begin(), keywordJson.end(), extDesc._keywords.begin());
        const json& descJson = j.at("desc");
        extDesc._desc.resize(descJson.size());
        std::copy(descJson.begin(), descJson.end(), extDesc._desc.begin());
    }

    void to_json(json& j, const NPC& npc) {
        j = json{{"id",           npc.id},
                 {"keywords",     npc.keywords},
                 {"shortdesc",    npc.shortdesc},
                 {"longdesc",     npc.longdesc},
                 {"descriptions", npc.description}};
    }

    void from_json(const json& j, NPC& npc) {
        j.at("id").get_to(npc.id);

        const json& keywordssj = j.at("keywords");
        npc.keywords.resize(keywordssj.size());
        std::copy(keywordssj.begin(), keywordssj.end(), npc.keywords.begin());

        j.at("shortdesc").get_to(npc.shortdesc);

        const json& longdescsj = j.at("longdesc");
        npc.longdesc.resize(longdescsj.size());
        std::copy(longdescsj.begin(), longdescsj.end(), npc.longdesc.begin());

        const json& descriptionsj = j.at("description");
        npc.description.resize(descriptionsj.size());
        std::copy(descriptionsj.begin(), descriptionsj.end(), npc.description.begin());
    }

    void to_json(json& j, const Object& object) {
        //TODO implement
    }

    void from_json(const json& j, Object& object) {
        j.at("id").get_to(object.id);

        const json& keywordsjson = j.at("keywords");
        object.keywords.resize(keywordsjson.size());
        std::copy(keywordsjson.begin(), keywordsjson.end(), object.keywords.begin());

        j.at("shortdesc").get_to(object.shortdesc);

        const json& longdescjson = j.at("longdesc");
        object.longdesc.resize(longdescjson.size());
        std::copy(longdescjson.begin(), longdescjson.end(), object.longdesc.begin());

        const json& extraJson = j.at("extra");
        object._jsonExtDesc.resize(extraJson.size());
        std::copy(extraJson.begin(), extraJson.end(), object._jsonExtDesc.begin());
    }

    void to_json(json& j, const Room& room) {
        //TODO implement
    }

    void from_json(const json& j, Room& room) {
        // for some reason, it needs the cast
        j.at("id").get_to(room._id);
        j.at("name").get_to(room._name);
        const json& descJson = j.at("desc");
        room._jsonDesc.resize(descJson.size());
        std::copy(descJson.begin(), descJson.end(), room._jsonDesc.begin());
        const json& doorsJson = j.at("doors");
        room._jsonDoors.resize(doorsJson.size());
        std::copy(doorsJson.begin(), doorsJson.end(), room._jsonDoors.begin());
        const json& extDescJson = j.at("extended_descriptions");
        room._jsonExtDesc.resize(extDescJson.size());
        std::copy(extDescJson.begin(), extDescJson.end(), room._jsonExtDesc.begin());
    }

    void to_json(json& j, const Area& area) {
        j = json{{"name", area._name}};
    }

    void parseResetJsonToArea(const json& resetJson, const Area& area);

    void from_json(const json& j, Area& area) {
        const json& areaName = j.at("AREA");
        areaName.at("name").get_to(area._name);

        const json& npcJson = j.at("NPCS");
        area._npcs.resize(npcJson.size());
        std::copy(npcJson.begin(), npcJson.end(), area._npcs.begin());

        const json& objectson = j.at("OBJECTS");
        area._objects.resize(objectson.size());
        std::copy(objectson.begin(), objectson.end(), area._objects.begin());

        const json& roomJson = j.at("ROOMS");
        area._rooms.resize(roomJson.size());
        std::copy(roomJson.begin(), roomJson.end(), area._rooms.begin());

        const json& resetJson = j.at("RESETS");
        parseResetJsonToArea(resetJson, area);
    }

    //Manual checking/parse is required for resets, See doc/JsonStructureDocument for more info
    void parseResetJsonToArea(const json& resetJson, Area& area) {
        for (json resetJsonObject : resetJson) {
            auto actionString = resetJsonObject["action"].get<std::__cxx11::string>();
            if (actionString == "npc") {
                area._npcsWrappers.push_back(NPCJsonWrapper(
                        resetJsonObject["id"].get<int>(),
                        resetJsonObject["limit"].get<int>(),
                        resetJsonObject["room"].get<int>()
                ));
            } else if (actionString == "give") {
                area._npcsWrappers.at(area._npcsWrappers.size() - 1).addObject(resetJsonObject["id"].get<int>());
            } else if (actionString == "equip") {
                area._npcsWrappers.at(area._npcsWrappers.size() - 1).addEquipment({
                    resetJsonObject["slot"].get<int>(),
                    resetJsonObject["id"].get<int>()
                });
            } else if (actionString == "door") {
                area._doorStateWrappers.push_back(DoorStateJsonWrapper(
                        resetJsonObject["id"].get<int>(),
                        resetJsonObject["room"].get<int>(),
                        resetJsonObject["state"].get<std::__cxx11::string>()
                ));
            } else if (actionString == "object") {
                area._containerWrappers.push_back(ContainerJsonWrapper(
                        resetJsonObject["id"].get<int>(),
                        resetJsonObject["room"].get<int>()
                ));
            } else if (actionString == "put") {
                auto object = find_if(area._containerWrappers.begin(), area._containerWrappers.end(),
                                           [resetJsonObject](ContainerJsonWrapper wrapper) {
                                               return wrapper._objectId == resetJsonObject["container"].get<int>();
                                           });
                if (object != area._containerWrappers.end()) {
                    object.base()->addObject(resetJsonObject["id"].get<int>());
                }
            }
        }
    }
}