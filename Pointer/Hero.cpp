//
// Created by Raymond Chan on 2/23/18.
//

#include "Hero.h"

Hero::Hero(int hp, int attack, int defend, int speed) : hp(hp), attack(attack), defend(defend), speed(speed){

  //Initialize Player into this hero
  //Player = this;
}

void Hero::set_HP(const int attack) {
  this->hp = hp - attack;
}
void Hero::set_Attack(const int effect) {
  this->attack = attack - effect;
}
void Hero::set_Defend(const int effect){
  this->defend = defend - effect;
}
void Hero::set_Speed(const int effect){
  this->speed = speed - effect;
}


const int Hero::getHP() const {
  return hp;
};
const int Hero::getAttack() const {
  return attack;
};
const int Hero::getDefend() const {
  return defend;
};
const int Hero::getSpeed() const {
  return speed;
};

const void Hero::get_info() const {
  std::cout << "----------------------------------------------" << std::endl;
  std::cout << "Your stat: " << std::endl;
  std::cout << "Health: " << getHP() << std::endl;
  std::cout << "Attack: " << getAttack() << std::endl;
  std::cout << "Defend: " << getDefend() << std::endl;
  std::cout << "Speed: " << getSpeed() << std::endl;
  std::cout << "----------------------------------------------" << std::endl;
}



