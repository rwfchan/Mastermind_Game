//
// Created by Raymond Chan on 3/28/18.
//

#include "Imp.h"
#include "Unity.h"

Imp::Imp() : Monsters("Imp", 10, hostile, 0){
  unsigned int seed = 0;

  seed = static_cast<unsigned int>(rand());
  if(true_false_randomizer(seed)){
    hp = 10 + rand() % 5;
    max_hp = hp;
  } else {
    hp = 10 + (rand() % 5 * -1);
    max_hp = hp;
  }

  seed = static_cast<unsigned int>(rand());
  if(true_false_randomizer(seed)){
    attack = 10 + rand() % 5;
  } else {
    attack = 10 + (rand() % 5 * -1);
  }

  seed = static_cast<unsigned int>(rand());
  if(true_false_randomizer(seed)){
    defend = 10 + rand() % 5;
  } else {
    defend = 10 + (rand() % 5 * -1);
  }

  seed = static_cast<unsigned int>(rand());
  if(true_false_randomizer(seed)){
    speed = 15 + rand() % 5;
  } else {
    speed = 15 + (rand() % 5 * -1);
  }
}

int Imp::special_attack(Player &player) {
  return 0;
}

void Imp::print_monster(int i, int position) {
  switch (i) { //Imp have 7 spaces
    case 0:
      monster_spacing();
      std::cout << "     ";
      monster_tag_color(nothing, position);
      print_name();
      std::cout << "       ";
      monster_spacing();
      break;
    case 1:
      monster_spacing();
      std::cout << "    /v\\___/\\     ";
      monster_spacing();
      break;
    case 2:
      monster_spacing();
      std::cout << "    | -  o |     ";
      monster_spacing();
      break;
    case 3:
      monster_spacing();
      std::cout << "    | (00) |     ";
      monster_spacing();
      break;
    case 4:
      monster_spacing();
      std::cout << "    \\-==-=-/     ";
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
      std::cout << "Default for imp" << std::endl;
      break;
  }
}

