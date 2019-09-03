//
// Created by Raymond Chan on 8/8/18.
//

#include "void_monster.h"
#include "Unity.h"

void_monster::void_monster() : Monsters(" ", 0, tag_empty, 99){
  hp = 0;
  attack = 0;
  defend = 0;
  speed = 0;
}

int void_monster::special_attack(Player &player) {
  return 0;
}
void void_monster::print_monster(int i, int position) {
  int spacing = 16;

  switch (i) { //soul have 0 space
    case 0:
      monster_spacing();
      std::cout << std::setfill(' ') << std::setw(spacing)  << ' ';
      monster_spacing();
      break;
    case 1:
      monster_spacing();
      std::cout << std::setfill(' ') << std::setw(spacing)  << ' ';
      monster_spacing();
      break;
    case 2:
      monster_spacing();
      std::cout << std::setfill(' ') << std::setw(spacing)  << ' ';
      monster_spacing();
      break;
    case 3:
      monster_spacing();
      std::cout << std::setfill(' ') << std::setw(spacing)  << ' ';
      monster_spacing();
      break;
    case 4:
      monster_spacing();
      std::cout << std::setfill(' ') << std::setw(spacing)  << ' ';
      monster_spacing();
      break;
    case 5:
      monster_spacing();
      std::cout << std::setfill(' ') << std::setw(spacing)  << ' ';
      monster_spacing();
      break;
    case 6:
      monster_spacing();
      std::cout << std::setfill(' ') << std::setw(spacing)  << ' ';
      monster_spacing();
      break;
    case 7:
      monster_spacing();
      std::cout << std::setfill(' ') << std::setw(spacing)  << ' ';
      monster_spacing();
      break;
    case 8:
      monster_spacing();
      std::cout << std::setfill(' ') << std::setw(spacing)  << ' ';
      monster_spacing();
      break;
    case 9:
      monster_spacing();
      std::cout << std::setfill(' ') << std::setw(spacing)  << ' ';
      monster_spacing();
      break;
    default:
      std::cout << "Default for soul" << std::endl;
      break;
  }
}

