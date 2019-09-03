//
// Created by Raymond Chan on 2/23/18.
//

#include "Monster_A.h"
#include "Hero.h"
#include <iostream>

//This is the real function of get_info
void Monster_A::get_info() const {
  std::cout << "== " << name << " ==" << std::endl;
  std::cout << "Health: " << getHP() << std::endl;
  std::cout << "Attack: " << getAttack() << std::endl;
  std::cout << "Defend: " << getDefend() << std::endl;
  std::cout << "Speed: " << getSpeed() << std::endl;
}

//Is there a way to link Hero onto this function without making parameter
void Monster_A::hp_down() {
  std::cout << "Player dealt " << /*Hero::Player->getAttack()*/ "Filter:Hero" << " damage to " << getName() << std::endl;

  setHp( /*Hero::Player->getAttack()*/ 10);
}


//Here is where the string of name from the addCharacter get pass into Character class
Monster_A::Monster_A(const std::string &name, int hp, int attack, int defend, int speed) : Monsters(name, hp, attack, defend, speed) {}

void Monster_A1::get_info() const {
  std::cout << "== " << getName() << " ==" << std::endl;
  std::cout << "Health: " << getHP() << std::endl;
  std::cout << "Attack: " << getAttack() << std::endl;
  std::cout << "Defend: " << getDefend() << std::endl;
  std::cout << "Speed: " << getSpeed() << std::endl;
}

Monster_A1::Monster_A1(const std::string& name, int hp, int attack, int defend, int speed) : Monster_A(name, hp, attack, defend, speed){}

void Monster_A1::hp_down() {
  std::cout << "Player destroyed " << getName() << " by dealting " << /*Hero::Player->getAttack()*/ "Filter:Hero" << std::endl;

  setHp( /*Hero::Player->getAttack()*/ 10);
}
