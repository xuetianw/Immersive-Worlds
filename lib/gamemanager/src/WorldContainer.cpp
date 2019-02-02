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
    auto solaceArea = solaceJson.get<CusJson::Area>();
    this->_area = channel::Area(solaceArea);
}

void WorldContainer::resetWorld() {
    loadFromStorage();
}


WorldContainer::WorldContainer() {
  _area = channel::Area();
}

json WorldContainer::debugArea() {
    json j = R"(
{
"AREA": {
    "name": "Town Of Solace"
  },
  "NPCS": [
    {
      "id": 10500,
      "keywords": [
        "bat"
      ],
      "shortdesc": "bat",
      "longdesc": [
        "There is a large bat here."
      ],
      "description": []
    },
    {
      "id": 10501,
      "keywords": [
        "old",
        "lady"
      ],
      "shortdesc": "old lady",
      "longdesc": [
        "There is an old lady here."
      ],
      "description": []
    },
    {
      "id": 10502,
      "keywords": [
        "tired",
        "adventurer"
      ],
      "shortdesc": "tired adventurer",
      "longdesc": [
        "There is a tired adventurer resting here."
      ],
      "description": []
    },
    {
      "id": 10503,
      "keywords": [
        "Magnus",
        "wizard"
      ],
      "shortdesc": "Magnus wizard",
      "longdesc": [
        "Magnus the wizard is resting here from his long journeys."
      ],
      "description": []
    },
    {
      "id": 10504,
      "keywords": [
        "Lord",
        "doom",
        "warrior"
      ],
      "shortdesc": "Lord Doom",
      "longdesc": [
        "Lord Doom is resting here from his long journeys."
      ],
      "description": []
    },
    {
      "id": 10505,
      "keywords": [
        "foreign",
        "trade",
        "representative"
      ],
      "shortdesc": "Foreign Trade Representative",
      "longdesc": [
        "A foreign trade representative is waiting here to meet with the Captain of the Guard."
      ],
      "description": []
    },
    {
      "id": 10506,
      "keywords": [
        "bodyguard"
      ],
      "shortdesc": "bodyguard",
      "longdesc": [
        "There is a bodyguard here."
      ],
      "description": []
    },
    {
      "id": 10507,
      "keywords": [
        "Secretary",
        "captain"
      ],
      "shortdesc": "Secretary",
      "longdesc": [
        "The Captain of the Guard's Secretary is here."
      ],
      "description": [
        "She looks very busy.",
        "The Secretary says 'Sorry, but the Captain is extremely busy today'.",
        "The Secretary says 'Please sit down and have a seat in the meantime'."
      ]
    },
    {
      "id": 10508,
      "keywords": [
        "Secretary",
        "Lieutenant"
      ],
      "shortdesc": "Secretary",
      "longdesc": [
        "The Lieutenant Commander's Secretary is here."
      ],
      "description": [
        "She looks very busy.",
        "The Secretary says 'Sorry, but the Lieutenant is extremely busy today'.",
        "The Secretary says 'Please sit down and have a seat in the meantime'."
      ]
    },
    {
      "id": 10509,
      "keywords": [
        "Secretary",
        "Sergeant"
      ],
      "shortdesc": "Secretary",
      "longdesc": [
        "The Sergeant at Arm's Secretary is here."
      ],
      "description": [
        "She looks very busy.",
        "The Secretary says 'Sorry, but the Sergeant is extremely busy today'.",
        "The Secretary says 'Please sit down and have a seat in the meantime'."
      ]
    },
    {
      "id": 10510,
      "keywords": [
        "Macaw"
      ],
      "shortdesc": "the macaw",
      "longdesc": [
        "A large macaw is here."
      ],
      "description": [
        "The macaw looks like a strong, fearless fighter. It is a beautiful bird."
      ]
    },
    {
      "id": 10511,
      "keywords": [
        "Raven"
      ],
      "shortdesc": "the raven",
      "longdesc": [
        "A large, black raven is here."
      ],
      "description": [
        "The raven looks like a strong, fearless fighter."
      ]
    },
    {
      "id": 10512,
      "keywords": [
        "hunting",
        "hawk"
      ],
      "shortdesc": "the hunting hawk",
      "longdesc": [
        "A large, hunting hawk is here."
      ],
      "description": [
        "The hawk looks like a strong, fearless fighter. It has been trained for",
        "hunting game."
      ]
    },
    {
      "id": 10513,
      "keywords": [
        "Battle",
        "falcon"
      ],
      "shortdesc": "the battle falcon",
      "longdesc": [
        "A giant, falcon is here."
      ],
      "description": [
        "The battle falcon looks like a strong, fearless fighter. This giant breed has",
        "been trained especially for combat."
      ]
    },
    {
      "id": 10514,
      "keywords": [
        "captain",
        "guard"
      ],
      "shortdesc": "Captain of the Guard",
      "longdesc": [
        "The Captain of the Guard is here."
      ],
      "description": [
        "The Captain of the Guard is an older but very powerful man. His obsidian",
        "armor seems to glow faintly. The crest of the town of Solace is displayed",
        "with pride on his chestplate. The gold crest of two coins seems to match",
        "the wealth of this town."
      ]
    },
    {
      "id": 10515,
      "keywords": [
        "lieutenant",
        "commander"
      ],
      "shortdesc": "Lieutenant Commander",
      "longdesc": [
        "The Lieutenant Commander is here."
      ],
      "description": [
        "The Lieutenant seems like a happy fellow. Although he seems to have",
        "the brain of a 7 year old. His steel armor is covered with finger paint.",
        "Dispite his mental problems he is quite a challenge. If you would like",
        "to test his abilities go right ahead. He looks as if he is quite an easy",
        "fight."
      ]
    },
    {
      "id": 10516,
      "keywords": [
        "Sergeant",
        "Arms"
      ],
      "shortdesc": "Sergeant at Arms",
      "longdesc": [
        "The Sergeant at Arms is here polishing his hammer."
      ],
      "description": [
        "This is the tough and burly Sergeant at Arms. He wears the red armor of",
        "war. He is a middle age man with graying hair that pokes out from under",
        "his helmet. He is always waiting for a fight."
      ]
    },
    {
      "id": 10517,
      "keywords": [
        "townguard",
        "guard"
      ],
      "shortdesc": "Townguard",
      "longdesc": [
        "A townguard stands here."
      ],
      "description": [
        "A big strong townguard of Solace."
      ]
    },
    {
      "id": 10518,
      "keywords": [
        "townguard",
        "guard",
        "agg"
      ],
      "shortdesc": "Townguard",
      "longdesc": [
        "A townguard stands here."
      ],
      "description": [
        "A big strong townguard of Solace."
      ]
    },
    {
      "id": 10519,
      "keywords": [
        "citizen",
        "solace"
      ],
      "shortdesc": "Citizen of Solace",
      "longdesc": [
        "A citizen of Solace stands here."
      ],
      "description": [
        "He is one of the wealthy citizens of Solace."
      ]
    },
    {
      "id": 10520,
      "keywords": [
        "woman"
      ],
      "shortdesc": "woman",
      "longdesc": [
        "A woman is here."
      ],
      "description": [
        "She is a beautiful woman."
      ]
    },
    {
      "id": 10521,
      "keywords": [
        "matt",
        "brewmaster"
      ],
      "shortdesc": "Matt the brewmaster",
      "longdesc": [
        "Matt the brewmaster is here looking for something to drink."
      ],
      "description": []
    },
    {
      "id": 10522,
      "keywords": [
        "Mcbaker"
      ],
      "shortdesc": "the Mcbaker",
      "longdesc": [
        "The Mcbaker looks at you calmly, wiping flour from his face with one hand."
      ],
      "description": [
        "A fat, nice looking baker. But you can see that he has many scars on his",
        "body."
      ]
    },
    {
      "id": 10523,
      "keywords": [
        "cookie's",
        "helper"
      ],
      "shortdesc": "Cookie's Helper",
      "longdesc": [
        "Cookie's Helper is here offering you a free cookie sample."
      ],
      "description": [
        "A young neighborhood girl helps out cookie when she is not around."
      ]
    },
    {
      "id": 10524,
      "keywords": [
        "marilyn"
      ],
      "shortdesc": "Marilyn",
      "longdesc": [
        "Marilyn is here selling birds."
      ],
      "description": [
        "She is a very pretty and loves her birds. Her black hair hangs behind her",
        "tied in a pony tail."
      ]
    },
    {
      "id": 10525,
      "keywords": [
        "ghost",
        "jander"
      ],
      "shortdesc": "Ghost of Jander",
      "longdesc": [
        "The Ghost of Jander is here."
      ],
      "description": [
        "The ghost of Jander is as he was in life. A rather large man with flaming",
        "red hair. His clothes seems dirty and tattered. His bushy beard obscures",
        "his stone face."
      ]
    },
    {
      "id": 10526,
      "keywords": [
        "ghost",
        "waiter"
      ],
      "shortdesc": "ghost of waiter",
      "longdesc": [
        "A ghost of a waiter is here waiting to serve you."
      ],
      "description": [
        "This is the ghost of a long dead waiter. Probably one of the many that",
        "Jander killed for spilling a drink or something."
      ]
    },
    {
      "id": 10527,
      "keywords": [
        "ghost",
        "barkeep"
      ],
      "shortdesc": "ghost of a barkeeper",
      "longdesc": [
        "A ghost of a barkeeper is here waiting an eternity to take your order."
      ],
      "description": [
        "This is probably another of Jander's victims. Probably got caught with",
        "his hand in the cash or something."
      ]
    },
    {
      "id": 10528,
      "keywords": [
        "townguard",
        "guard"
      ],
      "shortdesc": "Townguard",
      "longdesc": [
        "A townguard is on patrol."
      ],
      "description": [
        "A big strong townguard of Solace."
      ]
    },
    {
      "id": 10529,
      "keywords": [
        "field",
        "rat"
      ],
      "shortdesc": "field rat",
      "longdesc": [
        "A field rat is here looking for food."
      ],
      "description": [
        "A dirty nasty field rat . Obviously  looking for food in the town."
      ]
    },
    {
      "id": 10530,
      "keywords": [
        "town",
        "clerk"
      ],
      "shortdesc": "Town Clerk",
      "longdesc": [
        "The Town Clerk is here impatiently waiting for you to pay taxes."
      ],
      "description": [
        "A stringy rat like individual. He beams at you through his spectacles",
        "as if he can see the money in your pockets."
      ]
    },
    {
      "id": 10531,
      "keywords": [
        "treasury",
        "guards"
      ],
      "shortdesc": "Treasury Guards",
      "longdesc": [
        "The Treasury Guards are here guarding the town's money."
      ],
      "description": [
        "These are like the biggest and meanest men you've every seen.",
        "They look more like trolls or ogres than men."
      ]
    },
    {
      "id": 10532,
      "keywords": [
        "Jhen"
      ],
      "shortdesc": "Jhen the farmer",
      "longdesc": [
        "Jhen the farmer is here."
      ],
      "description": [
        "A rather tall man who works hard for his money."
      ]
    },
    {
      "id": 10533,
      "keywords": [
        "Krista"
      ],
      "shortdesc": "Krista the fruit peddler",
      "longdesc": [
        "Krista the fruit peddler is here."
      ],
      "description": [
        "A pretty woman who works hard for her money. Travelling every year",
        "to the market to sell her fruits."
      ]
    },
    {
      "id": 10534,
      "keywords": [
        "Janni"
      ],
      "shortdesc": "Janni",
      "longdesc": [
        "Janni is here."
      ],
      "description": [
        "Janni has spent his whole life making trinkets for people to enjoy."
      ]
    },
    {
      "id": 10535,
      "keywords": [
        "Nisi"
      ],
      "shortdesc": "Nisi the grocer",
      "longdesc": [
        "Nisi is here."
      ],
      "description": [
        "Nisi is a very interesting person. It shows in the wares she sells"
      ]
    },
    {
      "id": 10536,
      "keywords": [
        "Molin"
      ],
      "shortdesc": "Molin the brewer",
      "longdesc": [
        "Molin the brewer is here."
      ],
      "description": [
        "Molin is a grey old man with hair down to his toes."
      ]
    },
    {
      "id": 10537,
      "keywords": [
        "Rashan"
      ],
      "shortdesc": "Rashan the farmer",
      "longdesc": [
        "Rashan the farmer is here."
      ],
      "description": [
        "Rashan is a middle aged man who grows his rutabagas by candlelight."
      ]
    },
    {
      "id": 10538,
      "keywords": [
        "Lexie"
      ],
      "shortdesc": "Lexie",
      "longdesc": [
        "Lexie is here."
      ],
      "description": [
        "Lexie is an accomplish diver. But he seems to have problems keeping",
        "students."
      ]
    },
    {
      "id": 10539,
      "keywords": [
        "Croben"
      ],
      "shortdesc": "Croben",
      "longdesc": [
        "Croben is here."
      ],
      "description": [
        "Croben is a young man who learned the art of container making from his",
        "grandfather."
      ]
    },
    {
      "id": 10540,
      "keywords": [
        "otik",
        "sandath",
        "bartender"
      ],
      "shortdesc": "Otik Sandath",
      "longdesc": [
        "Otik sandath is here tending the bar"
      ],
      "description": [
        "Otik is an older man with a gift for cooking.",
        "",
        "Otik whispers, \"A magical staff! I bet it was forged by demons from the",
        "terrible Darken Wood. There are terrible mysteries in that place, there are.\""
      ]
    },
    {
      "id": 10541,
      "keywords": [
        "tika",
        "barmaid"
      ],
      "shortdesc": "Tika the barmaid",
      "longdesc": [
        "Tika the barmaid is here delivering drinks and food."
      ],
      "description": [
        "Curly auburn hair tumbles around Tika's lightly freckled face. Her striking",
        "green eyes match her low-cut blouse. She is a brash young barmaid who",
        "looks older than her 19 years. Rough living has hardened her and she",
        "presents a tough image as protection against her sense of vulnerablility."
      ]
    },
    {
      "id": 10542,
      "keywords": [
        "thief",
        "cloaked",
        "figure"
      ],
      "shortdesc": "Thief",
      "longdesc": [
        "A cloaked figure sits here."
      ],
      "description": [
        "A thin, cloaked figure sits alone at a table near the door, an untouched",
        "glass of ale before him."
      ]
    },
    {
      "id": 10543,
      "keywords": [
        "old",
        "man"
      ],
      "shortdesc": "old man",
      "longdesc": [
        "An old man is here."
      ],
      "description": [
        "He looks like an old man....go figure.."
      ]
    },
    {
      "id": 10544,
      "keywords": [
        "boy"
      ],
      "shortdesc": "boy",
      "longdesc": [
        "A small boy is here."
      ],
      "description": [
        "He is a small boy lost in his own daydreams.",
        "",
        "boy says, \"I saw the white stag up near Prayers Eye Peak just a few days",
        "ago! If only I could catch it. He who walks the paths of the white stag is",
        "blessed, I hear tell.\""
      ]
    },
    {
      "id": 10545,
      "keywords": [
        "brat",
        "boy"
      ],
      "shortdesc": "bratty boy",
      "longdesc": [
        "A brat is here."
      ],
      "description": [
        "He looks like a pain in the ass."
      ]
    },
    {
      "id": 10546,
      "keywords": [
        "Mage"
      ],
      "shortdesc": "mage",
      "longdesc": [
        "A mage is here."
      ],
      "description": [
        "He is the typical adventurer. He looks as if he has travelled far."
      ]
    },
    {
      "id": 10547,
      "keywords": [
        "Thief"
      ],
      "shortdesc": "Thief",
      "longdesc": [
        "A thief is here."
      ],
      "description": [
        "He is the typical adventurer. He looks as if he has travelled far."
      ]
    },
    {
      "id": 10548,
      "keywords": [
        "Warrior"
      ],
      "shortdesc": "Warrior",
      "longdesc": [
        "A warrior is here."
      ],
      "description": [
        "He is the typical adventurer. He looks as if he has travelled far."
      ]
    },
    {
      "id": 10549,
      "keywords": [
        "Cleric"
      ],
      "shortdesc": "Cleric",
      "longdesc": [
        "A cleric is here."
      ],
      "description": [
        "He is the typical adventurer. He looks as if he has travelled far."
      ]
    },
    {
      "id": 10550,
      "keywords": [
        "ghost",
        "gambler"
      ],
      "shortdesc": "Ghost of gambler",
      "longdesc": [
        "A ghost of a gambler is floating here looking for something to bet on."
      ],
      "description": [
        "Even in death this sad spirit is looking to gamble."
      ]
    },
    {
      "id": 10551,
      "keywords": [
        "child"
      ],
      "shortdesc": "child",
      "longdesc": [
        "A child is here eating bugs off the ground."
      ],
      "description": []
    },
    {
      "id": 10552,
      "keywords": [
        "rat"
      ],
      "shortdesc": "rat",
      "longdesc": [
        "There is a large rat here."
      ],
      "description": []
    }
  ],
  "ROOMS": [
    {
      "id": 10500,
      "name": "Lexie's Scuba Shop",
      "desc": [
        "This is one shop that seems to be ahead of its time.",
        "But who doesn't like scuba diving. If you don't already have",
        "a diving license you can buy one. Lexie can also train you too. Not  in",
        "scuba though. Something about a revoked teaching credential due to too",
        "many students dying or something. This does seem to be an odd place to have",
        "a scuba shop considering the sea is miles away. But I guess you could",
        "always go diving in the lake. But why?....",
        "There is a small sign here."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "You see the marketplace."
          ],
          "keywords": [],
          "to": 10608
        }
      ],
      "extended_descriptions": [
        {
          "keywords": [
            "sign"
          ],
          "desc": [
            "The sign reads:",
            "",
            "  List  - Show which various items are in the store.",
            "  Buy   - Buy an item.",
            "  Value - The shopkeeper will (free of charge) tell how much he will",
            "          pay for your item.",
            "  Sell  - Sell an item."
          ]
        }
      ]
    },
    {
      "id": 10501,
      "name": "Croben's Containers.",
      "desc": [
        "This is the catch all, hold all, container shop. Croben sell all sorts.",
        "Just take your pick. And no he doesn't know how much each one holds.",
        "What...you think he has nothing better to do than fill each container",
        "just to see how much it holds? Get a life....",
        "There is a small sign here."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "You see the marketplace."
          ],
          "keywords": [],
          "to": 10607
        }
      ],
      "extended_descriptions": [
        {
          "keywords": [
            "sign"
          ],
          "desc": [
            "The sign reads:",
            "",
            "  List  - Show which various items are in the store.",
            "  Buy   - Buy an item.",
            "  Value - The shopkeeper will (free of charge) tell how much he will",
            "          pay for your item.",
            "  Sell  - Sell an item."
          ]
        }
      ]
    },
    {
      "id": 10502,
      "name": "Matt's Brewery.",
      "desc": [
        "Matt could never find enough to drink. So to solve this he started his own",
        "brewery. \"You can never drink enough\" is Matt's logo and offers plenty",
        "to drink.",
        "There is a small sign here."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see West Gullen Way."
          ],
          "keywords": [],
          "to": 10602
        }
      ],
      "extended_descriptions": [
        {
          "keywords": [
            "sign"
          ],
          "desc": [
            "The sign reads:",
            "",
            "  List  - Show which various items are in the store.",
            "  Buy   - Buy an item.",
            "  Value - The shopkeeper will (free of charge) tell how much he will",
            "          pay for your item.",
            "  Sell  - Sell an item."
          ]
        }
      ]
    },
    {
      "id": 10503,
      "name": "a House.",
      "desc": [
        "This is a small house off of West Gullen Way. It is not your house and you",
        "were not invited. Why are you here?"
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see West Gullen Way."
          ],
          "keywords": [
            "door"
          ],
          "to": 10603
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10504,
      "name": "a House.",
      "desc": [
        "This is a small house off of West Gullen Way. It is sparsely furnished and",
        "very tidy. a small fire burns warmly in the fireplace. The sweet smell of",
        "flowers is present. Ahhh....what a nice home."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see West Gullen Way."
          ],
          "keywords": [
            "door"
          ],
          "to": 10604
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10505,
      "name": "Cookie's Cookie Cookery.",
      "desc": [
        "This is the cookie shop of who else...Cookie. She's not in right now",
        "but there are many delicious cookies to munch on if you want to wait till",
        "she returns."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see the Main road of Solace."
          ],
          "keywords": [],
          "to": 10580
        },
        {
          "dir": "west",
          "desc": [
            "You see a door."
          ],
          "keywords": [
            "door"
          ],
          "to": 10510
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10506,
      "name": "a House.",
      "desc": [
        "This is a small house off of the main street. It is well furnished and",
        "very tidy. a small fire burns warmly in the fireplace. The sweet smell of",
        "flowers is present. Ahhh....what a nice home."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see the Main road of Solace."
          ],
          "keywords": [
            "door"
          ],
          "to": 10579
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10507,
      "name": "Old Gambling Parlor.",
      "desc": [
        "This used to be a very popular and busy gambling parlor. But the Captain",
        "of the Guard lost big here once and thereafter declared gambling illegal.",
        "It has been closed for many years. It is dusty and full of cobwebs."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "You see a small alleyway."
          ],
          "keywords": [
            "door"
          ],
          "to": 10595
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10508,
      "name": "The McBakery",
      "desc": [
        "You are standing inside the small bakery.  A sweet scent of McDanish",
        "and fine McBread fills the room.  The McBread and McDanish are arranged",
        "in fine order on the McShelves, and seem to be of the finest McQuality. You",
        "remember seeing a place like this somewhere before. Maybe its a McChain?",
        "A small McSign is on the McCounter."
      ],
      "doors": [
        {
          "dir": "west",
          "desc": [
            "You see Harvest road."
          ],
          "keywords": [],
          "to": 10598
        }
      ],
      "extended_descriptions": [
        {
          "keywords": [
            "sign"
          ],
          "desc": [
            "Free instructions provided by the store:",
            "",
            "   Buy  - Will buy you some McBread or McPastry.",
            "   List - The McBaker will kindly tell you the price and sort of the McBread in",
            "          his McBakery."
          ]
        }
      ]
    },
    {
      "id": 10509,
      "name": "a House.",
      "desc": [
        "This is a small house off of the main street. It is well furnished and",
        "very tidy. a small fire burns warmly in the fireplace. The sweet smell of",
        "flowers is present. Ahhh....what a nice home."
      ],
      "doors": [
        {
          "dir": "west",
          "desc": [
            "You see Harvest road."
          ],
          "keywords": [
            "door"
          ],
          "to": 10599
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10510,
      "name": "Cookie's Relaxing Room.",
      "desc": [
        "This is where Cookie comes to unwind. She comes here sometimes to just",
        "munch on cookies and talk to her friends."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see the front of the store."
          ],
          "keywords": [
            "door"
          ],
          "to": 10505
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10511,
      "name": "a House.",
      "desc": [
        "This is a small house off of West Gullen Way. It is not your house and you",
        "were not invited. Why are you here?"
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see East Gullen Way."
          ],
          "keywords": [
            "door"
          ],
          "to": 10583
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10512,
      "name": "The Marilyn's Bird Factory.",
      "desc": [
        "This is Marilyn's Bird Factory. There are a wide variety of birds here.",
        "Buy a pet. Take it home. A loving companion to keep you company."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see East Gullen Way."
          ],
          "keywords": [],
          "to": 10584
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10513,
      "name": "Pet Storage",
      "desc": [
        "This is where Marilyn keeps her birds. It is important that this room be",
        "right after the bird factory."
      ],
      "doors": [],
      "extended_descriptions": []
    },
    {
      "id": 10514,
      "name": "Storage Building",
      "desc": [
        "This is an abandon storage building. Its empty walls used to house large",
        "amounts of surplus equipment for the market and various vendors. Sales",
        "have been good lately and all surplus has been sold. It seems supply has",
        "yet to catch up to demand."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see Ketra Road."
          ],
          "keywords": [
            "door"
          ],
          "to": 10588
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10515,
      "name": "Jander's",
      "desc": [
        "Jander's bar used to be a very popular bar in Solace. For some reason or",
        "another it is now empty. Dust and cobwebs cover everything. It looks as if",
        "nobody has tread here in years. The bar is hidden beneath broken bottles",
        "and shattered glasses. Tables and chairs are scattered all over the floor.",
        "There is a sign on the wall.",
        "There is a door to Ketra Road to the east."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see Ketra Road."
          ],
          "keywords": [
            "door"
          ],
          "to": 10589
        },
        {
          "dir": "west",
          "desc": [
            "You see the poolhall."
          ],
          "keywords": [],
          "to": 10516
        }
      ],
      "extended_descriptions": [
        {
          "keywords": [
            "sign"
          ],
          "desc": [
            "Welcome to Jander's!",
            "",
            "Drink and be Merry!!!!",
            "",
            "But Remember don't Marry after you drink....",
            "",
            "-Jander-"
          ]
        }
      ]
    },
    {
      "id": 10516,
      "name": "Jander's Poolhall",
      "desc": [
        "Jander's bar used to be a very popular bar in Solace. For some reason or",
        "another it is now empty. Dust and cobwebs cover everything. It looks as if",
        "nobody has tread here in years. The bar is to the east. The pooltables are",
        "broken in half and lie in a heap on the floor.",
        "There is a sign on the door to Jander's office.",
        "A backdoor to the alley is to the south."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see Jander's office door."
          ],
          "keywords": [
            "office",
            "door"
          ],
          "to": 10519
        },
        {
          "dir": "east",
          "desc": [
            "You see the bar."
          ],
          "keywords": [],
          "to": 10515
        },
        {
          "dir": "south",
          "desc": [
            "You see a backdoor to the alley."
          ],
          "keywords": [
            "door",
            "backdoor"
          ],
          "to": 10592
        },
        {
          "dir": "west",
          "desc": [
            "You see the restaurant."
          ],
          "keywords": [],
          "to": 10517
        }
      ],
      "extended_descriptions": [
        {
          "keywords": [
            "sign"
          ],
          "desc": [
            "*Jander's Office*",
            "",
            "Read this sign!",
            "",
            "And then GO AWAY!!",
            "",
            "-Jander-"
          ]
        }
      ]
    },
    {
      "id": 10517,
      "name": "Jander's Restaurant",
      "desc": [
        "Jander's bar and restaurant used to be a very popular bar in Solace.",
        "For some reason or another it is now empty. Dust and cobwebs cover",
        "everything. It looks as if nobody has tread here in years.",
        "The poolhall and bar are to the east.",
        "A door to the main road is to the west."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see the poolhall."
          ],
          "keywords": [],
          "to": 10516
        },
        {
          "dir": "west",
          "desc": [
            "You see the main road of Solace."
          ],
          "keywords": [
            "door"
          ],
          "to": 10579
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10518,
      "name": "Death's Chambers",
      "desc": [
        "This is the Chamber of Death. If you are lucky, he isn't here right now.",
        "The walls are covered with twisted faces of a countless tortured",
        "souls crying out in agony. The floor is made of black marble as is the",
        "ceiling. The air smells of brimstone and makes your lungs burn with",
        "every breath.",
        "There is a sign floating in front of you."
      ],
      "doors": [],
      "extended_descriptions": [
        {
          "keywords": [
            "sign"
          ],
          "desc": [
            "Please sit and wait.",
            "",
            "Death will be with you shortly.",
            "",
            "\"Those who wait for death are indeed lost souls...\""
          ]
        }
      ]
    },
    {
      "id": 10519,
      "name": "Jander's Office",
      "desc": [
        "This is Jander's Office and obviously you didn't read the sign before",
        "coming in.The office is dusty and abandon like the rest of the bar, but is",
        "otherwise in the same condition as when it was occupied. An oak desk",
        "sits in the middle of the room. A bookcase rests against the wall. Various",
        "chairs are set in front of the desk. An employee that was called into Jander's",
        "office was not likely to leave. Jander was rarely if ever seen. He mostly",
        "stayed in his office and did office stuff. He was never in a good mood.",
        "The office door is to the south."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "You see the poolhall."
          ],
          "keywords": [
            "door"
          ],
          "to": 10516
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10520,
      "name": "Inside Southeast Watchtower.",
      "desc": [
        "You are inside the Southeast Watchtower.",
        "From up here you can see above the trees and most of the valley.",
        "There is a beautiful view of Crystalmir lake.",
        "Well actually the Southwest watchtower is blocking some of your view.",
        "You are however not suppose to be up here. If the guards catch you up",
        "here you are likely to be in BIG trouble..."
      ],
      "doors": [
        {
          "dir": "down",
          "desc": [
            "You see stairs leading down to the guardpost."
          ],
          "keywords": [],
          "to": 10590
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10521,
      "name": "Inside Southwest Watchtower.",
      "desc": [
        "You are inside the Southwest Watchtower.",
        "From up here you can see above the trees and most of the valley.",
        "There is a beautiful view of Crystalmir lake.",
        "You are however not suppose to be up here. If the guards catch you up",
        "here you are likely to be in BIG trouble..."
      ],
      "doors": [
        {
          "dir": "down",
          "desc": [
            "You see stairs leading down to the guardpost."
          ],
          "keywords": [],
          "to": 10597
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10522,
      "name": "Dusty road.",
      "desc": [
        "This dusty road looks well traveled. To the East you see the Townguard",
        "Administration Building."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see the Townguard Administration Building."
          ],
          "keywords": [],
          "to": 10523
        },
        {
          "dir": "west",
          "desc": [
            "You see the end of Main road."
          ],
          "keywords": [],
          "to": 10606
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10523,
      "name": "Townguard Administration Building.",
      "desc": [
        "Before you stands the Townguard Administration Building. This is a large",
        "building with various statues and other artwork decorating the building.",
        "There is a door the east."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see entrance hall."
          ],
          "keywords": [
            "door"
          ],
          "to": 10524
        },
        {
          "dir": "west",
          "desc": [
            "You see a dusty road."
          ],
          "keywords": [],
          "to": 10522
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10524,
      "name": "Entrance Hall.",
      "desc": [
        "The entrance hall is made entirely of marble and granite. It seems sort of",
        "extravagant for a townguard administration building. The 30 foot high",
        "ceiling seems to dwarf everything in the hallway. The Seal of the Town",
        "of Solace lies embedded in the center of the floor.",
        "A pair of heavy double doors lies to the east.",
        "The entrance door is to the west."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see a pair of heavy double doors."
          ],
          "keywords": [
            "doors"
          ],
          "to": 10530
        },
        {
          "dir": "south",
          "desc": [
            "You see a marble corridor."
          ],
          "keywords": [],
          "to": 10525
        },
        {
          "dir": "west",
          "desc": [
            "You see the entrance to the building."
          ],
          "keywords": [
            "door"
          ],
          "to": 10523
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10525,
      "name": "Marble Corridor.",
      "desc": [
        "This corridor is also decorated with paintings and sculptures. Marble",
        "columns line the walls. Crystal chandeliers hang from the ceiling.",
        "A door to the Town Clerk's office is to the west."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see the entrance hallway."
          ],
          "keywords": [],
          "to": 10524
        },
        {
          "dir": "east",
          "desc": [
            "You see marble corridor."
          ],
          "keywords": [],
          "to": 10528
        },
        {
          "dir": "west",
          "desc": [
            "You see the door to the Town Clerk's Office."
          ],
          "keywords": [
            "door",
            "officedoor"
          ],
          "to": 10526
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10526,
      "name": "Town Clerk.",
      "desc": [
        "This is where you pay your fines and taxes.",
        "The Town Clerk's desk sits in front of you. There are chairs and a",
        "few tables along the walls. There is a metal door on the west wall",
        "behind the clerk's desk.",
        "The hallway is to the east.",
        "A heavy metal depository door is to the west."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see a marble corridor."
          ],
          "keywords": [],
          "to": 10525
        },
        {
          "dir": "west",
          "desc": [
            "You see a heavy metal door."
          ],
          "keywords": [
            "safe"
          ],
          "to": 10527
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10527,
      "name": "Deposits Room.",
      "desc": [
        "This is a large safe like room. All payments for taxes and fines are deposited",
        "here by the clerk. The walls are made of white marble and have gold deposit",
        "boxes set into them.",
        "The safe door is to the east."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see Town Clerks Office."
          ],
          "keywords": [
            "safe"
          ],
          "to": 10526
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10528,
      "name": "Marble Corridor.",
      "desc": [
        "This corridor is also decorated with paintings and sculptures. Marble",
        "columns line the walls. Crystal chandeliers hang from the ceiling.",
        "A pair of heavy double doors lie to the north."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a pair of heavy double doors."
          ],
          "keywords": [
            "doors"
          ],
          "to": 10530
        },
        {
          "dir": "east",
          "desc": [
            "You see a fountain."
          ],
          "keywords": [],
          "to": 10529
        },
        {
          "dir": "west",
          "desc": [
            "You see a marble corridor."
          ],
          "keywords": [],
          "to": 10525
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10529,
      "name": "Water Fountain.",
      "desc": [
        "There is a very large water fountain here. Large marble lion heads spout",
        "water from their mouths and stone fish spit water from the base of the",
        "fountain."
      ],
      "doors": [
        {
          "dir": "west",
          "desc": [
            "You see marble corridor."
          ],
          "keywords": [],
          "to": 10528
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10530,
      "name": "Hallway Intersection.",
      "desc": [
        "This is the intersection of four large hallways. Light streams in from the",
        "stainglass skylight above. Large double doors close off each hallway.",
        "The doors are made of oak and encrusted with gold patterns.",
        "A pair of double doors are in each direction."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a pair of double doors."
          ],
          "keywords": [
            "doors"
          ],
          "to": 10536
        },
        {
          "dir": "east",
          "desc": [
            "You see a pair of double doors."
          ],
          "keywords": [
            "doors"
          ],
          "to": 10531
        },
        {
          "dir": "south",
          "desc": [
            "You see a pair of double doors."
          ],
          "keywords": [
            "doors"
          ],
          "to": 10528
        },
        {
          "dir": "west",
          "desc": [
            "You see a pair of double doors."
          ],
          "keywords": [
            "doors"
          ],
          "to": 10524
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10531,
      "name": "End of Long Hall",
      "desc": [
        "This is the end of a long and lavish hallway. exquisite paintings and",
        "statues line the walls. The ceilings are covered with colorful mosaics.",
        "A pair of double doors lie to the west."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see a long hallway."
          ],
          "keywords": [],
          "to": 10537
        },
        {
          "dir": "west",
          "desc": [
            "You see a pair of double doors."
          ],
          "keywords": [
            "doors"
          ],
          "to": 10530
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10532,
      "name": "Cobblestone Path",
      "desc": [
        "You are walking on a cobblestone path. It leads to a large building to the",
        "north."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a large building ahead."
          ],
          "keywords": [],
          "to": 10542
        },
        {
          "dir": "south",
          "desc": [
            "You see the end of Main road."
          ],
          "keywords": [],
          "to": 10606
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10533,
      "name": "Sergeant's Reception Room",
      "desc": [
        "This room is decorated with various swords and other ornamental artifacts",
        "of combat. Pictures of bloody battles adorn the walls. If you have an",
        "appointment to see the Sergeant at Arms this is where you'd come to wait.",
        "But who knows how long you'll have to wait...",
        "The door to the Sergeant's office is to the north.",
        "The door to the hallway is on the east wall."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see an Iron bound door."
          ],
          "keywords": [
            "door"
          ],
          "to": 10543
        },
        {
          "dir": "east",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [
            "door"
          ],
          "to": 10534
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10534,
      "name": "Administration Hallway",
      "desc": [
        "The hallway is just as extravagant as all the others in this building.",
        "Gem mosaics cover the walls, and intricate patterns are carved in the",
        "gold laden floors. This doesn't look like an admistration building,",
        "more like a palace.",
        "The Sergeant's waiting room is to the west."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10544
        },
        {
          "dir": "east",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10535
        },
        {
          "dir": "west",
          "desc": [
            "You see a reception area."
          ],
          "keywords": [
            "door"
          ],
          "to": 10533
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10535,
      "name": "Administration Hallway",
      "desc": [
        "The hallway is just as extravagant as all the others in this building.",
        "Gem mosaics cover the walls, and intricate patterns are carved in the",
        "gold laden floors. This doesn't look like an admistration building,",
        "more like a palace.",
        "There is an oak door to the north."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see an oak door."
          ],
          "keywords": [
            "oak",
            "door"
          ],
          "to": 10545
        },
        {
          "dir": "east",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10536
        },
        {
          "dir": "west",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10534
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10536,
      "name": "Administration Hallway",
      "desc": [
        "The hallway is just as extravagant as all the others in this building.",
        "Gem mosaics cover the walls, and intricate patterns are carved in the",
        "gold laden floors. This doesn't look like an admistration building,",
        "more like a palace.",
        "A pair of double doors are south of you."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10546
        },
        {
          "dir": "south",
          "desc": [
            "You see double doors."
          ],
          "keywords": [
            "doors"
          ],
          "to": 10530
        },
        {
          "dir": "west",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10535
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10537,
      "name": "Long Hallway",
      "desc": [
        "This hallway is sparse compared to some of the others. It seems to go",
        "on and on. The marble floors are barren of any type of decorations.",
        "The walls are rough stone bound by large wooden beams. This is maybe",
        "the only hallway that doesn't have large amounts of gold and other artifacts."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a long hallway."
          ],
          "keywords": [],
          "to": 10547
        },
        {
          "dir": "south",
          "desc": [
            "You see the end of the hallway."
          ],
          "keywords": [],
          "to": 10531
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10538,
      "name": "West end of Common Room",
      "desc": [
        "You are standing in the West end of a very large room. It is where",
        "adventurers rest their weary feet if they don't have enough gold to",
        "pay for a private room. The room continues to the East."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see more of a very large room."
          ],
          "keywords": [],
          "to": 10539
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10539,
      "name": "East end of Common Room",
      "desc": [
        "You are standing in the East end of a very large room. It is where",
        "adventurers rest their weary feet if they don't have enough gold to",
        "pay for a private room. The room continues to the west.",
        "A door to the hallway is to the north."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a large hallway."
          ],
          "keywords": [
            "door"
          ],
          "to": 10549
        },
        {
          "dir": "west",
          "desc": [
            "You see more of a very large room."
          ],
          "keywords": [],
          "to": 10538
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10540,
      "name": "West end of Bar.",
      "desc": [
        "You are standing of the west end of the bar. This is a darker corner where",
        "less seems to occur. Maybe a beer and a nap would be nice."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see main bar."
          ],
          "keywords": [],
          "to": 10541
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10541,
      "name": "Inn of the Last Home.",
      "desc": [
        "The Inn of the Last Home never changes. The polished wooden bar curves",
        "around several living branches. An old man weaves stories in the corner and",
        "delights the crowd gathered about him. The delicate windows of stained",
        "glass behind the bar are being polished by Otik Sandath, the barkeeper.",
        "The carved door to the Inn is to the east."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see north end of the bar."
          ],
          "keywords": [],
          "to": 10551
        },
        {
          "dir": "east",
          "desc": [
            "You see a carved door."
          ],
          "keywords": [
            "door"
          ],
          "to": 10542
        },
        {
          "dir": "west",
          "desc": [
            "You see the west end of the bar."
          ],
          "keywords": [],
          "to": 10540
        },
        {
          "dir": "up",
          "desc": [
            "You see a wooden staircase."
          ],
          "keywords": [],
          "to": 10550
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10542,
      "name": "Outside the Inn of the Last Home.",
      "desc": [
        "The Inn of the Last Home rests within the trunk of a huge vallenwood tree.",
        "Warm laughter tumbles from the inn. The worn steps wind around the heavy",
        "trunk up to the familiar, carved door."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see trees"
          ],
          "keywords": [
            "tree"
          ],
          "to": 10552
        },
        {
          "dir": "south",
          "desc": [
            "You see a cobblestone path."
          ],
          "keywords": [],
          "to": 10532
        },
        {
          "dir": "west",
          "desc": [
            "You see a carved door."
          ],
          "keywords": [
            "door"
          ],
          "to": 10541
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10543,
      "name": "Sergeant's Office",
      "desc": [
        "This is the office of the Sergeant at Arms. He is in charge of all minor",
        "complaints. His office is richly decorated with ornamental weapons and",
        "pictures of war. A large desk sits in the middle of the room.",
        "You see an Iron bound door to the south."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "You see an Iron bound door."
          ],
          "keywords": [
            "door"
          ],
          "to": 10533
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10544,
      "name": "Administration Hallway",
      "desc": [
        "The hallway is just as extravagant as all the others in this building.",
        "Gem mosaics cover the walls, and intricate patterns are carved in the",
        "gold laden floors. This doesn't look like an admistration building,",
        "more like a palace."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10554
        },
        {
          "dir": "south",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10534
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10545,
      "name": "Guards Room.",
      "desc": [
        "There are many barrels and chests of food in here. All of it looks spoiled.",
        "This is where the town guards hang out when not on duty.",
        "You see an oak door to the south."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "You see an oak door."
          ],
          "keywords": [
            "door"
          ],
          "to": 10535
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10546,
      "name": "Administration Hallway",
      "desc": [
        "The hallway is just as extravagant as all the others in this building.",
        "Gem mosaics cover the walls, and intricate patterns are carved in the",
        "gold laden floors. This doesn't look like an admistration building,",
        "more like a palace."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10556
        },
        {
          "dir": "south",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10536
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10547,
      "name": "Long Hallway",
      "desc": [
        "This hallway is sparse compared to some of the others. It seems to go",
        "on and on. The marble floors are barren of any type of decorations.",
        "The walls are rough stone bound by large wooden beams. This is maybe",
        "the only hallway that doesn't have large amounts of gold and other artifacts."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a long hallway."
          ],
          "keywords": [],
          "to": 10557
        },
        {
          "dir": "south",
          "desc": [
            "You see a long hallway."
          ],
          "keywords": [],
          "to": 10537
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10548,
      "name": "Hallway",
      "desc": [
        "You are standing in an old vallenwood hallway."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10558
        },
        {
          "dir": "east",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10549
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10549,
      "name": "Outside Common Room",
      "desc": [
        "You are standing in an old vallenwood hallway. Laughter and the murmur",
        "of conversation comes from the south.",
        "The door to the common room lies to the south."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10550
        },
        {
          "dir": "south",
          "desc": [
            "You see the common room."
          ],
          "keywords": [
            "door"
          ],
          "to": 10539
        },
        {
          "dir": "west",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10548
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10550,
      "name": "Second Floor of the Inn.",
      "desc": [
        "You are at the top of a wooden staircase. Downstairs is the bar.",
        "To the west you can hear laughter and the low murmur of voices."
      ],
      "doors": [
        {
          "dir": "west",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10549
        },
        {
          "dir": "down",
          "desc": [
            "You see a wooden staircase."
          ],
          "keywords": [],
          "to": 10541
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10551,
      "name": "North End of Bar.",
      "desc": [
        "A smoky fire struggles in the blackened stove, feebly challenging",
        "the gloom in the town. In sharp contrast to the usual lively crowd,",
        "the few patrons present are lost in their own thoughts. No one",
        "smiles, nor does anyone seem interested in the arrival of a few",
        "more customers."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "You see main bar."
          ],
          "keywords": [],
          "to": 10541
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10552,
      "name": "Captain's Office.",
      "desc": [
        "This is the office of the Captain of the Guard. Leather couches",
        "and a solid marble desk sit against the far wall. A weapons",
        "cabinet stands against the west wall. The Captain has a large",
        "portrait of himself on the wall behind his desk.",
        "A pair of heavy metal doors with the emblem of the townguard",
        "is on the north wall."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a set of Heavy Metal Doors with the emblem of the townguard."
          ],
          "keywords": [
            "doors"
          ],
          "to": 10562
        },
        {
          "dir": "south",
          "desc": [
            "A wall."
          ],
          "keywords": [
            "wall"
          ],
          "to": 10542
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10553,
      "name": "Administration Hallway",
      "desc": [
        "The hallway is just as extravagant as all the others in this building.",
        "Gem mosaics cover the walls, and intricate patterns are carved in the",
        "gold laden floors. This doesn't look like an admistration building,",
        "more like a palace."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10563
        },
        {
          "dir": "east",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10554
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10554,
      "name": "Administration Hallway",
      "desc": [
        "The hallway is just as extravagant as all the others in this building.",
        "Gem mosaics cover the walls, and intricate patterns are carved in the",
        "gold laden floors. This doesn't look like an admistration building,",
        "more like a palace."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see a reception area."
          ],
          "keywords": [],
          "to": 10555
        },
        {
          "dir": "south",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10544
        },
        {
          "dir": "west",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10553
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10555,
      "name": "Lieutenant's Reception Area.",
      "desc": [
        "This is the waiting room for meetings with the Lieutenant Commander.",
        "The furniture is made of vallenwood and the walls are covered with",
        "finger paintings. Various crayon drawings are framed behind the",
        "secretary 's desk.",
        "A glass door with the townguard emblem is to the north."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a glass door with the townguard emblem."
          ],
          "keywords": [
            "door"
          ],
          "to": 10565
        },
        {
          "dir": "west",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10554
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10556,
      "name": "Administration Hallway",
      "desc": [
        "The hallway is just as extravagant as all the others in this building.",
        "Gem mosaics cover the walls, and intricate patterns are carved in the",
        "gold laden floors. This doesn't look like an admistration building,",
        "more like a palace."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10566
        },
        {
          "dir": "south",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10546
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10557,
      "name": "Long Hallway",
      "desc": [
        "This hallway is sparse compared to some of the others. It seems to go",
        "on and on. The marble floors are barren of any type of decorations.",
        "The walls are rough stone bound by large wooden beams. This is maybe",
        "the only hallway that doesn't have large amounts of gold and other artifacts."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10567
        },
        {
          "dir": "south",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10547
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10558,
      "name": "Hallway",
      "desc": [
        "You are standing in an old vallenwood hallway."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see reading room."
          ],
          "keywords": [],
          "to": 10568
        },
        {
          "dir": "south",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10548
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10559,
      "name": "Private Room",
      "desc": [
        "This is a private room. Those with some money can rent these rooms instead",
        "of staying in the common room. It is well furnished with a large bed and",
        "other bedroom stuff.",
        "There is a door to the north."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a door."
          ],
          "keywords": [
            "door"
          ],
          "to": 10569
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10560,
      "name": "Private Room",
      "desc": [
        "This is a private room. Those with some money can rent these rooms instead",
        "of staying in the common room. It is well furnished with a large bed and",
        "other bedroom stuff.",
        "There is a door to the north."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a door."
          ],
          "keywords": [
            "door"
          ],
          "to": 10570
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10561,
      "name": "Private Room",
      "desc": [
        "This is a private room. Those with some money can rent these rooms instead",
        "of staying in the common room. It is well furnished with a large bed and",
        "other bedroom stuff.",
        "There is a door to the north."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a door."
          ],
          "keywords": [
            "door"
          ],
          "to": 10571
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10562,
      "name": "Captain's Meeting room.",
      "desc": [
        "You are standing in the meeting room of the Captain of the Guard. This",
        "is where he holds his administrative meetings and other official functions.",
        "A large meeting tables sits in the middle of the room.",
        "There is a pair of glass double doors to the north.",
        "There is a pair of heavy metal doors with the emblem of the",
        "townguard to the south."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see Glass Double Doors."
          ],
          "keywords": [
            "doors"
          ],
          "to": 10572
        },
        {
          "dir": "south",
          "desc": [
            "You see a set of Heavy Metal Doors with the emblem of the townguard."
          ],
          "keywords": [
            "doors"
          ],
          "to": 10552
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10563,
      "name": "Administration Hallway",
      "desc": [
        "The hallway is just as extravagant as all the others in this building.",
        "Gem mosaics cover the walls, and intricate patterns are carved in the",
        "gold laden floors. This doesn't look like an admistration building,",
        "more like a palace."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10573
        },
        {
          "dir": "south",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10553
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10564,
      "name": "Guards Room.",
      "desc": [
        "There are many barrels and chests of food in here. All of it looks spoiled.",
        "This is where the town guards hang out when not on duty.",
        "There is an oak door to the north."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a oak door."
          ],
          "keywords": [
            "door"
          ],
          "to": 10574
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10565,
      "name": "Lieutenant's Office.",
      "desc": [
        "This is the Office of the Lieutenant Commander. He basicially does",
        "nothing all day. Hence the fingerpainting tacked to all the walls.",
        "The furniture is more fitting to a 7 year old than that of a commander.",
        "Small plastic furniture and plastic flowers adorn the office.",
        "You see a glass door with the townguard emblem to the south."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "You see a glass door."
          ],
          "keywords": [
            "door"
          ],
          "to": 10555
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10566,
      "name": "Administration Hallway",
      "desc": [
        "The hallway is just as extravagant as all the others in this building.",
        "Gem mosaics cover the walls, and intricate patterns are carved in the",
        "gold laden floors. This doesn't look like an admistration building,",
        "more like a palace."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10576
        },
        {
          "dir": "south",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10556
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10567,
      "name": "Long Hallway",
      "desc": [
        "This hallway is sparse compared to some of the others. It seems to go",
        "on and on. The marble floors are barren of any type of decorations.",
        "The walls are rough stone bound by large wooden beams. This is maybe",
        "the only hallway that doesn't have large amounts of gold and other artifacts."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see the end of a long hallway."
          ],
          "keywords": [],
          "to": 10577
        },
        {
          "dir": "south",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10557
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10568,
      "name": "Reading Room.",
      "desc": [
        "This is an afternoon reading room. Its especially nice on sunny days when",
        "the afternoon sun shines through the large picture window. Many books",
        "line the walls. All look pretty boring and seem to be more for show than",
        "for reading."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10569
        },
        {
          "dir": "south",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10558
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10569,
      "name": "Hallway",
      "desc": [
        "You are standing in an old vallenwood hallway.",
        "This corridor is lined with the more expensive private rooms.",
        "There is a door to the south."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10570
        },
        {
          "dir": "south",
          "desc": [
            "You see a door."
          ],
          "keywords": [
            "door"
          ],
          "to": 10559
        },
        {
          "dir": "west",
          "desc": [
            "You see a reading room."
          ],
          "keywords": [],
          "to": 10568
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10570,
      "name": "Hallway",
      "desc": [
        "You are standing in an old vallenwood hallway.",
        "This corridor is lined with the more expensive private rooms.",
        "There is a door to the south."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10571
        },
        {
          "dir": "south",
          "desc": [
            "You see a door."
          ],
          "keywords": [
            "door"
          ],
          "to": 10560
        },
        {
          "dir": "west",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10569
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10571,
      "name": "Hallway",
      "desc": [
        "You are standing in an old vallenwood hallway.",
        "This corridor is lined with the more expensive private rooms.",
        "There is a door to the south."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "You see a door."
          ],
          "keywords": [
            "door"
          ],
          "to": 10561
        },
        {
          "dir": "west",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10570
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10572,
      "name": "Captain's Waiting Room.",
      "desc": [
        "This is the Reception area for the the Captain of the Guard. A large portrait",
        "of the Captain is on the north wall. With the amount of extravagance and",
        "expensive items that decorate this room you wonder how he gets away with",
        "it. The title Sultan would be more appropriate than Captain of the Guard.",
        "You see an oak door to the east.",
        "There are a pair of glass double doors to the south."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see a oak door."
          ],
          "keywords": [
            "door"
          ],
          "to": 10573
        },
        {
          "dir": "south",
          "desc": [
            "You see Glass Double Doors."
          ],
          "keywords": [
            "doors"
          ],
          "to": 10562
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10573,
      "name": "Administration Hallway",
      "desc": [
        "The hallway is just as extravagant as all the others in this building.",
        "Gem mosaics cover the walls, and intricate patterns are carved in the",
        "gold laden floors. This doesn't look like an admistration building,",
        "more like a palace.",
        "The Captain of the Guard's waiting room is to the west."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10574
        },
        {
          "dir": "south",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10563
        },
        {
          "dir": "west",
          "desc": [
            "You see Captain's waiting room door."
          ],
          "keywords": [
            "door"
          ],
          "to": 10572
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10574,
      "name": "Administration Hallway",
      "desc": [
        "The hallway is just as extravagant as all the others in this building.",
        "Gem mosaics cover the walls, and intricate patterns are carved in the",
        "gold laden floors. This doesn't look like an admistration building,",
        "more like a palace.",
        "There is an oak door to the south."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10575
        },
        {
          "dir": "south",
          "desc": [
            "You see a oak door."
          ],
          "keywords": [
            "door"
          ],
          "to": 10564
        },
        {
          "dir": "west",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10573
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10575,
      "name": "Administration Hallway",
      "desc": [
        "The hallway is just as extravagant as all the others in this building.",
        "Gem mosaics cover the walls, and intricate patterns are carved in the",
        "gold laden floors. This doesn't look like an admistration building,",
        "more like a palace."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10576
        },
        {
          "dir": "west",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10574
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10576,
      "name": "Administration Hallway",
      "desc": [
        "The hallway is just as extravagant as all the others in this building.",
        "Gem mosaics cover the walls, and intricate patterns are carved in the",
        "gold laden floors. This doesn't look like an admistration building,",
        "more like a palace."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see the end of a long hallway."
          ],
          "keywords": [],
          "to": 10577
        },
        {
          "dir": "south",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10566
        },
        {
          "dir": "west",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10575
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10577,
      "name": "End of Long Hall",
      "desc": [
        "This is the end of a long and lavish hallway. exquisite paintings and",
        "statues line the walls. The ceilings are covered with colorful mosaics."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10567
        },
        {
          "dir": "west",
          "desc": [
            "You see a hallway."
          ],
          "keywords": [],
          "to": 10576
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10578,
      "name": "Gateway to Solace",
      "desc": [
        "This is the gateway to the town of Solace. It keeps the monsters out and",
        "the people in. This is a quiet farming town on the shores of Crytalmir",
        "Lake.",
        "There is a sign nailed to a nearby tree.",
        "There is a plaque embedded in the road.",
        "There is a Gate to the south."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see the Main road in Solace."
          ],
          "keywords": [],
          "to": 10579
        },
        {
          "dir": "east",
          "desc": [
            "You see a small alleyway."
          ],
          "keywords": [],
          "to": 10593
        },
        {
          "dir": "south",
          "desc": [
            "You see the Gateway of Solace."
          ],
          "keywords": [
            "gate"
          ],
          "to": 10003
        },
        {
          "dir": "west",
          "desc": [
            "You see a small alleyway."
          ],
          "keywords": [],
          "to": 10594
        }
      ],
      "extended_descriptions": [
        {
          "keywords": [
            "sign"
          ],
          "desc": [
            "**WELCOME TO SOLACE**",
            "",
            "Welcome to Solace Traveler.",
            "Rest your weary feet and enjoy our small town.",
            "",
            "Please don't feed the animals.",
            "",
            "And please behave yourself.",
            "",
            "Gates will be closed and lock at night to keep the town safe.",
            "",
            "-Captain of the Guard-"
          ]
        },
        {
          "keywords": [
            "plaque"
          ],
          "desc": [
            "*************",
            "Town of Solace",
            "*************",
            "",
            "Brought to you by Strahd"
          ]
        }
      ]
    },
    {
      "id": 10579,
      "name": "Main Road",
      "desc": [
        "This is the main road in Solace. Down the street you can see various",
        "shops and houses."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see the main road of Solace."
          ],
          "keywords": [],
          "to": 10580
        },
        {
          "dir": "east",
          "desc": [
            "You see Jander's Bar & Restaurant."
          ],
          "keywords": [
            "door"
          ],
          "to": 10517
        },
        {
          "dir": "south",
          "desc": [
            "You see the town gateway."
          ],
          "keywords": [],
          "to": 10578
        },
        {
          "dir": "west",
          "desc": [
            "You see a house."
          ],
          "keywords": [
            "door"
          ],
          "to": 10506
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10580,
      "name": "Main Road",
      "desc": [
        "This is the main road in Solace. Down the street you can see various",
        "shops and houses."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see the main road of Solace."
          ],
          "keywords": [],
          "to": 10581
        },
        {
          "dir": "south",
          "desc": [
            "You see the main road of Solace."
          ],
          "keywords": [],
          "to": 10579
        },
        {
          "dir": "west",
          "desc": [
            "You see Cookie's Cookie Cookery."
          ],
          "keywords": [],
          "to": 10505
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10581,
      "name": "Main Road",
      "desc": [
        "This is the main road in Solace. Down the street you can see various",
        "shops and houses."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see the main road of Solace."
          ],
          "keywords": [],
          "to": 10582
        },
        {
          "dir": "south",
          "desc": [
            "You see the main road of Solace."
          ],
          "keywords": [],
          "to": 10580
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10582,
      "name": "Intersection at Main Road.",
      "desc": [
        "Here there is an intersection at the main road.",
        "You see to the east and west, smaller houses and some more shops.",
        "To the road continues to the north."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see the main road of Solace."
          ],
          "keywords": [],
          "to": 10605
        },
        {
          "dir": "east",
          "desc": [
            "You see East Gullen Way"
          ],
          "keywords": [],
          "to": 10583
        },
        {
          "dir": "south",
          "desc": [
            "You see the main road of Solace."
          ],
          "keywords": [],
          "to": 10581
        },
        {
          "dir": "west",
          "desc": [
            "You see West Gullen Way."
          ],
          "keywords": [],
          "to": 10604
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10583,
      "name": "East Gullen Way",
      "desc": [
        "This is the road called East Gullen Way. It is lined with small houses and",
        "shops."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see East Gullen Way."
          ],
          "keywords": [],
          "to": 10584
        },
        {
          "dir": "south",
          "desc": [
            "You see a house."
          ],
          "keywords": [
            "door"
          ],
          "to": 10511
        },
        {
          "dir": "west",
          "desc": [
            "You see the Intersection of Gullen Way and the main road."
          ],
          "keywords": [],
          "to": 10582
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10584,
      "name": "East Gullen Way",
      "desc": [
        "This is the road called East Gullen Way. It is lined with small houses and",
        "shops."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see East Gullen Way."
          ],
          "keywords": [],
          "to": 10585
        },
        {
          "dir": "south",
          "desc": [
            "You see Marilyn's Bird Factory."
          ],
          "keywords": [],
          "to": 10512
        },
        {
          "dir": "west",
          "desc": [
            "You see East Gullen Way."
          ],
          "keywords": [],
          "to": 10583
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10585,
      "name": "East Gullen Way",
      "desc": [
        "This is the road called East Gullen Way. It is lined with small houses and",
        "shops."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see the Corner Of East Gullen and Ketra Road."
          ],
          "keywords": [],
          "to": 10586
        },
        {
          "dir": "west",
          "desc": [
            "You see East Gullen Way."
          ],
          "keywords": [],
          "to": 10584
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10586,
      "name": "Corner of East Gullen and Ketra Road.",
      "desc": [
        "This is the Corner of East Gullen Way and Ketra Road.",
        "Everything is amazingly clean here.",
        "But this doesn't look like the wealthier part of town.",
        "This whole town seems to be one big trading post."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "You see Ketra Road."
          ],
          "keywords": [],
          "to": 10587
        },
        {
          "dir": "west",
          "desc": [
            "You see East Gullen way."
          ],
          "keywords": [],
          "to": 10585
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10587,
      "name": "Ketra Road.",
      "desc": [
        "It is one of the sidestreets of Solace. But even here there are shops.",
        "Most of it is run down houses and shacks.",
        "Even though this looks like the poorer part of town, it is amazingly clean."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see The corner of East Gullen and Ketra."
          ],
          "keywords": [],
          "to": 10586
        },
        {
          "dir": "south",
          "desc": [
            "You see Ketra Road."
          ],
          "keywords": [],
          "to": 10588
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10588,
      "name": "Ketra Road.",
      "desc": [
        "It is one of the sidestreets of Solace. But even here there are shops.",
        "Most of it is run down houses and shacks.",
        "Even though this looks like the poorer part of town, it is amazingly clean."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see Ketra Road."
          ],
          "keywords": [],
          "to": 10587
        },
        {
          "dir": "south",
          "desc": [
            "You see Ketra Road."
          ],
          "keywords": [],
          "to": 10589
        },
        {
          "dir": "west",
          "desc": [
            "You see a Storage Building."
          ],
          "keywords": [
            "door"
          ],
          "to": 10514
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10589,
      "name": "Ketra Road.",
      "desc": [
        "It is one of the sidestreets of Solace. But even here there are shops.",
        "Most of it is run down houses and shacks.",
        "Even though this looks like the poorer part of town, it is amazingly clean."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see Ketra Road."
          ],
          "keywords": [],
          "to": 10588
        },
        {
          "dir": "south",
          "desc": [
            "You see one of the towns watchtowers."
          ],
          "keywords": [],
          "to": 10590
        },
        {
          "dir": "west",
          "desc": [
            "You see Jander's Bar."
          ],
          "keywords": [
            "door"
          ],
          "to": 10515
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10590,
      "name": "Southeast Guardpost and Watchtower.",
      "desc": [
        "This is the Southeast guardpost and guardpost of Solace.",
        "It is used as a watch station and coffee break area for the town guards.",
        "There are some stairs in the corner leading up to the watchtower.",
        "There is a sign above the stairway."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see Ketra Road."
          ],
          "keywords": [],
          "to": 10589
        },
        {
          "dir": "west",
          "desc": [
            "You see a small alleyway."
          ],
          "keywords": [],
          "to": 10591
        },
        {
          "dir": "up",
          "desc": [
            "You see stairs leading up to the watchtower."
          ],
          "keywords": [],
          "to": 10520
        }
      ],
      "extended_descriptions": [
        {
          "keywords": [
            "sign"
          ],
          "desc": [
            "** WARNING **",
            "",
            "This area is RESTRICTED.",
            "",
            "Authorized Personnel Only!",
            "Violators will be jailed or killed.",
            "",
            "-Captain of the Guard-"
          ]
        }
      ]
    },
    {
      "id": 10591,
      "name": "Small Alleyway.",
      "desc": [
        "You are walking down a small alleyway along the north wall of the town."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see the Southeast Guardpost."
          ],
          "keywords": [],
          "to": 10590
        },
        {
          "dir": "west",
          "desc": [
            "You see a small alleyway."
          ],
          "keywords": [],
          "to": 10592
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10592,
      "name": "Small Alleyway.",
      "desc": [
        "You are walking down a small alleyway along the north wall of the town."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a poolhall."
          ],
          "keywords": [
            "door"
          ],
          "to": 10516
        },
        {
          "dir": "east",
          "desc": [
            "You see a small alleyway."
          ],
          "keywords": [],
          "to": 10591
        },
        {
          "dir": "west",
          "desc": [
            "You see a small alleyway."
          ],
          "keywords": [],
          "to": 10593
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10593,
      "name": "Small Alleyway.",
      "desc": [
        "You are walking down a small alleyway along the north wall of the town."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see a small alleyway."
          ],
          "keywords": [],
          "to": 10592
        },
        {
          "dir": "west",
          "desc": [
            "You see the gateway to the town."
          ],
          "keywords": [],
          "to": 10578
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10594,
      "name": "Small Alleyway.",
      "desc": [
        "You are walking down a small alleyway along the north wall of the town."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see the gateway to the town."
          ],
          "keywords": [],
          "to": 10578
        },
        {
          "dir": "west",
          "desc": [
            "You see a small alleyway."
          ],
          "keywords": [],
          "to": 10595
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10595,
      "name": "Small Alleyway.",
      "desc": [
        "You are walking down a small alleyway along the north wall of the town."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see an old boarded up building."
          ],
          "keywords": [
            "door"
          ],
          "to": 10507
        },
        {
          "dir": "east",
          "desc": [
            "You see a small alleyway."
          ],
          "keywords": [],
          "to": 10594
        },
        {
          "dir": "west",
          "desc": [
            "You see a small alleyway."
          ],
          "keywords": [],
          "to": 10596
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10596,
      "name": "Small Alleyway.",
      "desc": [
        "You are walking down a small alleyway along the north wall of the town."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see a small alleyway."
          ],
          "keywords": [],
          "to": 10595
        },
        {
          "dir": "west",
          "desc": [
            "You see the Southwest Guardpost."
          ],
          "keywords": [],
          "to": 10597
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10597,
      "name": "Southwest Guardpost and Watchtower.",
      "desc": [
        "This is the Southwest guardpost and guardpost of Solace.",
        "It is used as a watch station and coffee break area for the town guards.",
        "There are some stairs in the corner leading up to the watchtower.",
        "There is a sign above the stairway."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see Harvest Road."
          ],
          "keywords": [],
          "to": 10598
        },
        {
          "dir": "east",
          "desc": [
            "You see a small alleyway."
          ],
          "keywords": [],
          "to": 10596
        },
        {
          "dir": "up",
          "desc": [
            "You see stairs leading up to the watchtower."
          ],
          "keywords": [],
          "to": 10521
        }
      ],
      "extended_descriptions": [
        {
          "keywords": [
            "sign"
          ],
          "desc": [
            "** WARNING **",
            "",
            "This area is RESTRICTED.",
            "",
            "Authorized Personnel Only!",
            "Violators will be jailed or killed.",
            "",
            "-Captain of the Guard-"
          ]
        }
      ]
    },
    {
      "id": 10598,
      "name": "Harvest Road.",
      "desc": [
        "You are walking down Harvest Road.",
        "It is quiet and peacefull here. The smell of baked goods and other foods",
        "fill the air."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see Harvest Road."
          ],
          "keywords": [],
          "to": 10599
        },
        {
          "dir": "east",
          "desc": [
            "You see the McBakery."
          ],
          "keywords": [],
          "to": 10508
        },
        {
          "dir": "south",
          "desc": [
            "You see the Southwest Guardpost."
          ],
          "keywords": [],
          "to": 10597
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10599,
      "name": "Harvest Road.",
      "desc": [
        "You are walking down Harvest Road.",
        "It is quiet and peacefull here. The smell of baked goods and other foods",
        "fill the air."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see Harvest Road."
          ],
          "keywords": [],
          "to": 10600
        },
        {
          "dir": "east",
          "desc": [
            "You see a house."
          ],
          "keywords": [
            "door"
          ],
          "to": 10509
        },
        {
          "dir": "south",
          "desc": [
            "You see Harvest Road."
          ],
          "keywords": [],
          "to": 10598
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10600,
      "name": "Harvest Road.",
      "desc": [
        "You are walking down Harvest Road.",
        "It is quiet and peacefull here. The smell of baked goods and other foods",
        "fill the air."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see the corner of West Gullen Way and Harvest Road."
          ],
          "keywords": [],
          "to": 10601
        },
        {
          "dir": "south",
          "desc": [
            "You see Harvest Road."
          ],
          "keywords": [],
          "to": 10599
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10601,
      "name": "Corner of West Gullen Way and Harvest Road.",
      "desc": [
        "This is the corner of West Gullen and Harvest road.",
        "To the south you can smell baked goods and other food.",
        "To the east are various small shops and houses."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see West Gullen Way."
          ],
          "keywords": [],
          "to": 10602
        },
        {
          "dir": "south",
          "desc": [
            "You see Harvest Road."
          ],
          "keywords": [],
          "to": 10600
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10602,
      "name": "West Gullen Way",
      "desc": [
        "This is the road called West Gullen Way. It is lined with small houses and",
        "shops."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see West Gullen Way."
          ],
          "keywords": [],
          "to": 10603
        },
        {
          "dir": "south",
          "desc": [
            "You see the entrance to Matt's Brewery."
          ],
          "keywords": [],
          "to": 10502
        },
        {
          "dir": "west",
          "desc": [
            "You see the corner of West Gullen and Harvest."
          ],
          "keywords": [],
          "to": 10601
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10603,
      "name": "West Gullen Way",
      "desc": [
        "This is the road called West Gullen Way. It is lined with small houses and",
        "shops."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see West Gullen Way."
          ],
          "keywords": [],
          "to": 10604
        },
        {
          "dir": "south",
          "desc": [
            "You see a house"
          ],
          "keywords": [
            "door"
          ],
          "to": 10503
        },
        {
          "dir": "west",
          "desc": [
            "You see West Gullen Way."
          ],
          "keywords": [],
          "to": 10602
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10604,
      "name": "West Gullen Way",
      "desc": [
        "This is the road called West Gullen Way. It is lined with small houses and",
        "shops."
      ],
      "doors": [
        {
          "dir": "east",
          "desc": [
            "You see the intersection of West Gullen and the main road."
          ],
          "keywords": [],
          "to": 10582
        },
        {
          "dir": "south",
          "desc": [
            "You see a house."
          ],
          "keywords": [
            "door"
          ],
          "to": 10504
        },
        {
          "dir": "west",
          "desc": [
            "You see West Gullen Way."
          ],
          "keywords": [],
          "to": 10603
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10605,
      "name": "Main Road",
      "desc": [
        "This is the main road in Solace. Down the street you can see various",
        "shops and houses."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see the end of the main road."
          ],
          "keywords": [],
          "to": 10606
        },
        {
          "dir": "south",
          "desc": [
            "You see the intersection of Gullen Way and the main road."
          ],
          "keywords": [],
          "to": 10582
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10606,
      "name": "End of the Main Road",
      "desc": [
        "The main road of Solace stops here. Other smaller roadways lead off",
        "in various directions.",
        "To the west is the marketplace, where farmers go to sell thier harvests.",
        "Farther north you see a large building.",
        "To the East is the Townguard Administration Building."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see a cobblestone path."
          ],
          "keywords": [],
          "to": 10532
        },
        {
          "dir": "east",
          "desc": [
            "You see a dusty road."
          ],
          "keywords": [],
          "to": 10522
        },
        {
          "dir": "south",
          "desc": [
            "You see the Main Road of Solace."
          ],
          "keywords": [],
          "to": 10605
        },
        {
          "dir": "west",
          "desc": [
            "You see the Marketplace."
          ],
          "keywords": [],
          "to": 10607
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10607,
      "name": "Marketplace.",
      "desc": [
        "This is the Marketplace of Solace. Where the farmers come to sell their",
        "crops. The smell of vegetables and fruit fill the air. There are a couple",
        "other vendors selling trinkets and other items.",
        "There is a sign at the entrance to the market."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see Croben's Container Emporium."
          ],
          "keywords": [],
          "to": 10501
        },
        {
          "dir": "east",
          "desc": [
            "You see the End of the Main Road of Solace."
          ],
          "keywords": [],
          "to": 10606
        },
        {
          "dir": "south",
          "desc": [
            "You see Nisi's Frozen Food Store."
          ],
          "keywords": [],
          "to": 10614
        },
        {
          "dir": "west",
          "desc": [
            "You see the Marketplace."
          ],
          "keywords": [],
          "to": 10608
        }
      ],
      "extended_descriptions": [
        {
          "keywords": [
            "sign"
          ],
          "desc": [
            "**NOTICE**",
            "",
            "Stealing will NOT be tolerated.",
            "Any sort of shady actions will be punishable by death.",
            "",
            "",
            "-Captain of the Guard-"
          ]
        }
      ]
    },
    {
      "id": 10608,
      "name": "Marketplace.",
      "desc": [
        "This is the Marketplace of Solace. Where the farmers come to sell their",
        "crops. The smell of vegetables and fruit fill the air. There are a couple",
        "other vendors selling trinkets and other items."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see Lexie's Scuba Shop."
          ],
          "keywords": [],
          "to": 10500
        },
        {
          "dir": "east",
          "desc": [
            "You see the marketplace."
          ],
          "keywords": [],
          "to": 10607
        },
        {
          "dir": "south",
          "desc": [
            "You see Janni's Souvenir Shop."
          ],
          "keywords": [],
          "to": 10613
        },
        {
          "dir": "west",
          "desc": [
            "You see the Marketplace."
          ],
          "keywords": [],
          "to": 10609
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10609,
      "name": "Marketplace.",
      "desc": [
        "This is the Marketplace of Solace. Where the farmers come to sell their",
        "crops. The smell of vegetables and fruit fill the air. There are a couple",
        "other vendors selling trinkets and other items."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see Rashan's Rutabagas Restaurant."
          ],
          "keywords": [],
          "to": 10616
        },
        {
          "dir": "east",
          "desc": [
            "You see the marketplace."
          ],
          "keywords": [],
          "to": 10608
        },
        {
          "dir": "south",
          "desc": [
            "You see Krista's Fruit Stand."
          ],
          "keywords": [],
          "to": 10612
        },
        {
          "dir": "west",
          "desc": [
            "You see the Marketplace."
          ],
          "keywords": [],
          "to": 10610
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10610,
      "name": "Marketplace.",
      "desc": [
        "This is the Marketplace of Solace. Where the farmers come to sell their",
        "crops. The smell of vegetables and fruit fill the air. There are a couple",
        "other vendors selling trinkets and other items.",
        "These are the last stalls in the marketplace. Next to you stands the West wall",
        "of the town."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see Molin's Mulburry Extract Distillery."
          ],
          "keywords": [],
          "to": 10615
        },
        {
          "dir": "east",
          "desc": [
            "You see the marketplace."
          ],
          "keywords": [],
          "to": 10609
        },
        {
          "dir": "south",
          "desc": [
            "You see Jhen's Vegtable Cart."
          ],
          "keywords": [],
          "to": 10611
        }
      ],
      "extended_descriptions": []
    },
    {
      "id": 10611,
      "name": "Jhen's Vegetable Cart.",
      "desc": [
        "This is where Jhen the farmer comes to sell his crops. His wooden vegtable",
        "cart stands here filled with all sorts of vegetables. All his vegtables are",
        "unusually large. What kind of plant food does he use anyway...?",
        "There is a small sign nailed to the cart."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see the marketplace."
          ],
          "keywords": [],
          "to": 10610
        }
      ],
      "extended_descriptions": [
        {
          "keywords": [
            "sign"
          ],
          "desc": [
            "The sign reads:",
            "",
            "  List  - Show which various items are in the store.",
            "  Buy   - Buy an item.",
            "  Value - The shopkeeper will (free of charge) tell how much he will",
            "          pay for your item.",
            "  Sell  - Sell an item."
          ]
        }
      ]
    },
    {
      "id": 10612,
      "name": "Krista's Fruit Stand.",
      "desc": [
        "This is where Krista peddles her fruits. Every year she travels from her",
        "orchards in the mountains to Solace to sell her fruit. Everything seems",
        "to have an unusually small size. I wonder if she shrinks heads too...",
        "There is a small sign hanging above the fruit stand."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see the marketplace."
          ],
          "keywords": [],
          "to": 10609
        }
      ],
      "extended_descriptions": [
        {
          "keywords": [
            "sign"
          ],
          "desc": [
            "The sign reads:",
            "",
            "  List  - Show which various items are in the store.",
            "  Buy   - Buy an item.",
            "  Value - The shopkeeper will (free of charge) tell how much he will",
            "          pay for your item.",
            "  Sell  - Sell an item."
          ]
        }
      ]
    },
    {
      "id": 10613,
      "name": "Janni's Souvenirs.",
      "desc": [
        "This is Janni's Souvenir shop. He makes trinkets year round that he peddles",
        "here in the market. You wouldn't want to leave Solace without a souvenir",
        "would you?",
        "there is a sign behind the glass case."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see the marketplace."
          ],
          "keywords": [],
          "to": 10608
        }
      ],
      "extended_descriptions": [
        {
          "keywords": [
            "sign"
          ],
          "desc": [
            "The sign reads:",
            "",
            "  List  - Show which various items are in the store.",
            "  Buy   - Buy an item.",
            "  Value - The shopkeeper will (free of charge) tell how much he will",
            "          pay for your item.",
            "  Sell  - Sell an item."
          ]
        }
      ]
    },
    {
      "id": 10614,
      "name": "Nisi's Frozen Food",
      "desc": [
        "This is one of the oddest venders in the marketplace. Nisi claims to have",
        "various fresh frozen types of vegetables. They are frozen all right. In",
        "fact they are hard enough to stop an axe swing...go figure..",
        "And just how does she keep them from melting...",
        "There is a small sign on the wall in the back of the shop."
      ],
      "doors": [
        {
          "dir": "north",
          "desc": [
            "You see the marketplace."
          ],
          "keywords": [],
          "to": 10607
        }
      ],
      "extended_descriptions": [
        {
          "keywords": [
            "sign"
          ],
          "desc": [
            "The sign reads:",
            "",
            "  List  - Show which various items are in the store.",
            "  Buy   - Buy an item.",
            "  Value - The shopkeeper will (free of charge) tell how much he will",
            "          pay for your item.",
            "  Sell  - Sell an item."
          ]
        }
      ]
    },
    {
      "id": 10615,
      "name": "Molin's Mulburry Extracts.",
      "desc": [
        "This is the shop of the famous mulburry extract. Known throughout the",
        "valley to quech the thirst of even the thirstiest traveller. What else it does",
        "is just rumor. That person recovered in a month anyway...",
        "There is a small sign on the wall."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "You see the marketplace."
          ],
          "keywords": [],
          "to": 10610
        }
      ],
      "extended_descriptions": [
        {
          "keywords": [
            "sign"
          ],
          "desc": [
            "The sign reads:",
            "",
            "  List  - Show which various items are in the store.",
            "  Buy   - Buy an item.",
            "  Value - The shopkeeper will (free of charge) tell how much he will",
            "          pay for your item.",
            "  Sell  - Sell an item."
          ]
        }
      ]
    },
    {
      "id": 10616,
      "name": "Rashan's Rutabagas",
      "desc": [
        "This is one shop to stay away from. Rashan's rutabagas have been know",
        "to do strange things to people. And true to its reputation the shop is",
        "very very empty. I'm sure Rashan would be more than willing to sell",
        "you one. Business obviously has been very slow....",
        "There is a small sign hanging next to you."
      ],
      "doors": [
        {
          "dir": "south",
          "desc": [
            "You see the marketplace."
          ],
          "keywords": [],
          "to": 10609
        }
      ],
      "extended_descriptions": [
        {
          "keywords": [
            "sign"
          ],
          "desc": [
            "The sign reads:",
            "",
            "  List  - Show which various items are in the store.",
            "  Buy   - Buy an item.",
            "  Value - The shopkeeper will (free of charge) tell how much he will",
            "          pay for your item.",
            "  Sell  - Sell an item."
          ]
        }
      ]
    }
  ]
})"_json;
return j;
}

std::string WorldContainer::getAreaName(const int id) {
  return this->_area.getName(); // currently only has one area
}
