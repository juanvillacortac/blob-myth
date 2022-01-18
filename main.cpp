/*The Myth of Blob - A simple terminal RPG.
Copyright (C) 2018  Juan Villacorta

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

    ______)          __     __)
   (, /  /)         (, /|  /|          /)
     /  (/    _       / | / |      _/_(/
  ) /   / )__(/_   ) /  |/  |_ (_/_(__/ )_
 (_/              (_/   '     .-/
                             (_/

                       /)    ·Programmed by:
                   ___//
                  (_)/(_    Juan Villacorta.
                    /)
                  (/
             ______
            (, /    ) /)    /)
              /---(  // ___(/_
           ) / ____)(/_(_)/_)
          (_/ (
*/

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

// Clears the screen
void clear() { cout << string(80, '\n'); }

// Draw the ascii art
void draw(string type) {
  if (type == "Lion") {
    cout << R"(
======================================================================
                                                ,w.
                                              ,YWMMw  ,M  ,
                         _.---.._   __..---._.'MMMMMw,wMWmW,
                    _.-""        """           YP"WMMMMMMMMMb,
                 .-' __.'                   .'     MMMMW^WMMMM;
     _,        .'.-'"; `,       /`     .--""      :MMM[==MWMW^;
  ,mM^"     ,-'.'   /   ;      ;      /   ,       MMMMb_wMW"  @\
 ,MM:.    .'.-'   .'     ;     `\    ;     `,     MMMMMMMW `"=./`-,
 WMMm__,-'.'     /      _.\      F"""-+,,   ;_,_.dMMMMMMMM[,_ / `=_}
 "^MP__.-'    ,-' _.--""   `-,   ;       \  ; ;MMMMMMMMMMW^``; __|
            /   .'            ; ;         )  )`{  \ `"^W^`,   \  :
           /  .'             /  (       .'  /     Ww._     `.  `"
          /  Y,              `,  `-,=,_{   ;      MMMP`""-,  `-._.-,
         (--, )                `,_ / `) \/"")      ^"      `-, -;"\:
          `"""                    `"""   `"'                  `---" 
======================================================================
        )"
         << endl;
  } else if (type == "Boar") {
    cout << R"(
============================================
              _,-""""-..__
         |`,-'_. `  ` ``  `--'""".
         ;  ,'  | ``  ` `  ` ```  `.
       ,-'   ..-' ` ` `` `  `` `  ` |==.
     ,'    ^    `  `    `` `  ` `.  ;   \
    `}_,-^-   _ .  ` \ `  ` __ `   ;    #
       `"---"' `-`. ` \---""`.`.  `;
                  \\` ;       ; `. `,
                   ||`;      / / | |
                  //_;`    ,_;' ,_;"
============================================
        )"
         << endl;
  } else if (type == "Spider") {
    cout << R"(
================================
        /\  .-"""-.  /\
       //\\/  ,,,  \//\\
       |/\| ,;;;;;, |/\|
       //\\\;-"""-;///\\
      //  \/   .   \/  \\
     (| ,-_| \ | / |_-, |)
       //`__\.-.-./__`\\
      // /.-(() ())-.\ \\
     (\ |)   '---'   (| /)
      ` (|           |) `
        \)           (/
================================
        )"
         << endl;
  } else if (type == "Wolf") {
    cout << R"(
=====================================
                          ,     ,
                          |\---/|
                         /  , , |
                    __.-'|  / \ /
           __ ___.-'        ._O|
        .-'  '        :      _/
       / ,    .        .     |
      :  ;    :        :   _/
      |  |   .'     __:   /
      |  :   /'----'| \  |
      \  |\  |      | /| |
       '.'| /       || \ |
       | /|.'       '.l \\_
       || ||             '-'
       '-''-'
=====================================
        )"
         << endl;
  } else if (type == "Elephant") {
    cout << R"(
=====================================================
              ___.-~"~-._   __....__
            .'    `    \ ~"~        ``-.
           /` _      )  `\              `\
          /`  a)    /     |               `\
         :`        /      |                 \
    <`-._|`  .-.  (      /   .            `;\\
     `-. `--'_.'-.;\___/'   .      .       | \\
  _     /:--`     |        /     /        .'  \\
 ("\   /`/        |       '     '         /    :`;
 `\'\_/`/         .\     /`~`=-.:        /     ``
   `._.'          /`\    |      `\      /(
                 /  /\   |        `Y   /  \
                J  /  Y  |         |  /`\  \
               /  |   |  |         |  |  |  |
              "---"  /___|        /___|  /__|
=====================================================
        )"
         << endl;
  } else if (type == "Slime") {
    cout << R"(
==================================
         , - ~ ~ ~ - ,
     , '               ' ,
   ,    !           !      ,
  ,                         ,
 ,              `@@    `@@   ,
 , !             @@     @@   ,
 ,        !                  ,
  ,                         ,
   ,                    !  ,
     ,       !          , '
       ' - , _ _ _ ,  '
==================================
        )"
         << endl;
  }
}

// Displays the abilities
pair<string, int> getability(string pclass, int mana, int inte, int level) {
  string input;
  string ability;
  int cost;
  cout << "Choose an ability" << endl;
  if (pclass == "Champion") { // Champion Section
    cost = inte * (level);
    cout << "[1]  Cleaving Strike [" << cost << " mana]" << endl;
    cout << "[2]  Melting Thrust [" << cost << " mana]" << endl;
    cout << "[3]  Critical Bash [" << cost << " mana]" << endl;
    cost = inte * (level + 1);
    cout << "[4]  Purify [" << cost << " mana]" << endl;
    cout << "[99] Go back" << endl;
    cost = inte * (level);
    cin >> input;
    if (input == "1") {
      ability = "cleaving strike";
      if (mana >= cost) {
        mana = mana - cost;
        return {ability, mana};
      } else {
        ability = "none";
        return {ability, mana};
      }
    } else if (input == "2") {
      ability = "melting thrust";
      if (mana >= cost) {
        mana = mana - cost;
        return {ability, mana};
      } else {
        ability = "none";
        return {ability, mana};
      }
    } else if (input == "3") {
      ability = "critical bash";
      if (mana >= cost) {
        mana = mana - cost;
        return {ability, mana};
      } else {
        ability = "none";
        return {ability, mana};
      }
    } else if (input == "4") {
      ability = "purify";
      if (mana >= cost) {
        cost = inte * (level + 1);
        mana = mana - cost;
        return {ability, mana};
      } else {
        ability = "none";
        return {ability, mana};
      }
    } else {
      ability = "none";
      return {ability, mana};
    }
  } else if (pclass == "Necromancer") { // Necromancer Section
    cost = inte * (level);
    cout << "[1]  Shadow Strike [" << cost << " mana]" << endl;
    cout << "[2]  Cripple [" << cost << " mana]" << endl;
    cout << "[3]  Mutilate [" << cost << " mana]" << endl;
    cost = inte * (level + 2);
    cout << "[4]  Life Tap [" << cost << " mana]" << endl;
    cout << "[99] Go back" << endl;
    cost = inte * (level);
    cin >> input;
    if (input == "1") {
      ability = "shadow strike";
      if (mana >= cost) {
        mana = mana - cost;
        return {ability, mana};
      } else {
        ability = "none";
        return {ability, mana};
      }
    } else if (input == "2") {
      ability = "cripple";
      if (mana >= cost) {
        mana = mana - cost;
        return {ability, mana};
      } else {
        ability = "none";
        return {ability, mana};
      }
    } else if (input == "3") {
      ability = "mutilate";
      if (mana >= cost) {
        mana = mana - cost;
        return {ability, mana};
      } else {
        ability = "none";
        return {ability, mana};
      }
    } else if (input == "4") {
      ability = "life tap";
      if (mana >= cost) {
        cost = inte * (level + 2);
        mana = mana - cost;
        return {ability, mana};
      } else {
        ability = "none";
        return {ability, mana};
      }
    } else {
      ability = "none";
      return {ability, mana};
    }
  } else if (pclass == "Assassin") { // Assassin Section
    cost = inte * (level);
    cout << "[1]  Back Stab [" << cost << " mana]" << endl;
    cout << "[2]  Headcrack [" << cost << " mana]" << endl;
    cout << "[3]  Poison [" << cost << " mana]" << endl;
    cost = inte * 10;
    cout << "[4]  Assassinate [" << cost << " mana]" << endl;
    cout << "[99] Go back" << endl;
    cost = inte * (level);
    cin >> input;
    if (input == "1") {
      ability = "back stab";
      if (mana >= cost) {
        mana = mana - cost;
        return {ability, mana};
      } else {
        ability = "none";
        return {ability, mana};
      }
    } else if (input == "2") {
      ability = "headcrack";
      if (mana >= cost) {
        mana = mana - cost;
        return {ability, mana};
      } else {
        ability = "none";
        return {ability, mana};
      }
    } else if (input == "3") {
      ability = "poison";
      if (mana >= cost) {
        mana = mana - cost;
        return {ability, mana};
      } else {
        ability = "none";
        return {ability, mana};
      }
    } else if (input == "4") {
      ability = "assassinate";
      if (mana >= cost) {
        cost = inte * 10;
        mana = mana - cost;
        return {ability, mana};
      } else {
        ability = "none";
        return {ability, mana};
      }
    } else {
      ability = "none";
      return {ability, mana};
    }
  } else if (pclass == "Cleric") { // Cleric Section
    cost = inte * (level);
    cout << "[1]  Smite [" << cost << " mana]" << endl;
    cout << "[2]  Enflame [" << cost << " mana]" << endl;
    cout << "[3]  Atonement [" << cost << " mana]" << endl;
    cout << "[4]  Flash Heal [" << cost << " mana]" << endl;
    cout << "[99] Go back" << endl;
    cin >> input;
    if (input == "1") {
      ability = "smite";
      if (mana >= cost) {
        mana = mana - cost;
        return {ability, mana};
      } else {
        ability = "none";
        return {ability, mana};
      }
    } else if (input == "2") {
      ability = "enflame";
      if (mana >= cost) {
        mana = mana - cost;
        return {ability, mana};
      } else {
        ability = "none";
        return {ability, mana};
      }
    } else if (input == "3") {
      ability = "atonement";
      if (mana >= cost) {
        mana = mana - cost;
        return {ability, mana};
      } else {
        ability = "none";
        return {ability, mana};
      }
    } else if (input == "4") {
      ability = "flash heal";
      if (mana >= cost) {
        mana = mana - cost;
        return {ability, mana};
      } else {
        ability = "none";
        return {ability, mana};
      }
    } else {
      ability = "none";
      return {ability, mana};
    }
  } else {
    ability = "none";
    return {ability, mana};
  }
}

int main() {

  srand((unsigned)time(0));

  // Strings
  string code;   // Game save code
  string name;   // Player name
  string etype;  // Enemy Type (spider, giant)
  string pclass; // Player class
  string action; // Player ability / action
  // Dungeons
  string status = "arena"; // Status if in Dungeon or just Arena
  int ckills;              // Current amount of kills in Dungeon
  int rkills;              // Required amount of kills to complete a Dungeon
  // Armor / Weapons
  int bhp = 0;             // Bonus hp
  double bphp = 0;         // Bonus precantage hp
  double goldb = 0;        // Bonus Gold
  int slimychestplate = 0; // Slimy Chestplate (TRUE or FALSE)
  int slimyhelmet = 0;     // Slimy Helmet (TRUE or FALSE)
  int bloblegplates = 0;   // Blob Legplates
  int blobboots = 0;       // Blob Boots
  string head = "Open";    // Whats on the head
  string chest = "Open";   // Whats on the chest
  string legs = "Open";    // Whats on the legs
  string feet = "Open";    // Whats on the feet
  // Player Variables
  int piclass = 0;
  int level = 1; // Level
  int xp = 0;    // Current XP
  int rxp;       // Reward XP
  int xpb = 50;  // Increases each level, adds to max hp to increase it
  int xpl = 25;  // XP Required till next level
  int stre = 5;  // Strength
  int inte = 5;  // Intelligence
  int dext = 5;  // Dexterity
  int skill = 0; // Skillpoint points (used to increase Strength, Intelligence,
                 // Dexterity)
  int dmg;       // Damage
  int hp = stre * 20;    // Current hp
  int mhp = stre * 20;   // Max hp
  int shp = stre * 20;   // hp used to set enemy hp
  int mana = inte * 10;  // Mana
  int mmana = inte * 10; // Max Mana
  // Inventory / Shop
  int hpotion = 1; // Healing Potions
  int price;       // Price of item(s)
  // Resources
  int gold = 25; // Gold
  int rgold;     // Reward Gold
  // Saving / Loading Strings
  int x = 0;
  int y = 0;
  string sslimychestplate = std::to_string(slimychestplate);
  string sslimyhelmet = std::to_string(slimyhelmet);
  string sbloblegplates = std::to_string(bloblegplates);
  string sblobboots = std::to_string(blobboots);
  string spiclass = std::to_string(piclass);
  string slevel = std::to_string(level);
  string sxp = std::to_string(xp);
  string sxpb = std::to_string(xpb);
  string sxpl = std::to_string(xpl);
  string sstre = std::to_string(stre);
  string sinte = std::to_string(inte);
  string sdext = std::to_string(dext);
  string shpotion = std::to_string(hpotion);
  string sgold = std::to_string(gold);
  string sskill = std::to_string(skill);
  // Questhall
  int quest = 0;  // The quest
  int questr = 0; // The quest requirements (6 boars slain)
  int questc = 0; // The current position on the requirements (3/6 boars slain)
  int questreward = 0; // The quest's reward
  string questmob;     // Enemy that must be slain to complete the quest
  string questdisplay; // Displays the quest
  int qxpr;            // Quest xp reward
  int qgoldr;          // Quest gold reward
  // Monster Variables
  int elevel;      // Enemy level
  int ehp;         // Enemy hp
  int mehp;        // Max Enemy hp
  int edmg;        // Enemy dmg
  string eability; // Enemy Ability
  // Other Variables
  int random;  // Random Integer #1
  int random2; // Random Integer #2
  // Weapons
  // Inputs
  string input; // Standard Input

  // Setup
neworload:
  clear();
  cout << R"(
    ______)          __     __)
   (, /  /)         (, /|  /|          /)
     /  (/    _       / | / |      _/_(/
  ) /   / )__(/_   ) /  |/  |_ (_/_(__/ )_
 (_/              (_/   '     .-/
                             (_/

                       /)    ·Programmed by:
                   ___//
                  (_)/(_    Juan Villacorta.
                    /)
                  (/
             ______
            (, /    ) /)    /)
              /---(  // ___(/_
           ) / ____)(/_(_)/_)            
          (_/ (

============================================
	)"
       << endl;
  cout << "Please choose, an option:" << endl;
  cout << "1- New Game" << endl;
  cout << "2- Load Game" << endl;
  cin >> input;
  if (input == "1") {
    goto setup;
  } else if (input == "2") {
    goto loadgame;
  } else {
    goto neworload;
  }

setup:
  clear();
  cout << "Hello there, what is your name?" << endl;
  cin >> input;
  name = input;
  clear();
  cout << "Ahh, is it " << input << "? [y/n]" << endl;
  cin >> input;
  if (input == "n") {
    clear();
    goto setup;
  }

  // Class Setup
csetup:
  clear();
  cout << "Choose your Class" << endl;
  cout << "=================" << endl;
  cout << "[1] Champion" << endl;
  cout << "[2] Necromancer" << endl;
  cout << "[3] Assassin" << endl;
  cout << "[4] Cleric" << endl;
  cin >> input;

  if (input == "1") {
    pclass = "Champion";
    piclass = 1;
  } else if (input == "2") {
    pclass = "Necromancer";
    piclass = 2;
  } else if (input == "3") {
    pclass = "Assassin";
    piclass = 3;
  } else if (input == "4") {
    pclass = "Cleric";
    piclass = 4;
  }

  goto menue;

  // Main Menue
menue:
  clear();

  if (pclass == "Assassin") {
    goldb = 1.25;
  } else {
    goldb = 1;
  }

  cout << R"(
       __, _,____,_,  _,_, _,
 ____,(-|\/|(-|_,(-|\ |(-|  \ ____, 
(      _| _|,_|__,_| \|,_|__/(
      (     (    (     (
    )" << endl;

  cout << pclass << " " << name << endl;
  cout << "[1]  Traveller's Encounter" << endl;
  cout << "[2]  Inventory" << endl;
  cout << "[3]  Rest (Returns you to full health/mana)" << endl;
  cout << "[4]  Assign Skillpoints [" << skill << " available]" << endl;
  cout << "[5]  Shop" << endl;
  cout << "[6]  Quest hall" << endl;
  cout << "[7]  Dungeons" << endl;
  cout << "[98] Save Game" << endl;
  cout << "[99] Exit" << endl;
  cin >> input;
  if (input == "1") {
    goto sarena;
  } else if (input == "99") {
    goto leave;
  } else if (input == "2") {
    goto inventory;
  } else if (input == "3") {
    mhp = stre * 20;
    mmana = inte * 10;
    hp = mhp;
    hp = hp * (bphp + 1);
    hp = hp + bhp;
    mana = mmana;
    goto menue;
  } else if (input == "4") {
    goto askill;
  } else if (input == "5") {
    goto shop;
  } else if (input == "6") {
    goto questhall;
  } else if (input == "7") {
    goto dungeonmenue;
  } else if (input == "98") {
    goto savegame;
  }

  goto menue;

  // Setting Up Enemys
sarena:

  mmana = inte * 10;
  shp = stre * 20;
  mhp = stre * 20;
  random = rand() % 5 + 1;
  switch (random) {
  case 1:
    etype = "Lion";
    random2 = rand() % 2 + 1;
    eability = "gnaw";
    if (random2 == 1) {
      ehp = shp + rand() % (level * 5);
    } else {
      ehp = shp - rand() % (level * 5);
    }
    mehp = ehp;
    break;

  case 2:
    etype = "Boar";
    random2 = rand() % 2 + 1;
    eability = "goar";
    if (random2 == 1) {
      ehp = shp + rand() % (level * 3);
    } else {
      ehp = shp - rand() % (level * 3);
    }
    mehp = ehp;
    break;

  case 3:
    etype = "Spider";
    random2 = rand() % 2 + 1;
    eability = "webspin";
    elevel = rand() % (level + 3) + 1;
    if (random2 == 1) {
      ehp = shp + rand() % (level * 2);
    } else {
      ehp = shp - rand() % (level * 2);
    }
    mehp = ehp;
    break;

  case 4:
    etype = "Wolf";
    random2 = rand() % 2 + 1;
    eability = "growl";
    elevel = rand() % (level + 3) + 1;
    if (random2 == 1) {
      ehp = shp + rand() % (level * 4);
    } else {
      ehp = shp - rand() % (level * 4);
    }
    mehp = ehp;
    break;

  case 5:
    etype = "Elephant";
    random2 = rand() % 2 + 1;
    eability = "stomp";
    if (random2 == 1) {
      ehp = shp + rand() % (level * 6);
    } else {
      ehp = shp - rand() % (level * 3);
    }
    mehp = ehp;
    break;
  }

  elevel = rand() % (level + 3) + 1;
  if ((elevel < (level - 3)) || (elevel > (level + 3))) {
    elevel = level;
  }

  goto aarena;

  // Arena Main
aarena:

  clear();
  draw(etype);
  cout << "[" << etype << " lvl " << elevel << "] >>> " << ehp << "/" << mehp
       << endl;
  cout << "[" << name << " lvl " << level << "] >>> " << hp << "/" << mhp
       << endl;
  cout << "-Mana- >>> " << mana << "/" << mmana << endl;
  cout << "[1]  Attack" << endl;
  cout << "[2]  Do ability" << endl;
  cout << "[3]  Inventory" << endl;
  cout << "[99] Flee" << endl;
  cin >> input;

  if (input == "1") {
    dmg = (stre + inte) + rand() % (dext * 2);
    ehp = ehp - dmg;
    // If enemy ehp < 0 then
    if (ehp <= 0) {
      clear();
      cout << R"(
 __  _,__, ____,____,____, ____, _  _,
(-\  /(-| (-/  (-|  (-/  \(-|__)(-\_/
  _\/  _|_,_\__,_|,  _\__/,_|  \, _|,
 (    (   (    (    (     (      (
			)"
           << endl;
      cout << "[*] You killed the " << etype << endl;
      cout << "Type [1] to continue" << endl;
      cin >> input;
      goto rarena;
    }
    random2 = rand() % 2 + 1;
    edmg = dmg;
    // Setting up enemy damage
    if (random2 == 1) {
      edmg = edmg + rand() % (dext * 2);
    } else {
      edmg = edmg - rand() % (dext * 2);
    }
    hp = hp - edmg;
    // If player hp < 0 then
    if (hp <= 0) {
      clear();
      cout << R"(
▓██   ██▓ ▒█████   █    ██    ▓█████▄  ██▓▓█████ ▓█████▄ 
 ▒██  ██▒▒██▒  ██▒ ██  ▓██▒   ▒██▀ ██▌▓██▒▓█   ▀ ▒██▀ ██▌
  ▒██ ██░▒██░  ██▒▓██  ▒██░   ░██   █▌▒██▒▒███   ░██   █▌
  ░ ▐██▓░▒██   ██░▓▓█  ░██░   ░▓█▄   ▌░██░▒▓█  ▄ ░▓█▄   ▌
  ░ ██▒▓░░ ████▓▒░▒▒█████▓    ░▒████▓ ░██░░▒████▒░▒████▓ 
   ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒     ▒▒▓  ▒ ░▓  ░░ ▒░ ░ ▒▒▓  ▒ 
 ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░     ░ ▒  ▒  ▒ ░ ░ ░  ░ ░ ▒  ▒ 
 ▒ ▒ ░░  ░ ░ ░ ▒   ░░░ ░ ░     ░ ░  ░  ▒ ░   ░    ░ ░  ░ 
 ░ ░         ░ ░     ░           ░     ░     ░  ░   ░    
 ░ ░                           ░                  ░      

[*]You're not the chosen one, wanderer...
			)"
           << endl;
      // cout << "Type [1] to continue" << endl;
      // cin >> input;
      if (status != "arena") {
        status = "arena";
      }
      // goto menue;
      exit(0);
    }
    goto aarena;
  } else if (input == "99") {
    goto menue;
  } else if (input == "2") {
    goto darena;
  } else if (input == "3") {
    goto iarena;
  } else {
    goto aarena;
  }

  // Using items from Inventory
iarena:
  clear();

  cout << "Inventory" << endl;
  cout << "[1]  Health Potion, " << hpotion << " (Heals you to max health)"
       << endl;
  cout << "[99] Exit" << endl;
  cin >> input;
  if (input == "1") {
    if (hpotion > 0) {
      hpotion = hpotion - 1;
      hp = mhp;
    }
  } else if (input == "99") {
    goto aarena;
  }
  goto iarena;

  // Picking spells and doing damage
darena:

  clear();
  tie(action, mana) = getability(pclass, mana, inte, level);
  // Champion spells
  if (action == "cleaving strike") {
    dmg = (stre + inte + dext) + rand() % (dext * 2);
  } else if (action == "melting thrust") {
    dmg = (stre + inte + dext) + rand() % (stre * 2);
  } else if (action == "critical bash") {
    dmg = (stre + inte + dext) + rand() % (inte * 2);
  } else if (action == "purify") {
    hp = hp + inte * (level) + (rand() % inte);
    if (hp > mhp) {
      hp = mhp;
    }
    goto aarena;
  } else if (action == "none") {
    goto aarena;
  } else if (action == "shadow strike") {
    dmg = (stre + inte + dext) + rand() % (dext * 2);
  } else if (action == "cripple") {
    dmg = (stre + inte + dext) + rand() % (stre * 2);
  } else if (action == "mutilate") {
    dmg = (stre + inte + dext) + rand() % (inte * 2);
  } else if (action == "life tap") {
    dmg = (stre + inte) + rand() % (inte);
    hp = hp + dmg;
    if (hp > mhp) {
      hp = mhp;
    }
    ehp = ehp - dmg;
    // If enemy ehp < 0 then
    if (ehp <= 0) {
      clear();
      cout << "[*] You killed the " << etype << endl;
      cout << "Type [1] to continue" << endl;
      cin >> input;
      goto rarena;
    }
    goto aarena;
  } else if (action == "back stab") {
    dmg = (stre + inte + dext) + rand() % (dext * 2);
  } else if (action == "headcrack") {
    dmg = (stre + inte + dext) + rand() % (stre * 2);
  } else if (action == "poison") {
    dmg = (stre + inte + dext) + rand() % (inte * 2);
  } else if (action == "assassinate") {
    dmg = (stre + inte + dext) + rand() % ((inte + stre) * 3);
    ehp = ehp - dmg;
    // If enemy ehp < 0 then
    if (ehp <= 0) {
      clear();
      cout << "[*] You killed the " << etype << endl;
      cout << "Type [1] to continue" << endl;
      cin >> input;
      goto rarena;
    }
    goto aarena;
  } else if (action == "smite") {
    dmg = (stre + inte + dext) + rand() % (dext);
  } else if (action == "enflame") {
    dmg = (stre + inte + dext) + rand() % (stre);
  } else if (action == "atonement") {
    dmg = (stre + inte + dext) + rand() % (inte);
  } else if (action == "flash heal") {
    hp = hp + ((stre * level) + (rand() % (inte * 2)));
    if (hp > mhp) {
      hp = mhp;
    }
    goto aarena;
  }

  // Doing the damage (Enemy)
  ehp = ehp - dmg;
  // If enemy ehp < 0 then
  if (ehp <= 0) {
    clear();
    cout << "[*] You killed the " << etype << endl;
    cout << "Type [1] to continue" << endl;
    cin >> input;
    goto rarena;
  }
  random2 = rand() % 2 + 1;
  dmg = (stre + inte) + rand() % (dext * 2);
  edmg = dmg;
  // Setting up enemy damage
  if (random2 == 1) {
    edmg = edmg + rand() % (dext * 2);
  } else {
    edmg = edmg - rand() % (dext * 2);
  }
  hp = hp - edmg;
  // If player hp < 0 then
  if (hp <= 0) {
    clear();
    cout << R"(
▓██   ██▓ ▒█████   █    ██    ▓█████▄  ██▓▓█████ ▓█████▄ 
 ▒██  ██▒▒██▒  ██▒ ██  ▓██▒   ▒██▀ ██▌▓██▒▓█   ▀ ▒██▀ ██▌
  ▒██ ██░▒██░  ██▒▓██  ▒██░   ░██   █▌▒██▒▒███   ░██   █▌
  ░ ▐██▓░▒██   ██░▓▓█  ░██░   ░▓█▄   ▌░██░▒▓█  ▄ ░▓█▄   ▌
  ░ ██▒▓░░ ████▓▒░▒▒█████▓    ░▒████▓ ░██░░▒████▒░▒████▓ 
   ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒     ▒▒▓  ▒ ░▓  ░░ ▒░ ░ ▒▒▓  ▒ 
 ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░     ░ ▒  ▒  ▒ ░ ░ ░  ░ ░ ▒  ▒ 
 ▒ ▒ ░░  ░ ░ ░ ▒   ░░░ ░ ░     ░ ░  ░  ▒ ░   ░    ░ ░  ░ 
 ░ ░         ░ ░     ░           ░     ░     ░  ░   ░    
 ░ ░                           ░                  ░      

[*]You're not the chosen one, wanderer...
			)"
         << endl;
    // cout << "Type [1] to continue" << endl;
    // cin >> input;
    if (status != "arena") {
      status = "arena";
    }
    // goto menue;
    exit(0);
  }
  goto aarena;

  // Here you get arena awards
rarena:
  clear();
  rxp = rand() % (level * 2) + 5;
  rgold = rand() % (level * 5);
  rgold = rgold * goldb;

  cout << R"(
*******************************************************************************
          |                   |                  |                     |       
 _________|________________.=""_;=.______________|_____________________|_______
|                   |  ,-"_,=""     `"=.|                  |                   
|___________________|__"=._o`"-._        `"=.______________|___________________
          |                `"=._o`"=._      _`"=._                     |       
 _________|_____________________:=._o "=._."_.-="'"=.__________________|_______
|                   |    __.--" , ; `"=._o." ,-"""-._ ".   |                   
|___________________|_._"  ,. .` ` `` ,  `"-._"-._   ". '__|___________________
          |           |o`"=._` , "` `; .". ,  "-._"-._; ;              |       
 _________|___________| ;`-.o`"=._; ." ` '`."\` . "-._ /_______________|_______
|                   | |o;    `"-.o`"=._``  '` " ,__.--o;   |                   
|___________________|_| ;     (#) `-.o `"=.`_.--"_o.-; ;___|___________________
____/______/______/___|o;._    "      `".o|o_.--"    ;o;____/______/______/____
/______/______/______/_"=._o--._        ; | ;        ; ;/______/______/______/_
____/______/______/______/__"=._o--._   ;o|o;     _._;o;____/______/______/____
/______/______/______/______/____"=._o._; | ;_.--"o.--"_/______/______/______/_
____/______/______/______/______/_____"=.o|o_.--""___/______/______/______/____
/______/______/______/______/______/______/______/______/______/______/______/_
*******************************************************************************
    )" << endl; // That chest looks amazing

  if (status == "slimedung") {
    goto slimedungr;
  } else {
    goto rrarena;
  }

rrarena:
  cout << "You recieved " << rxp << " xp" << endl;
  cout << "You recieved " << rgold << " gold" << endl;
  xp = xp + rxp;
  gold = gold + rgold;
  if (xp >= xpl) {
    level = level + 1;
    xpl = xpl + xpb;
    xpb = xpb + 50;
    skill = skill + 5;
    cout << "You have leveled up to level " << level << endl;
  }
  cout << "Type [1] to continue to the menue" << endl;

  if (etype == questmob) {
    questc = questc + 1;
  }

  cin >> input;
  goto menue;

  // Inventory
inventory:
  clear();

  cout << R"(
       ___
       )_(                                            _
       | |                                           [_ ]
     .-'-'-.       _                               .-'. '-.
    /-::_..-\    _[_]_                            /:;/ _.-'\
    )_     _(   /_   _\      [-]                  |:._   .-|
    |;::    |   )_``'_(    .-'-'-.       (-)      |:._     |
    |;::    |   |;:   |    :-...-:     .-'-'-.    |:._     |
    |;::    |   |;:   |    |;:   |     |-...-|    |:._     |
    |;::-.._|   |;:.._|    |;:.._|     |;:.._|    |:._     |
    `-.._..-'   `-...-'    `-...-'     `-...-'    `-.____.-'    
    )" << endl;

levelalert:
  if (xp >= xpl) {
    level = level + 1;
    xpl = xpl + xpb;
    xpb = xpb + 50;
    skill = skill + 5;
    goto levelalert;
  } else {
    goto inventory2;
  }

inventory2:
  cout << "[Level] >>> " << level << endl;
  cout << "[XP] >>> " << xp << "/" << xpl << endl;
  cout << "[Gold] >>> " << gold << endl;
  cout << "[Healing Potions] >>> " << hpotion << endl;
  cout << "==================================" << endl;
  cout << "Head  - " << head << endl;
  cout << "Chest - " << chest << endl;
  cout << "Legs  - " << legs << endl;
  cout << "Feet  - " << feet << endl;
  cout << "==================================" << endl;
  cout << "[1]  Armory" << endl;
  cout << "[99] Exit" << endl;
  cin >> input;
  if (input == "99") {
    goto menue;
  } else if (input == "1") {
    goto armory;
  }
  goto inventory;

armory:
  clear();

  cout << R"(
   ,   A           {}
  / \, | ,        .--.
 |    =|= >      /.--.\
  \ /` | `       |====|
   `   |         |`::`|  
       |     .-;`\..../`;_.-^-._
      /\\/  /  |...::..|`   :   `|
      |:'\ |   /'''::''|   .:.   |
       \ /\;-,/\   ::  |..:::::..|
       |\ <` >  >._::_.| ':::::' |
       | `""`  /   ^^  |   ':'   |
    )" << endl;

  cout << "1-  Slimy Chestplate >>> [10% HP Increase] ";
  if (slimychestplate == 1) {
    cout << ">>> [Owned] ";
    if (chest == "slimychestplate") {
      cout << ">>> [Equiped]" << endl;
    } else {
      cout << endl;
    }
  } else {
    cout << endl;
  }

  cout << "2-  Slimy Helmet >>> [5% HP Increase] ";
  if (slimyhelmet == 1) {
    cout << ">>> [Owned] ";
    if (head == "slimyhelmet") {
      cout << ">>> [Equiped]" << endl;
    } else {
      cout << endl;
    }
  } else {
    cout << endl;
  }

  cout << "3-  Blob Legplates >>> [15% HP Increase] ";
  if (bloblegplates == 1) {
    cout << ">>> [Owned] ";
    if (legs == "bloblegplates") {
      cout << ">>> [Equiped]" << endl;
    } else {
      cout << endl;
    }
  } else {
    cout << endl;
  }

  cout << "4-  Blob Boots >>> [10% HP Increase] ";
  if (blobboots == 1) {
    cout << ">>> [Owned] ";
    if (feet == "blobboots") {
      cout << ">>> [Equiped]" << endl;
    } else {
      cout << endl;
    }
  } else {
    cout << endl;
  }

  cout << "99- Back" << endl;
  cin >> input;
  if (input == "99") {
    goto armor2;
  } else if (input == "1") {
    if (chest == "slimychestplate") {
      chest = "Open";
      goto armory;
    } else if (slimychestplate == 1) {
      chest = "slimychestplate";
      goto armory;
    } else {
      goto armory;
    }
  } else if (input == "2") {
    if (head == "slimyhelmet") {
      head = "Open";
      goto armory;
    } else if (slimyhelmet == 1) {
      head = "slimyhelmet";
      goto armory;
    } else {
      goto armory;
    }
  } else if (input == "3") {
    if (legs == "bloblegplates") {
      legs = "Open";
      goto armory;
    } else if (bloblegplates == 1) {
      legs = "bloblegplates";
      goto armory;
    } else {
      goto armory;
    }
  } else if (input == "4") {
    if (feet == "blobboots") {
      feet = "Open";
      goto armory;
    } else if (blobboots == 1) {
      feet = "blobboots";
      goto armory;
    } else {
      goto armory;
    }
  }

armor2:
  bhp = 0;
  bphp = 0;
  // Head
  if (head == "slimyhelmet") {
    bphp = bphp + .10;
  }
  // Chest
  if (chest == "slimychestplate") {
    bphp = bphp + .05;
  }
  // Legs
  if (legs == "bloblegplates") {
    bphp = bphp + .15;
  }
  // Feet
  if (feet == "blobboots") {
    bphp = bphp + .10;
  }
  goto inventory;

askill:
  clear();

  cout << R"(
              .__=\__                  .__==__,
            jf'      ~~=\,         _=/~'      `\,
        ._jZ'            `\q,   /=~             `\__
       j5(/                 `\./                  V\\,
     .Z))' _____              |             .____, \)/\
    j5(K=~~     ~~~~\=_,      |      _/=~~~~'    `~~+K\\,
  .Z)\/                `~=L   |  _=/~                 t\ZL
 j5(_/.__/===========\__   ~q |j/   .__============___/\J(N,
4L#XXXL_________________XGm, \P  .mXL_________________JXXXW8L
~~~~~~~~~~~~~~~~~~~~~~~~~YKWmmWmmW@~~~~~~~~~~~~~~~~~~~~~~~~~~
    )" << endl; // Bedtime stories?

  cout << "Available Skillpoints [" << skill << "]" << endl;
  cout << "1-  Strength [" << stre << "]" << endl;
  cout << "2-  Intelligence [" << inte << "]" << endl;
  cout << "3-  Dexterity [" << dext << "]" << endl;
  cout << "99- Exit" << endl;
  cin >> input;
  if (skill > 0) {
    if (input == "1") {
      stre = stre + 1;
      skill = skill - 1;
    } else if (input == "2") {
      inte = inte + 1;
      skill = skill - 1;
    } else if (input == "3") {
      dext = dext + 1;
      skill = skill - 1;
    } else if (input == "99") {
      goto menue;
    }
  } else {
    goto menue;
  }
  goto askill;

shop:
  clear();

  cout << R"(
                               ____
                  _           |---||            _
                  ||__________|---||___________||
                 /_ _ _ _ _ _ |:._|'_ _ _ _ _ _ _\`.
                /_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\:`.
               /_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\::`.
              /:.___________________________________\:::`-._
          _.-'_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _`::::::`-.._
      _.-' _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ `:::::::::`-._
    ,'_:._________________________________________________`:_.::::-';`
     `.'/ || |:::::`.'/::::::::`.'/::::::::`.'/::::::|.`.'/.|     :|
      ||  || |::::::||::::::::::||::::::::::||:::::::|..||..|     ||
      ||  || |  __  || ::  ___  || ::  __   || ::    |..||;||     ||
      ||  || | |::| || :: |:::| || :: |::|  || ::    |.|||:||_____||__
      ||  || | |::| || :: |:::| || :: |::|  || ::    |.|||:||_|_|_||,(
      ||_.|| | |::| || :: |:::| || :: |::|  || ::    |.'||..|    _||,|
   .-'::_.:'.:-.--.-::--.-:.--:-::--.--.--.-::--.--.-:.-::,'.--.'_|| |
    );||_|__||_|__|_||__|_||::|_||__|__|__|_||__|__|_|;-'|__|_(,' || '-
    ||||  || |. . . ||. . . . . ||. . . . . ||. . . .|::||;''||   ||:'
    ||||.;  _|._._._||._._._._._||._._._._._||._._._.|:'||,, ||,,
    '''''           ''-         ''-         ''-         '''  '''
    )" << endl;

  price = level * 5;
  cout << "[Gold] >>> " << gold << endl;
  cout << "1-  Health Potion (" << price << " gold)" << endl;
  cout << "99- Exit" << endl;
  cin >> input;
  if (input == "1") {
    price = level * 5;
    if (gold >= price) {
      hpotion = hpotion + 1;
      gold = gold - price;
      goto shop;
    } else {
      goto menue;
    }
  } else if (input == "99") {
    goto menue;
  }
  goto shop;

  // Receive / "Turn" in quests
questhall:
  clear();

  cout << R"(
         _______________
    ()==(              (@==()
         '______________'|
           |             |
           |  Quests...  |
         __)_____________|
    ()==(               (@==()
         '--------------'
    )" << endl;

  cout << "Current Quest >>> ";

  if (quest == 0) {
    quest = rand() % 5 + 1;
    switch (quest) {
    case 1:
      questc = 0;
      questr = 6;
      questmob = "Boar";
      questreward = rand() % 4 + 1;
      questdisplay = "Slay Boars";
      break;

    case 2:
      questc = 0;
      questr = 6;
      questmob = "Lion";
      questreward = rand() % 4 + 1;
      questdisplay = "Slay Lions";
      break;

    case 3:
      questc = 0;
      questr = 6;
      questmob = "Elephant";
      questreward = rand() % 4 + 1;
      questdisplay = "Slay Elephants";
      break;

    case 4:
      questc = 0;
      questr = 6;
      questmob = "Wolf";
      questreward = rand() % 4 + 1;
      questdisplay = "Slay Wolves";
      break;

    case 5:
      questc = 0;
      questr = 6;
      questmob = "Spider";
      questreward = rand() % 4 + 1;
      questdisplay = "Slay Spiders";
      break;
    }
  }

  cout << questdisplay << " [" << questc << "/" << questr << "]" << endl;
  cout << "Reward >>> ";

  switch (questreward) {
  case 1:
    qgoldr = rand() % (level * 10) + (level * 10);
    cout << qgoldr << " Gold" << endl;
    break;

  case 2:
    qxpr = rand() % (level * 5) + (level * 5);
    cout << qxpr << " XP" << endl;
    break;

  case 3:
    cout << "Slimy Chestplate >>> [10% HP Increase]" << endl;
    break;

  case 4:
    cout << "Slimy Helmet >>> [5% HP Increase]" << endl;
    break;
  }

  if (questc >= questr) {
    quest = 0;
    switch (questreward) {
    case 1:
      gold = gold + qgoldr;
      goto questhall;
      break;

    case 2:
      xp = xp + qxpr;
      goto questhall;
      break;

    case 3:
      slimychestplate = 1;
      goto questhall;
      break;

    case 4:
      slimyhelmet = 1;
      goto questhall;
      break;
    }
  }

  cout << "99- Exit" << endl;
  cin >> input;
  goto menue;

dungeonmenue:
  clear();
  cout << R"(
   _________________________________________________________
  |                            ,                            |
  |      .-'````````'.        '(`        .-'```````'-.      |
  |    .` |           `.      `)'      .` |           `.    |          
  |   /   |   ()        \      U      /   |    ()       \   |
  |  |    |    ;         | o   T   o |    |    ;         |  |
  |  |    |     ;        |  .  |  .  |    |    ;         |  |
  |  |    |     ;        |   . | .   |    |    ;         |  |
  |  |    |     ;        |    .|.    |    |    ;         |  |
  |  |    |____;_________|     |     |    |____;_________|  |  
  |  |   /  __ ;   -     |     !     |   /     `'() _ -  |  |
  |  |  / __  ()        -|        -  |  /  __--      -   |  |
  |  | /        __-- _   |   _- _ -  | /        __--_    |  |
  |__|/__________________|___________|/__________________|__|
 /                                             _ -        lc \
/   -_- _ -             _- _---                       -_-  -_ \

    )" << endl;

  cout << "Available Dungeons" << endl;
  cout << "[1]  The Slime Lair >>> [150 Gold, Blob Gear]" << endl;
  cout << "[99] Return to Menu" << endl;
  cin >> input;
  if (input == "99") {
    goto menue;
  } else if (input == "1") {
    if (gold >= 150) {
      status = "slimedung";
      gold = gold - 150;
      ckills = 0;
      rkills = 6;
      goto slimedung;
    } else {
      goto menue;
    }
  }
  goto dungeonmenue;

slimedung:
  clear();
  cout << R"(
  __    ____  _   _  ____      ___  __    ____  __  __  ____     
 / /___(_  _)( )_( )( ___)___ / __)(  )  (_  _)(  \/  )( ___)___ 
< <(___) )(   ) _ (  )__)(___)\__ \ )(__  _)(_  )    (  )__)(___)
 \_\    (__) (_) (_)(____)    (___/(____)(____)(_/\/\_)(____)    
                     __      __    ____  ____               __    
  ___  ___  ___  ___(  )    /__\  (_  _)(  _ \ ___  ___  ___\ \   
 (___)(___)(___)(___))(__  /(__)\  _)(_  )   /(___)(___)(___)> >  
                    (____)(__)(__)(____)(_)\_)              /_/   
    )" << endl;

  if (ckills >= rkills) {
    goto slimedungc;
  }

  cout << "[1]  Continue [" << ckills << "/" << rkills << " slimes killed]"
       << endl;
  cout << "[2]  Adrenaline (Heals all missing hp/mana)" << endl;
  cout << "[99] Exit" << endl;
  cin >> input;
  if (input == "1") {
    mmana = inte * 10;
    shp = stre * 20;
    mhp = stre * 20;
    etype = "Slime";
    random2 = rand() % 2 + 1;
    eability = "ooze";
    if (random2 == 1) {
      ehp = shp + rand() % (level * 8);
    } else {
      ehp = shp + rand() % (level * 6);
    }
    mehp = ehp;
    elevel = rand() % (level + 3) + 1;
    if ((elevel < (level - 3)) || (elevel > (level + 3))) {
      elevel = level;
    }
    goto aarena;
  } else if (input == "99") {
    goto menue;
  } else if (input == "2") {
    mhp = stre * 20;
    mmana = inte * 10;
    hp = mhp;
    hp = hp * (bphp + 1);
    hp = hp + bhp;
    mana = mmana;
  }
  goto slimedung;

slimedungc:
  status = "arena";
  cout << "You have completed The Slime Lair" << endl;
  rxp = rand() % (level * 6) + 5;
  rgold = rand() % (level * 9);
  cout << "You recieved " << rxp << " xp" << endl;
  cout << "You recieved " << rgold << " gold" << endl;
  xp = xp + rxp;
  gold = gold + rgold;
  random = rand() % 2 + 1;
  switch (random) {
  case 1:
    cout << "New legplates unlocked! >>> [Blob Legplates, increases hp by 15%]"
         << endl;
    bloblegplates = 1;
    break;

  case 2:
    cout << "New boots unclocked! >>> [Blob Boots, increases hp by 10%]"
         << endl;
    blobboots = 1;
    break;
  }
  cout << "Type [1] to return to the menu" << endl;
  cin >> input;
  goto menue;

slimedungr:
  ckills = ckills + 1;
  rxp = rand() % (level * 4) + 5;
  rgold = rand() % (level * 7);
  rgold = rgold * goldb;
  cout << "You recieved " << rxp << " xp" << endl;
  cout << "You recieved " << rgold << " gold" << endl;
  xp = xp + rxp;
  gold = gold + rgold;
  if (xp >= xpl) {
    level = level + 1;
    xpl = xpl + xpb;
    xpb = xpb + 50;
    skill = skill + 5;
    cout << "You have leveled up to level " << level << endl;
  }
  cout << "Type [1] to continue your adventure" << endl;
  cin >> input;
  goto slimedung;

savegame:
  clear();

  // Saving / Loading Strings
  sslimychestplate = std::to_string(slimychestplate);
  sslimyhelmet = std::to_string(slimyhelmet);
  sbloblegplates = std::to_string(bloblegplates);
  sblobboots = std::to_string(blobboots);
  spiclass = std::to_string(piclass);
  slevel = std::to_string(level);
  sxp = std::to_string(xp);
  sxpb = std::to_string(xpb);
  sxpl = std::to_string(xpl);
  sstre = std::to_string(stre);
  sinte = std::to_string(inte);
  sdext = std::to_string(dext);
  shpotion = std::to_string(hpotion);
  sgold = std::to_string(gold);
  sskill = std::to_string(skill);

  code = "";
  code = code + sgold + ":" + sstre + ":" + sinte + ":" + sdext + ":" + sskill +
         ":" + sxp + ":" + sxpl + ":" + sxpb + ":" + slevel + ":";
  code = code + shpotion + ":";
  code = code + spiclass + sslimyhelmet + sslimychestplate + sbloblegplates +
         sblobboots;
  cout << code << endl;
  cout << "Type [1] to return to the menue" << endl;
  cin >> input;
  goto menue;

  // Loading the game code they input
loadgame:
  clear();

  sslimychestplate = "";
  sslimyhelmet = "";
  sbloblegplates = "";
  sblobboots = "";
  spiclass = "";
  slevel = "";
  sxp = "";
  sxpb = "";
  sxpl = "";
  sstre = "";
  sinte = "";
  sdext = "";
  shpotion = "";
  sgold = "";
  sskill = "";

  cout << "Please input your game code EXACTLY (if you don't this may corrupt "
          "your game save)"
       << endl;
  cin >> input;
  code = input;
  goto compile;
  cout << code << endl;

  // Loading Game Save FILE
compile:
  x = 0;
goldr:
  cout << sgold << endl;
  if (code[x] == ':') { // If the character is a pipe
    x = x + 1;          // Go to next variable
    goto strer;
  } else {
    sgold = sgold + code[x]; // If not add the variables
    x = x + 1;               // Go to next charcter
    goto goldr;
  }
strer:
  if (code[x] == ':') { // If the character is a pipe
    x = x + 1;          // Go to next variable
    goto inter;
  } else {
    sstre = sstre + code[x]; // If not add the variables
    x = x + 1;               // Go to next charcter
    goto strer;
  }
inter:
  if (code[x] == ':') { // If the character is a pipe
    x = x + 1;          // Go to next variable
    goto dextr;
  } else {
    sinte = sinte + code[x]; // If not add the variables
    x = x + 1;               // Go to next charcter
    goto inter;
  }
dextr:
  if (code[x] == ':') { // If the character is a pipe
    x = x + 1;          // Go to next variable
    goto skillr;
  } else {
    sdext = sdext + code[x]; // If not add the variables
    x = x + 1;               // Go to next charcter
    goto dextr;
  }
skillr:
  if (code[x] == ':') { // If the character is a pipe
    x = x + 1;          // Go to next variable
    goto xpr;
  } else {
    sskill = sskill + code[x]; // If not add the variables
    x = x + 1;                 // Go to next charcter
    goto skillr;
  }
xpr:
  if (code[x] == ':') { // If the character is a pipe
    x = x + 1;          // Go to next variable
    goto xplr;
  } else {
    sxp += code[x]; // If not add the variables
    x = x + 1;      // Go to next charcter
    goto xpr;
  }
xplr:
  if (code[x] == ':') { // If the character is a pipe
    x = x + 1;          // Go to next variable
    goto xpbr;
  } else {
    sxpl = sxpl + code[x]; // If not add the variables
    x = x + 1;             // Go to next charcter
    goto xplr;
  }
xpbr:
  if (code[x] == ':') { // If the character is a pipe
    x = x + 1;          // Go to next variable
    goto levelr;
  } else {
    sxpb = sxpb + code[x]; // If not add the variables
    x = x + 1;             // Go to next charcter
    goto xpbr;
  }
levelr:
  if (code[x] == ':') { // If the character is a pipe
    x = x + 1;          // Go to next variable
    goto hpotionr;
  } else {
    slevel = slevel + code[x]; // If not add the variables
    x = x + 1;                 // Go to next charcter
    goto levelr;
  }
hpotionr:
  if (code[x] == ':') { // If the character is a pipe
    x = x + 1;          // Go to next variable
    goto items;
  } else {
    shpotion = shpotion + code[x]; // If not add the variables
    x = x + 1;                     // Go to next charcter
    goto hpotionr;
  }
items:
  spiclass += code[x];
  x = x + 1;
  sslimyhelmet += code[x];
  x = x + 1;
  sslimychestplate += code[x];
  x = x + 1;
  sbloblegplates += code[x];
  x = x + 1;
  sblobboots += code[x];
  goto settingvaribles;

settingvaribles:

  gold = atoi(sgold.c_str());                       // Gold
  stre = atoi(sstre.c_str());                       // Strength
  inte = atoi(sinte.c_str());                       // Intelligence
  dext = atoi(sdext.c_str());                       // Dexterity
  skill = atoi(sskill.c_str());                     // Skillpoints
  xp = atoi(sxp.c_str());                           // Xp
  xpl = atoi(sxpl.c_str());                         // Xp till level
  xpb = atoi(sxpb.c_str());                         // Increases xpl
  level = atoi(slevel.c_str());                     // Level
  hpotion = atoi(shpotion.c_str());                 // HP potions
  piclass = atoi(spiclass.c_str());                 // Class
  slimyhelmet = atoi(sslimyhelmet.c_str());         // Slimy Helmet
  slimychestplate = atoi(sslimychestplate.c_str()); // Slimy Chestplate
  bloblegplates = atoi(sbloblegplates.c_str());     // Blob Legplates
  blobboots = atoi(sblobboots.c_str());             // Blob Boots

  if (piclass == 1) {
    pclass = "Champion";
  } else if (piclass == 2) {
    pclass = "Necromancer";
  } else if (piclass == 3) {
    pclass = "Assassin";
  } else if (piclass == 4) {
    pclass = "Cleric";
  }

  /*
     gold = arr[1];
     stre = arr[2];
     inte = arr[3];
     dext = arr[4];
     skill = arr[5];
     xp = arr[6];
     xpl = arr[7];
     xpb = arr[8];
     level = arr[9];
     hpotion = arr[10];
     piclass = arr[11];
     slimyhelmet = arr[12];
     slimychestplate = arr[13];
     bloblegplates = arr[14];
     blobboots = arr[15];
     */

  goto compilend;

compilend:
  clear();

loadingload:
  cout << R"(
db       .d88b.   .d8b.  d8888b. d888888b d8b   db  d888b  
88      .8P  Y8. d8' `8b 88  `8D   `88'   888o  88 88' Y8b 
88      88    88 88ooo88 88   88    88    88V8o 88 88      
88      88    88 88~~~88 88   88    88    88 V8o88 88  ooo 
88booo. `8b  d8' 88   88 88  .8D   .88.   88  V888 88. ~8~ 
Y88888P  `Y88P'  YP   YP Y8888D' Y888888P VP   V8P  Y888P  
    )" << endl;
  y = 0;

loadingload2:
  if (y < 101) {
    y = y + 1;
    goto loadingload2;
  }

  clear();
  cout << "-------~ Process Complete ~-------" << endl;
  cout << "Please re-input your name" << endl;
  cin >> input;
  name = input;
  goto menue;

leave:
  clear();
  cout << "See you later!" << endl;

  return 0;
}
