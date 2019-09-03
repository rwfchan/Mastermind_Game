//
// Created by Raymond Chan on 8/14/18.
//

#include "Punisher_boss.h"
#include "Unity.h"

Punisher_boss::Punisher_boss() : Monsters("Punisher", 40, elite, 3, true) {
  unsigned int seed = 0;

  seed = static_cast<unsigned int>(rand());
  if(true_false_randomizer(seed)){
    hp = 40 + rand() % 10;
    max_hp = hp;
  } else {
    hp = 40 + (rand() % 10 * -1);
    max_hp = hp;
  }

  seed = static_cast<unsigned int>(rand());
  if(true_false_randomizer(seed)){
    attack = 30 + rand() % 5;
  } else {
    attack = 30 + (rand() % 5 * -1);
  }

  seed = static_cast<unsigned int>(rand());
  if(true_false_randomizer(seed)){
    defend = 5 + rand() % 5;
  } else {
    defend = 5 + (rand() % 5 * -1);
  }

  seed = static_cast<unsigned int>(rand());
  if(true_false_randomizer(seed)){
    speed = 5 + rand() % 5;
  } else {
    speed = 5 + (rand() % 5 * -1);
  }
}

int Punisher_boss::special_attack(Player& player) {
  //One in third chance punisher will do special attack;
  int attack_decisor = rand() % 2;

  if(attack_decisor == 0) {
    std::cout << "The Punisher crave out a piece of your fresh!" << std::endl;

    int turn = (rand() % 3) + 3;
    player.add_status(bleed, turn);
    return attack / 2;
  }



  std::cout << "The Punisher bash you with his Meat Tenderizer!" << std::endl;
  return attack;
}
void Punisher_boss::print_monster(int i, int position) {
  switch (i) { //Skeleton have 7 spaces
    case 0:
      monster_spacing();
      std::cout <<  "      ";
      monster_tag_color(nothing, 2);
      print_name();
      std::cout << " ";
      monster_spacing();
      break;
    case 1:
      monster_spacing();
      std::cout << std::left << std::setw(22) << " /|     |\\     ______" << "  ";
      break;
    case 2:
      monster_spacing();
      std::cout << std::left << std::setw(22) << " \\ \\___/ /    < <  > >" << "  ";
      break;
    case 3:
      monster_spacing();
      std::cout << std::left << std::setw(22) << "  _|_oo_|_    <_<__>_>" << "  ";
      break;
    case 4:
      monster_spacing();
      std::cout << std::left << std::setw(22) << "/--|_|_|_|---\\   ||" << "  ";
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
      std::cout << "Somwthing's wrong with punisher" << std::endl;
      break;
  }
}
