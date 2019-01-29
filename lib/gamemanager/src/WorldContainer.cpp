//
// Created by Michael on 1/23/19.
//
#include <iostream>
#include <string>
#include "../include/WorldContainer.h"
//mock implementation of login system. Will change with requirements

#include <CusJson.h>

#include <fstream>
#include <nlohmann/json.hpp>
#include <WorldContainer.h>

#include "string"

using json = nlohmann::json;
using namespace std;

void WorldContainer::loadFromStorage() {
    json solaceJson = debugArea();
    auto solaceArea = solaceJson.get<channel::Area>();
    area = solaceArea;
    printOutArea(area);
}

void WorldContainer::resetWorld() {
    loadFromStorage();
}

void WorldContainer::printOutArea(const channel::Area &area) {

}

WorldContainer::WorldContainer() {
  area = channel::Area();
}

json WorldContainer::debugArea() {
    json j = R"({"ROOMS": [
    {
      "id": 1100,
      "name": "A dimly lit path",
      "desc": [
        "You tread through the deep, dark forest on a dimly lit path.  Up ahead you",
        "can hear the faint sounds of a village."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "The dimly lit path leads south through the light forest."
          ],
          "keywords": [],
          "to": 6000
        },
        {
          "dir": "north",
          "desc": [
            "The dimly lit path leads north through the dense forest."
          ],
          "keywords": [],
          "to": 1101
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1101,
      "name": "A dimly lit path",
      "desc": [
        "You tread through the deep, dark forest on a dimly lit path.  Up ahead you",
        "can hear the faint sounds of a village."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "The dimly lit path leads north through the dense forest."
          ],
          "keywords": [],
          "to": 1102
        },
        {
          "dir": "south",
          "desc": [
            "The dimly lit path leads south through the dense forest."
          ],
          "keywords": [],
          "to": 1100
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1102,
      "name": "A dimly lit path",
      "desc": [
        "You tread through the deep, dark forest on a dimly lit path.  The forest",
        "here seems less dense than to the south.  Northward you see the faint outline",
        "of a village."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "The dimly lit path leads south through the dense forest."
          ],
          "keywords": [],
          "to": 1101
        },
        {
          "dir": "north",
          "desc": [
            "The dimly lit path leads to a village."
          ],
          "keywords": [],
          "to": 1103
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1103,
      "name": "Entrance to the Shire",
      "desc": [
        "You stand at the entrance to the Shire.  You see halflings, no more than",
        "wee tall, every which way you look. Bywater Road leads east and west."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "To the south you see a dimly lit path which leads to a dense forest."
          ],
          "keywords": [],
          "to": 1102
        },
        {
          "dir": "east",
          "desc": [
            "To the east runs Bywater Road."
          ],
          "keywords": [],
          "to": 1104
        },
        {
          "dir": "west",
          "desc": [
            "To the west runs Bywater Road."
          ],
          "keywords": [],
          "to": 1118
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1104,
      "name": "Bywater Road",
      "desc": [
        "You stand on Bywater Road, the busiest street in all of Shiredom.  The road",
        "continues to the east and west while to the north lies the general store."
      ],
      "doors": [
        {
          "dir": "west",
          "desc": [
            "To the west you see the entrance to the Shire."
          ],
          "keywords": [],
          "to": 1103
        },
        {
          "dir": "north",
          "desc": [
            "The general store lies to the north."
          ],
          "keywords": [],
          "to": 1105
        },
        {
          "dir": "east",
          "desc": [
            "To the east runs Bywater Road."
          ],
          "keywords": [],
          "to": 1106
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1105,
      "name": "The General Store",
      "desc": [
        "You are inside the general store.  All sorts of goodies are stacked on the",
        "many shelves.  Your local friendly shopkeeper is smiling patiently, waiting to",
        "serve you to the best of his abilities.  The only exit is to the south."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "The only exit lies to the south."
          ],
          "keywords": [],
          "to": 1104
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1106,
      "name": "Bywater Road",
      "desc": [
        "You stand on Bywater Road, the busiest street in all of Shiredom.  The road",
        "continues to the east and west.  To the north, steps lead to a friendly looking",
        "weaponry/armory while a nursery lies to the south."
      ],
      "doors": [
        {
          "dir": "west",
          "desc": [
            "To the west runs Bywater Road."
          ],
          "keywords": [],
          "to": 1104
        },
        {
          "dir": "east",
          "desc": [
            "To the east runs Bywater Road."
          ],
          "keywords": [],
          "to": 1109
        },
        {
          "dir": "north",
          "desc": [
            "Steps lead to a friendly looking weaponry and armory."
          ],
          "keywords": [],
          "to": 1107
        },
        {
          "dir": "south",
          "desc": [
            "To the south lies Kid'n Keep, the local nursery."
          ],
          "keywords": [],
          "to": 1108
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1107,
      "name": "The House of Arms",
      "desc": [
        "You are inside the finest weapons and armour shop in all of Shiredom.  The",
        "shopkeeper proudly displays his fine wares and humbly offers the best daggers",
        "that you have ever laid eyes on."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "The only exit lies to the south."
          ],
          "keywords": [],
          "to": 1106
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1108,
      "name": "Kid'n Keep",
      "desc": [
        "You are inside Kid'n Keep, the convenient one-stop nursery that maintains",
        "the youth of the Shire.  Toddlers run every which way while their nursemaids",
        "sigh in exasperation.  The only exit lies to the north."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "The only exit lies to the north."
          ],
          "keywords": [],
          "to": 1106
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1109,
      "name": "A bend in the road",
      "desc": [
        "Bywater Road continues west and south.  A large, imposing building lies",
        "to the east.  Farther to the south, you can see an Inn of some sort."
      ],
      "doors": [
        {
          "dir": "west",
          "desc": [
            "To the west runs Bywater Road."
          ],
          "keywords": [],
          "to": 1106
        },
        {
          "dir": "south",
          "desc": [
            "To the south runs Bywater Road."
          ],
          "keywords": [],
          "to": 1112
        },
        {
          "dir": "east",
          "desc": [
            "A large, imposing building lies to the east.  A sign reads 'Shiriff Post'."
          ],
          "keywords": [],
          "to": 1110
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1110,
      "name": "Shiriff Post of the Eastern Shire",
      "desc": [
        "You are in the Shiriff Post which acts as the nucleus for the three shiriffs",
        "of the Eastern Shire.  As you examine the shiriffs on duty, you come to realize",
        "that the halflings of the Shire are not to be reckoned with.  You cower with",
        "awe.  A door offers passage to the east."
      ],
      "doors": [
        {
          "dir": "west",
          "desc": [
            "To the west you can see Bywater Road."
          ],
          "keywords": [],
          "to": 1109
        },
        {
          "dir": "east",
          "desc": [
            "A door offers passage to the office of the Thain."
          ],
          "keywords": [
            "door"
          ],
          "to": 1111
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1111,
      "name": "Thain's Office",
      "desc": [
        "You stand inside the office of the Thain, the police protectorate of the",
        "great Shire.  The Thain has sworn to protect the Shire from all thieves and",
        "murderers with his life, and so eyes you suspiciously.  A door to the west",
        "leads to the Shiriff Post."
      ],
      "doors": [
        {
          "dir": "west",
          "desc": [
            "A door offers passage to the Shiriff Post."
          ],
          "keywords": [
            "door"
          ],
          "to": 1110
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1112,
      "name": "Bywater Road",
      "desc": [
        "You stand on Bywater Road, the busiest street in all of Shiredom.  The road",
        "continues to the north and south.  To the east you spy the training grounds for",
        "shiriffs in training."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "To the north runs Bywater Road."
          ],
          "keywords": [],
          "to": 1109
        },
        {
          "dir": "south",
          "desc": [
            "To the south runs Bywater Road."
          ],
          "keywords": [],
          "to": 1113
        },
        {
          "dir": "east",
          "desc": [
            "The Shiriff Training Grounds lies to the east."
          ],
          "keywords": [],
          "to": 1117
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1113,
      "name": "Bywater Road",
      "desc": [
        "You stand on Bywater Road, the busiest street in all of Shiredom.  The road",
        "continues to the north.  The private residences of Shire inhabitants are to",
        "the east and west while to the south lies the Ivy Bush, second only to the",
        "Green Dragon for its hospitality and service."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "To the north runs Bywater Road."
          ],
          "keywords": [],
          "to": 1112
        },
        {
          "dir": "east",
          "desc": [
            "You spy the private dwelling of a Shire folk to the east."
          ],
          "keywords": [],
          "to": 1115
        },
        {
          "dir": "south",
          "desc": [
            "To the south you see the Ivy Bush, a favorite haunt of Shire urbanites and",
            "seasoned travelers."
          ],
          "keywords": [],
          "to": 1116
        },
        {
          "dir": "west",
          "desc": [
            "You spy the private dwelling of a Shire folk to the west."
          ],
          "keywords": [],
          "to": 1114
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1114,
      "name": "A smial",
      "desc": [
        "You are inside a smial, a hole in the ground which serves as the proper",
        "dwelling place for halflings.  As you look around this private abode, you feel",
        "as if you were intruding and so quickly cover your eyes.  The only exit lies",
        "to the east."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "The only exit lies to the east."
          ],
          "keywords": [],
          "to": 1113
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1115,
      "name": "A smial",
      "desc": [
        "You are inside a smial, a hole in the ground which serves as the proper",
        "dwelling place for halflings.  As you look around this private abode, you feel",
        "as if you were intruding and so quickly cover your eyes.  The only exit lies",
        "to the west."
      ],
      "doors": [
        {
          "dir": "west",
          "desc": [
            "The only exit lies to the west."
          ],
          "keywords": [],
          "to": 1113
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1116,
      "name": "The Ivy Bush",
      "desc": [
        "You are in the Ivy Bush, one of the most famous inns in all of Shiredom.",
        "Chique Shire urbanites and seasoned travelers fill the confines of the room",
        "with gay and lively talk.  A jovial innkeeper stops all that he is doing to",
        "await your command.  The only exit lies to the north."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "The only exit lies to the north."
          ],
          "keywords": [],
          "to": 1113
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1117,
      "name": "Shiriff Training Grounds",
      "desc": [
        "The sounds of mock battle and feigned death cries fill your ears.  Every",
        "which way you turn you see halfling trainees at the prime of their youth.  A",
        "wizened old battle instructor meets your gaze and asks if he may be of",
        "service.  The only exit lies to the west."
      ],
      "doors": [
        {
          "dir": "west",
          "desc": [
            "The only exit lies to the west."
          ],
          "keywords": [],
          "to": 1112
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1118,
      "name": "Bywater Road",
      "desc": [
        "You stand on Bywater Road, the busiest street in all of Shiredom.  The road",
        "continues to the east and west.  A large, imposing building lies to the south.",
        "You catch a glimpse of the Brandywine River to the north."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "To the east you see the entrance to the Shire."
          ],
          "keywords": [],
          "to": 1103
        },
        {
          "dir": "south",
          "desc": [
            "A large, imposing building lies to the south.  A sign reads 'Shiriff Post'."
          ],
          "keywords": [],
          "to": 1119
        },
        {
          "dir": "west",
          "desc": [
            "To the west runs Bywater Road."
          ],
          "keywords": [],
          "to": 1120
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1119,
      "name": "Shiriff Post of the Bridge",
      "desc": [
        "You are in the Shiriff Post which acts as the nucleus for the three shiriffs",
        "of the Bridge.  As you examine the shiriffs on duty, you come to realize that",
        "the halflings of the Shire are not to be reckoned with.  You cower with awe.",
        "The only exit is to the north."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "The only exit is to the north."
          ],
          "keywords": [],
          "to": 1118
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1120,
      "name": "Bywater Road",
      "desc": [
        "You stand on Bywater Road, the busiest street in all of Shiredom.  The road",
        "continues to the east and west.  To the south you spy the Grocer's Delight,",
        "the premium grocer's shop in all the realm while to the north lies Brandywine",
        "Bridge."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "Brandywine Bridge offers safe passage across the tumultuous river."
          ],
          "keywords": [],
          "to": 1131
        },
        {
          "dir": "east",
          "desc": [
            "To the east runs Bywater Road."
          ],
          "keywords": [],
          "to": 1118
        },
        {
          "dir": "south",
          "desc": [
            "You see the Grocer's Delight to the south."
          ],
          "keywords": [],
          "to": 1121
        },
        {
          "dir": "west",
          "desc": [
            "To the west runs Bywater Road."
          ],
          "keywords": [],
          "to": 1122
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1121,
      "name": "The Grocer's Delight",
      "desc": [
        "You tremble with ecstasy as the tempting odors of freshly made pipeweed",
        "bread fill your lungs.  Rumor has it that the pipeweed bread sold here can",
        "restore vitality.  You look around but find no one to take your order.",
        "You then peep over the counter and discover a friendly grocer who is too",
        "short to be seen over the counter.  The only exit is to the north."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "The only exit is to the north."
          ],
          "keywords": [],
          "to": 1120
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1122,
      "name": "Bywater Road",
      "desc": [
        "You stand on Bywater Road, the busiest street in all of Shiredom.  The road",
        "continues to the east.  A small hill lies to the west while you can see a",
        "watermill to the far south.  You catch a glimpse of the Brandywine River to",
        "the north."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "To the east runs Bywater Road."
          ],
          "keywords": [],
          "to": 1120
        },
        {
          "dir": "south",
          "desc": [
            "An entrance to the watermill lies to the south."
          ],
          "keywords": [],
          "to": 1123
        },
        {
          "dir": "west",
          "desc": [
            "A small hill to the west blocks your view."
          ],
          "keywords": [],
          "to": 1126
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1123,
      "name": "Entrance to Watermill",
      "desc": [
        "You stand at the entrance to a watermill.  You hear the bustle of busy",
        "workers and the sound of a creaking mill.  Bywater Road is to the north while",
        "the watermill continues to the south."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see Bywater Road to the north."
          ],
          "keywords": [],
          "to": 1122
        },
        {
          "dir": "south",
          "desc": [
            "A watermill meets your gaze."
          ],
          "keywords": [],
          "to": 1124
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1124,
      "name": "The Watermill",
      "desc": [
        "Halfling workers are scattered everywhere, busy at work.  You see the river",
        "to the west and get a compelling urge to grab the nearest worker and to toss",
        "him into the river.  The entrance stands to the north while a door offers",
        "passage to the south."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see the entrance."
          ],
          "keywords": [],
          "to": 1123
        },
        {
          "dir": "south",
          "desc": [
            "A wooden door leads to the rear of the watermill."
          ],
          "keywords": [
            "door"
          ],
          "to": 1125
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1125,
      "name": "Rear of watermill",
      "desc": [
        "You stand in a damp, dimly lit room.  Mildew clings to the walls and it",
        "appears as if you were the first person to enter the room in ages.  A barely",
        "visible portal in the ground catches your eye."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "A watermill meets your gaze."
          ],
          "keywords": [],
          "to": 1124
        },
        {
          "dir": "down",
          "desc": [
            "A hidden portal reveals a passageway down."
          ],
          "keywords": [],
          "to": 1146
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1126,
      "name": "Took Hill",
      "desc": [
        "You stand on top of Took Hill, named after the legendary Bandobras Took.",
        "You feel honored to be standing on a hill named after your hero.  From this",
        "vantage point you can see all of shiredom.  You get the feeling that with",
        "one stomp you could eliminate their great city.  You can see the outline of",
        "Midgaard to the far east.  Sounds of joyful celebration are heard from the",
        "fields west of here.  The Brandywine flows by lazily nearby."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "To the east runs Bywater Road."
          ],
          "keywords": [],
          "to": 1122
        },
        {
          "dir": "west",
          "desc": [
            "You see a grassy field to the west."
          ],
          "keywords": [],
          "to": 1128
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1127,
      "name": "Northern end of grassy field",
      "desc": [
        "You stand in a grassy field--nothing to get too excited about.  The field",
        "extends toward the south and the west.  To the east you see Took Hill."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "You see a grassy field."
          ],
          "keywords": [],
          "to": 1128
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1128,
      "name": "A grassy field",
      "desc": [
        "You stand in the center of a grassy field.  A great birthday party appears",
        "to be taking place.  Great tables of food are spread out and a young halfling",
        "beauty offers you welcome.  You are enticed by her generosity and suggestive",
        "winks."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a grassy field."
          ],
          "keywords": [],
          "to": 1127
        },
        {
          "dir": "east",
          "desc": [
            "A small hill to the east blocks your view."
          ],
          "keywords": [],
          "to": 1126
        },
        {
          "dir": "south",
          "desc": [
            "You see a grassy field."
          ],
          "keywords": [],
          "to": 1129
        },
        {
          "dir": "west",
          "desc": [
            "You see a grassy field."
          ],
          "keywords": [],
          "to": 1130
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1129,
      "name": "Southern end of grassy field",
      "desc": [
        "You stand in a grassy field--nothing to get too excited about.  The field",
        "extends toward the north and the west.  To the east you see Took Hill."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a grassy field."
          ],
          "keywords": [],
          "to": 1128
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1130,
      "name": "Western end of grassy field",
      "desc": [
        "You stand in a grassy field--nothing to get too excited about.  The field",
        "extends every which way but west."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see a grassy field."
          ],
          "keywords": [],
          "to": 1128
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1131,
      "name": "Brandywine Bridge",
      "desc": [
        "You stand on a solidly built bridge.  As you look down you spy gaily",
        "colored fish swimming with the current of Brandywine River.  The cool water",
        "looks invitingly refreshing and you get a sudden urge to strip and bathe in",
        "the river, but you hear the laughter of women nearby and so resist the urge.",
        "Delving Lane extends to the north while Bywater Road can be seen to the south."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see Delving Lane."
          ],
          "keywords": [],
          "to": 1132
        },
        {
          "dir": "south",
          "desc": [
            "To the south runs Bywater Road."
          ],
          "keywords": [],
          "to": 1120
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1132,
      "name": "Delving Lane",
      "desc": [
        "Delving Lane runs north and south in this small borough of the Shire.  To",
        "the south stands Brandywine Bridge.  The Green Dragon, the undisputed leader",
        "in the art of innkeeping, offers rest and comfort to the east.  You hear the",
        "bray of horses from the west."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see Delving Lane."
          ],
          "keywords": [],
          "to": 1133
        },
        {
          "dir": "south",
          "desc": [
            "Brandywine Bridge offers safe passage across the tumultuous river."
          ],
          "keywords": [],
          "to": 1131
        },
        {
          "dir": "east",
          "desc": [
            "The Green Dragon offers food, drink, and above all hospitality for mere gold."
          ],
          "keywords": [],
          "to": 1144
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1133,
      "name": "Delving Lane",
      "desc": [
        "Delving Lane runs north and south in this small borough of the Shire.  A",
        "large, imposing building lies to the east.  You hear the bray of horses from",
        "the west."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see Delving Lane."
          ],
          "keywords": [],
          "to": 1134
        },
        {
          "dir": "east",
          "desc": [
            "A large, imposing building lies to the east.  A sign reads 'Shiriff Post'."
          ],
          "keywords": [],
          "to": 1145
        },
        {
          "dir": "south",
          "desc": [
            "You see Delving Lane."
          ],
          "keywords": [],
          "to": 1132
        },
        {
          "dir": "west",
          "desc": [
            "You see a grassy field."
          ],
          "keywords": [],
          "to": 1138
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1134,
      "name": "Delving Lane",
      "desc": [
        "Delving Lane runs north and south in this small borough of the Shire. There",
        "is a small house to the west, nothing to the east, and up ahead you see a round",
        "door which leads to a rather impressive abode."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "A large, magnificent house meets your steady gaze.  Above the round door a",
            "sign reads 'Bag End'."
          ],
          "keywords": [],
          "to": 1135
        },
        {
          "dir": "south",
          "desc": [
            "You see Delving Lane."
          ],
          "keywords": [],
          "to": 1133
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1135,
      "name": "Bag End",
      "desc": [
        "You stand in a comfortably well-equipped house, a palace by humble halfling",
        "standards.  On the wall you see a banner which reads \"Home Sweet Home\".",
        "A solid oak door to the east leads to a pantry while you see a cozy bedroom",
        "to the west."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "Through the keyhole you see what looks like a well stocked pantry."
          ],
          "keywords": [
            "door"
          ],
          "to": 1137
        },
        {
          "dir": "south",
          "desc": [
            "You see Delving Lane."
          ],
          "keywords": [],
          "to": 1134
        },
        {
          "dir": "west",
          "desc": [
            "You see a bedroom.  It looks like the beds have recently been slept in."
          ],
          "keywords": [],
          "to": 1136
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1136,
      "name": "Bedroom",
      "desc": [
        "You stand in the private bedroom of Bag End.  There are two beds to the",
        "side, neither of which are made.  Portraits of halflings hang on the wall,",
        "and as you gaze upon them you come to the conclusion that the owner of",
        "Bag End comes from a long line of distinguished halflings.  A cozy fire",
        "in the fireplace keeps the room warm and comfortable."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "Through the doorway you see the main room of Bag End."
          ],
          "keywords": [],
          "to": 1135
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1137,
      "name": "Pantry",
      "desc": [
        "You are inside the pantry.  Shelves filled with food and drink surround",
        "you on all sides.  You wonder why a halfling would need so much to eat.",
        "The presence of something unseen chills you to your bones.  On the floor",
        "you spy a trapdoor."
      ],
      "doors": [
        {
          "dir": "west",
          "desc": [
            "Beyond the door you see the main room of Bag End."
          ],
          "keywords": [
            "door"
          ],
          "to": 1135
        },
        {
          "dir": "down",
          "desc": [
            "It's anyone's guess as to where the trapdoor leads."
          ],
          "keywords": [],
          "to": 1156
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1138,
      "name": "A grassy field",
      "desc": [
        "You stand upon a grassy field.  A bull stands grazing not far away and",
        "out of the corner of your eye you can see him considering you.  The sound",
        "of animals fill the air from the north.  To the south you see a pig pen."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a large barn."
          ],
          "keywords": [],
          "to": 1142
        },
        {
          "dir": "east",
          "desc": [
            "You see Delving Lane."
          ],
          "keywords": [],
          "to": 1133
        },
        {
          "dir": "south",
          "desc": [
            "A rather large pig pen is to the south."
          ],
          "keywords": [],
          "to": 1139
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1139,
      "name": "Pig pen",
      "desc": [
        "You feel your boots sinking into the mud.  Numerous pigs roam about,",
        "oblivious to your company.  A grassy field is to the north while you see",
        "a small path winding to the west."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a grassy field."
          ],
          "keywords": [],
          "to": 1138
        },
        {
          "dir": "west",
          "desc": [
            "A small path winds its way eastward."
          ],
          "keywords": [],
          "to": 1140
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1140,
      "name": "A stony path",
      "desc": [
        "You walk on a stony path which leads to a small residence to the north.",
        "From the east you hear the noisy din of pigs."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "To the north you see a modest house."
          ],
          "keywords": [],
          "to": 1141
        },
        {
          "dir": "east",
          "desc": [
            "A rather large pig pen is to the east."
          ],
          "keywords": [],
          "to": 1139
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1141,
      "name": "Gamgee Residence",
      "desc": [
        "You stand inside a modest home.  You deduce that this is indeed the home",
        "of whomever owns the surrounding lands.  The air is somewhat musty and",
        "the smell reminds you of a stable.  As you look around disdainfully, you",
        "think to yourself that this is more of a shack than a proper residence and",
        "you long for the urban riches of the Shire proper."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "You see a small path winding its way southward."
          ],
          "keywords": [],
          "to": 1140
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1142,
      "name": "A barn",
      "desc": [
        "Animals of every sort fill the small barn.  You feel the hot breath of",
        "horses and cows on your neck and you feel the sudden need for fresh air.",
        "Other than that, you feel cozy and protected and don't mind staying for a",
        "bit longer.  All the warmth and good vibes remind you of the days when your",
        "mother would hold you in her arms and sing you to sleep.  You find yourself",
        "wanting to cradle all the animals."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a chicken coop to the north."
          ],
          "keywords": [],
          "to": 1143
        },
        {
          "dir": "south",
          "desc": [
            "You see a grassy field."
          ],
          "keywords": [],
          "to": 1138
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1143,
      "name": "A chicken coop",
      "desc": [
        "You stand inside a rather crowded chicken coop.  The cackle of hens fill",
        "the air.  The only exit is to the south."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "You see a large barn."
          ],
          "keywords": [],
          "to": 1142
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1144,
      "name": "The Green Dragon",
      "desc": [
        "Welcome to the Green Dragon, the undisputed leader in the art of",
        "innkeeping.  A rather charming and friendly hostess stands to the side,",
        "ready to offer you food and drink.  While most of the patrons are halfling",
        "locals, you spy an occasional human or two.  As you listen more closely",
        "to the conversations that fill the inn, you hear the tales of great and",
        "seasoned adventurers as well as the usual gossip.  You feel as if you've",
        "found your second home in the Green Dragon.  You see a stairway leading",
        "upwards."
      ],
      "doors": [
        {
          "dir": "west",
          "desc": [
            "You see Delving Lane."
          ],
          "keywords": [],
          "to": 1132
        },
        {
          "dir": "up",
          "desc": [
            "You see the reception."
          ],
          "keywords": [],
          "to": 1157
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1145,
      "name": "Shiriff Post of Delving Lane",
      "desc": [
        "You are in the Shiriff Post which acts as the nucleus for the three shiriffs",
        "of Delving Lane.  As you examine the shiriffs on duty, you come to realize",
        "that the halflings of the Shire are not to be reckoned with.  You cower with",
        "awe.  The only exit is to the west."
      ],
      "doors": [
        {
          "dir": "west",
          "desc": [
            "You see Delving Lane."
          ],
          "keywords": [],
          "to": 1133
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1146,
      "name": "A dark tunnel",
      "desc": [
        "You stand inside a small underground tunnel.  The ceiling is so low that",
        "you must crouch to avoid hitting your head.  You see light from a small",
        "hole in the ceiling while to the east you see nothing but darkness."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see a dark tunnel."
          ],
          "keywords": [],
          "to": 1147
        },
        {
          "dir": "up",
          "desc": [
            "You see a portal which leads to a small room."
          ],
          "keywords": [],
          "to": 1125
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1147,
      "name": "A dark tunnel",
      "desc": [
        "You stand inside a small underground tunnel.  The ceiling is so low that",
        "you must crouch to avoid hitting your head.  The tunnel continues east and",
        "west.  All you can see is darkness."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see a dark tunnel."
          ],
          "keywords": [],
          "to": 1148
        },
        {
          "dir": "west",
          "desc": [
            "You see a dark tunnel."
          ],
          "keywords": [],
          "to": 1146
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1148,
      "name": "A dark tunnel",
      "desc": [
        "You stand inside a small underground tunnel.  The ceiling is so low that",
        "you must crouch to avoid hitting your head.  The tunnel continues east and",
        "west.  All you can see is darkness."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see a dark tunnel."
          ],
          "keywords": [],
          "to": 1149
        },
        {
          "dir": "west",
          "desc": [
            "You see a dark tunnel."
          ],
          "keywords": [],
          "to": 1147
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1149,
      "name": "A three way intersection",
      "desc": [
        "You stand at an intersection.  The tunnel continues east and west while",
        "to the north you can barely make out a smaller trail."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a dark tunnel."
          ],
          "keywords": [],
          "to": 1151
        },
        {
          "dir": "east",
          "desc": [
            "You see a dark tunnel."
          ],
          "keywords": [],
          "to": 1150
        },
        {
          "dir": "west",
          "desc": [
            "You see a dark tunnel."
          ],
          "keywords": [],
          "to": 1148
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1150,
      "name": "End of a dark tunnel",
      "desc": [
        "You stand at the end of a dark tunnel.  The underground tunnel continues",
        "to the west.  From a trapdoor in the ceiling you can hear the din of",
        "adventurers."
      ],
      "doors": [
        {
          "dir": "west",
          "desc": [
            "You see a dark tunnel."
          ],
          "keywords": [],
          "to": 1149
        },
        {
          "dir": "up",
          "desc": [
            "You hear the din of adventurers."
          ],
          "keywords": [],
          "to": 3001
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1151,
      "name": "A dark tunnel",
      "desc": [
        "You stand inside a small underground tunnel.  The ceiling is so low that",
        "you must crouch to avoid hitting your head.  The tunnel continues north and",
        "south.  To the west you see a Shirriff Post while to the east lies a small",
        "home.  All you can see is darkness."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a dark tunnel."
          ],
          "keywords": [],
          "to": 1152
        },
        {
          "dir": "east",
          "desc": [
            "You see a halfling hole."
          ],
          "keywords": [],
          "to": 1154
        },
        {
          "dir": "south",
          "desc": [
            "You see a dark tunnel."
          ],
          "keywords": [],
          "to": 1149
        },
        {
          "dir": "west",
          "desc": [
            "Above a great oak door you see a sign which reads 'Shirriff Post'."
          ],
          "keywords": [],
          "to": 1153
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1152,
      "name": "A dark tunnel",
      "desc": [
        "You stand inside a small underground tunnel.  The ceiling is so low that",
        "you must crouch to avoid hitting your head.  The tunnel continues north and",
        "south.  To the west lies a small home.  All you can see is darkness."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a dark tunnel."
          ],
          "keywords": [],
          "to": 1156
        },
        {
          "dir": "south",
          "desc": [
            "You see a dark tunnel."
          ],
          "keywords": [],
          "to": 1151
        },
        {
          "dir": "west",
          "desc": [
            "You see a halfling hole."
          ],
          "keywords": [],
          "to": 1155
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1153,
      "name": "Shiriff Post of the Lower Shire",
      "desc": [
        "You are in the shiriff Post which acts as the nucleus for the three shiriffs",
        "of the Lower Shire.  As you examine the shiriffs on duty, you come to realize",
        "that the halflings of the Shire are not to be reckoned with.  You cower with",
        "awe.  The only exit is to the east."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see a dark tunnel."
          ],
          "keywords": [],
          "to": 1151
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1154,
      "name": "A halfling hole",
      "desc": [
        "You stand inside a rather crudely built halfling hole.  The many passageways",
        "and winding paths remind you of a rodent's lair.  The air is musty and damp",
        "and you feel the need for fresh air."
      ],
      "doors": [
        {
          "dir": "west",
          "desc": [
            "You see a dark tunnel."
          ],
          "keywords": [],
          "to": 1151
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1155,
      "name": "A halfling hole",
      "desc": [
        "You stand inside a rather crudely built halfling hole.  The many passageways",
        "and winding paths remind you of a rodent's lair.  The air is musty and damp",
        "and you feel the need for fresh air."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see a dark tunnel."
          ],
          "keywords": [],
          "to": 1152
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1156,
      "name": "End of a dark tunnel",
      "desc": [
        "You are at one end of a dark tunnel.  The tunnel continues to the south",
        "while on the ceiling you can make out a trapdoor."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "You see a dark tunnel."
          ],
          "keywords": [],
          "to": 1152
        },
        {
          "dir": "up",
          "desc": [
            "A trapdoor on the ceiling reveals a passageway."
          ],
          "keywords": [],
          "to": 1137
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 1157,
      "name": "The Inn of the Green Dragon",
      "desc": [
        "You are standing in the Inn of the Green dragon.  Large paintings of",
        "halflings at work, and halflings at play adorn the walls.  Comfortable",
        "benches and seats line the walls.  A stairway leads down."
      ],
      "doors": [
        {
          "dir": "down",
          "desc": [],
          "keywords": [],
          "to": 1144
        }
      ],
      "extended_descriptions": []
    }
  ]})"_json;
return j;
}