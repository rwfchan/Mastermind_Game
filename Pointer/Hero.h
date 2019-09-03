//
// Created by Raymond Chan on 2/23/18.
//

#ifndef POINTER_HERO_H
#define POINTER_HERO_H
#include <iostream>
#include <memory>

class Hero {
 protected:
  int hp;
  int attack;
  int defend;
  int speed;

 public:

  //Static here mean:
  //This pointer is treated as a globe variable for this class only
  //static Hero* Player;

  explicit Hero(int hp = 50, int attack = 7, int defend = 10, int speed = 5);

  void set_HP(int attack);
  void set_Attack(int effect);
  void set_Defend(int effect);
  void set_Speed(int effect);

  const int getHP() const;
  const int getAttack() const;
  const int getDefend() const;
  const int getSpeed() const;

  const void get_info() const;
};


#endif //POINTER_HERO_H
