//
// Created by Raymond Chan on 2/23/18.
//

#include "Monster_B.h"

void Monster_B::get_info() const {
  std::cout << "== " << getName() << " ==" << std::endl;
  std::cout << "Health: " << getHP() << std::endl;
  std::cout << "Attack: " << getAttack() << std::endl;
  std::cout << "Defend: " << getDefend() << std::endl;
  std::cout << "Speed: " << getSpeed() << std::endl;
}

void Monster_B::hp_down() {
  std::cout << "Player dealt " << /*Hero::Player->getAttack()*/ "Filter:Hero" << " damage to " << getName() << std::endl;

  setHp( /*Hero::Player->getAttack()*/ 10);
}

Monster_B::Monster_B(const std::string &name, int hp, int attack, int defend, int speed) : Monsters(name, hp, attack, defend, speed) {}

