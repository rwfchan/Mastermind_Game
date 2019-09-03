//
// Created by Raymond Chan on 8/14/18.
//

#include "Monsters.h"
#include "Player.h"

#ifndef PROJECT101_PUNISHER_BOSS_H
#define PROJECT101_PUNISHER_BOSS_H

//This boss can apply bleed
//  This bleed attack half the damage of this boss, but apply bleed to player
//  Bleed makes the player lose 3 hp every turn, for 3 - 5 turns
//  Bleed calculate after everyone acted

class Punisher_boss : public Monsters{
 public:
  explicit Punisher_boss();

  int special_attack(Player& player) override;
  void print_monster(int i, int position) override;
};

#endif //PROJECT101_PUNISHER_BOSS_H
