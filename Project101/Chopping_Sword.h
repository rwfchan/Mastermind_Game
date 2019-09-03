//
// Created by Raymond Chan on 8/10/18.
//

#include "Weapon.h"

#ifndef PROJECT101_CHOPPING_SWORD_H
#define PROJECT101_CHOPPING_SWORD_H

class Chopping_Sword : public Weapon{
 public:
  explicit Chopping_Sword();

  std::string description() const override;
  void printing_weapon(int i) const override;

  void special_attack(std::unique_ptr<Monsters>& monster) override;
};

#endif //PROJECT101_CHOPPING_SWORD_H
