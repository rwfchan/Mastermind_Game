//
// Created by Raymond Chan on 2/23/18.
//

#ifndef POINTER_CHARACTER_H
#define POINTER_CHARACTER_H

#include <string>
#include <iostream>
#include "Hero.h"

//Pure Virtual/Abstract class
class Monsters {
 public:

  //Explicit here is to prevent a cast onto a character
  // Without explicit you can do: static_cast<Character>("Some Name")
    //Since Character's parameter have an argument that taks in a string, you can cast a string into the instance Character
  // With explicit, you can't do that

  //This is where the string got from main.cpp to Warrior_class.cpp end up -> Character.cpp
  explicit Monsters (const std::string & name, int hp, int attack, int defend, int speed);

  //The virtual keyword on get_info indicate that
  // all classes inherited this class and with the same function get_info
  //can have the get_info
  //More information in Travel_group.cpp

  //If Character's get_info have no virtual keyword, this get_info will take priority

  //virtual paires with override
  //  1.However, override is not strictly neccessary (just like const)
  //  2.virtual and override pairs across "generation"
  //More information go to Warrior_Class
  virtual void get_info() const = 0;
  virtual void hp_down() = 0;
//  virtual void attack_down() = 0;
//  virtual void defend_down() = 0;
//  virtual void speed_down() = 0;

//FIXME Do we need setter?
  void setHp(int attack);
  void setAttack(int effect);
  void setDefend(int effect);
  void setSpeed(int effect);

  const std::string& getName() const;
  const int getHP() const;
  const int getAttack() const;
  const int getDefend() const;
  const int getSpeed() const;

 protected:
  std::string name;
  int hp;
  int attack;
  int defend;
  int speed;
};

#endif //POINTER_CHARACTER_H
