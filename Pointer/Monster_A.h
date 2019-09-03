//
// Created by Raymond Chan on 2/23/18.
//

#ifndef POINTER_WARRIOR_CLASS_H
#define POINTER_WARRIOR_CLASS_H

#include "Monsters.h"
#include "Hero.h"

class Monster_A : public Monsters {
 public:

  //When the addCharacter from Travel group class was called, the name is passed into the whatever class indicated in the class pointer
  explicit Monster_A(const std::string& name, int hp = 30, int attack = 10, int defend = 0, int speed = 15);
  //Each sub classes like this one is inherit from Character
  //This function will run depend on what class pointer was called in main.cpp
  virtual void get_info() const override;
  virtual void hp_down() override;
  //virtual void attack_down() override;
  //virtual void defend_down() override;
  //virtual void speed_down() override;

};

class Monster_A1 : public Monster_A {
 public:
  explicit Monster_A1(const std::string& name, int hp, int attack, int defend, int speed);

  //Notice that ChildWarrior inherits from Warrior_class
  //In this case, get_info() in Warrior_class do not need virtual for ChildWarrior
  virtual void get_info() const override;
  virtual void hp_down() override;
  //virtual void attack_down() override;
  //virtual void defend_down() override;
  //virtual void speed_down() override;
};

#endif //POINTER_WARRIOR_CLASS_H
