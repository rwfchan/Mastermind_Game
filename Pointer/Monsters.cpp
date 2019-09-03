//
// Created by Raymond Chan on 2/23/18.
//

#include "Monsters.h"

//Here, the name of the character is setted
Monsters::Monsters(const std::string &name, int hp, int attack, int defend, int speed) : name(name), hp(hp), attack(attack), defend(defend), speed(speed){}

void Monsters::setHp(int attack) {
  this->hp = hp - attack;
}
void Monsters::setAttack(int effect) {
  this->attack = attack - effect;
}
void Monsters::setDefend(int effect){
  this->defend = defend - effect;
}
void Monsters::setSpeed(int effect){
  this->speed = speed - effect;
}

//Here, user can get the name of the characters that belong to each Warrior_class
const std::string& Monsters::getName() const {
  return name;
}

const int Monsters::getHP() const {
  return hp;
}

const int Monsters::getAttack() const {
  return attack;
}

const int Monsters::getDefend() const {
  return defend;
}

const int Monsters::getSpeed() const {
  return speed;
}

