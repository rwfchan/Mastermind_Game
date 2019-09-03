//
// Created by Raymond Chan on 7/31/18.
//
#include "Monsters.h"

#ifndef PROJECT101_WORTHLESS_SOUL_H
#define PROJECT101_WORTHLESS_SOUL_H

class worthless_soul : public Monsters {
 public:
    explicit worthless_soul();

    int special_attack(Player& player) override;
    void print_monster(int i, int position) override;

  int monster_id = 2;
};

#endif //PROJECT101_WORTHLESS_SOUL_H
