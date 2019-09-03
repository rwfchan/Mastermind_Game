//
// Created by Raymond Chan on 3/26/18.
//
#include "Monsters.h"

#ifndef PROJECT101_SKELETON_H
#define PROJECT101_SKELETON_H

class Skeleton : public Monsters{
 public:
  explicit Skeleton();

  int special_attack(Player& player) override;
  void print_monster(int i, int position) override;

};

#endif //PROJECT101_SKELETON_H
