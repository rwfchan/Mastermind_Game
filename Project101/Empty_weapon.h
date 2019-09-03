//
// Created by Raymond Chan on 8/10/18.
//
#include "Weapon.h"

#ifndef PROJECT101_EMPTY_WEAPON_H
#define PROJECT101_EMPTY_WEAPON_H

class Empty_weapon : public Weapon{
 public:
  explicit Empty_weapon();

  std::string description() const override;
  void printing_weapon(int i) const override;

  void special_attack(std::unique_ptr<Monsters>& monster) override;

};

#endif //PROJECT101_EMPTY_WEAPON_H
