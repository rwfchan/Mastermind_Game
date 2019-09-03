//
// Created by Raymond Chan on 8/20/18.
//

#include "Weapon.h"

#ifndef PROJECT101_MEAT_TENDERIZER_H
#define PROJECT101_MEAT_TENDERIZER_H

class Meat_Tenderizer : public Weapon {
 public:
  explicit Meat_Tenderizer();

  std::string description() const override;
  void printing_weapon(int i) const override;

  void special_attack(std::unique_ptr<Monsters>& monster) override;

};

#endif //PROJECT101_MEAT_TENDERIZER_H
