//
// Created by Raymond Chan on 3/26/18.
//

#include "Skeleton.h"
#include "Unity.h"

Skeleton::Skeleton() : Monsters("Skeleton", 5, hostile, 1){
  unsigned int seed = 0;

  seed = static_cast<unsigned int>(rand());
  if(true_false_randomizer(seed)){
    hp = 30 + rand() % 5;
    max_hp = hp;
  } else {
    hp = 30 + (rand() % 5 * -1);
    max_hp = hp;
  }

  seed = static_cast<unsigned int>(rand());
  if(true_false_randomizer(seed)){
    attack = 17 + rand() % 5;
  } else {
    attack = 17 + (rand() % 5 * -1);
  }

  seed = static_cast<unsigned int>(rand());
  if(true_false_randomizer(seed)){
    defend = 5 + rand() % 5;
  } else {
    defend = 5 + (rand() % 5 * -1);
  }

  seed = static_cast<unsigned int>(rand());
  if(true_false_randomizer(seed)){
    speed = 7 + rand() % 5;
  } else {
    speed = 7 + (rand() % 5 * -1);
  }
}

int Skeleton::special_attack(Player &player) {
  return 0;
}
void Skeleton::print_monster(int i, int position) {
  switch (i) { //Skeleton have 7 spaces
    case 0:
      monster_spacing();
      std::cout <<  " " << ' ';
      monster_tag_color(nothing, position);
      print_name();
      std::cout << "     ";
      monster_spacing();
      break;
    case 1:
      monster_spacing();
      std::cout << "     _____       ";
      monster_spacing();
      break;
    case 2:
      monster_spacing();
      std::cout << "    | o o |      ";
      monster_spacing();
      break;
    case 3:
      monster_spacing();
      std::cout << "     \\ A /       ";
      monster_spacing();
      break;
    case 4:
      monster_spacing();
      std::cout << "     [===]       ";
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
      std::cout << "Default for skeleton" << std::endl;
      break;
  }
}
