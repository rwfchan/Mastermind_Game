//
// Created by Raymond Chan on 3/28/18.
//
#include "Monsters.h"

#ifndef PROJECT101_IMP_H
#define PROJECT101_IMP_H

class Imp : public Monsters{
 public:
  explicit Imp();

  int special_attack(Player& player) override;
  void print_monster(int i, int position) override;

};

#endif //PROJECT101_IMP_H
