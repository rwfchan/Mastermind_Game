//
// Created by Raymond Chan on 7/31/18.
//

#include "worthless_soul.h"
#include "Unity.h"

worthless_soul::worthless_soul() : Monsters("Worthless Soul", 5, nonhostile, 2){
  max_hp = 0;
  hp = 0;
  attack = 0;
  defend = 0;
  speed = 0;
}

int worthless_soul::special_attack(Player &player) {
  return 0;
}
void worthless_soul::print_monster(int i, int position) {
  switch (i) { //soul have 0 space
    case 0:
      monster_spacing();
      std::cout << ' ' << color_tan << position << '.' << color_normal << "Worthless Soul";
      monster_spacing();
      break;
    case 1:
      monster_spacing();
      std::cout << "     (;;)        ";
      monster_spacing();
      break;
    case 2:
      monster_spacing();
      std::cout << "      | |        ";
      monster_spacing();
      break;
    case 3:
      monster_spacing();
      std::cout << R"(    !\|!\\_      )";
      monster_spacing();
      break;
    case 4:
      monster_spacing();
      std::cout << "       `~+--\\    ";
      monster_spacing();
      break;
    case 5:
      print_status();
      break;
    case 6:
      print_hp();
      break;
    case 7:
      print_attack();
      break;
    case 8:
      print_defend();
      break;
    case 9:
      print_speed();
      break;
    default:
      std::cout << "Default for soul" << std::endl;
      break;
  }
}
