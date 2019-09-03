//
// Created by Raymond Chan on 8/10/18.
//

#include "Weapon.h"

#ifndef PROJECT101_BASHING_SHIELD_H
#define PROJECT101_BASHING_SHIELD_H

class Bashing_Shield : public Weapon{
  public:
    explicit Bashing_Shield();

  std::string description() const override;
  void printing_weapon(int i) const override;

  void special_attack(std::unique_ptr<Monsters>& monster) override;

};

#endif //PROJECT101_BASHING_SHIELD_H
