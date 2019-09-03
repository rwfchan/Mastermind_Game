//
// Created by Raymond Chan on 2/23/18.
//

#ifndef POINTER_WIZARD_CLASS_H
#define POINTER_WIZARD_CLASS_H

#include "Monsters.h"

class Monster_B : public Monsters {
 public:

  //When the addCharacter from Travel group class was called, the name is passed into the whatever class indicated in the class pointer
  explicit Monster_B(const std::string& name, int hp, int attack, int defend, int speed);

  //Each sub classes like this one is inherit from Character
  //This function will run depend on what class pointer was called in main.cpp
  virtual void get_info() const override;
  virtual void hp_down() override;
  //virtual void attack_down() override;
  //virtual void defend_down() override;
  //virtual void speed_down() override;

};


#endif //POINTER_WIZARD_CLASS_H
