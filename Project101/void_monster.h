//
// Created by Raymond Chan on 8/8/18.
//

#include "Monsters.h"

#ifndef PROJECT101_VOID_MONSTER_H
#define PROJECT101_VOID_MONSTER_H

class void_monster : public Monsters {
 public:
  explicit void_monster();

  int special_attack(Player& player) override;
  void print_monster(int i, int position) override;

  int monster_id = 99;
};

#endif //PROJECT101_VOID_MONSTER_H
