//
// Created by Raymond Chan on 8/10/18.
//

#ifndef PROJECT101_WEAPON_H
#define PROJECT101_WEAPON_H

#include "enum_only.h"
#include "Unity.h"
#include <string>
class Monsters;

class Weapon {
 public:
  Weapon(Weapon& weapon);
  explicit Weapon(std::string name, weapon_type type, weapon_order order, int weapon_id,
                  weapon_mod_type mod_type = null, stat increase_at = nothing, int mod_amount = 0,
                  stat stat_to_enemy = nothing, status status_to_enemy = none);

  std::string get_name();
  weapon_type get_weapon_type();
  weapon_order get_weapon_order();

  weapon_mod_type get_mod_type();
  stat get_increase_at();
  int get_mod_amount();

  stat get_stat_to_enemy();
  status get_status_to_enemy();

  virtual std::string description() const = 0;
  virtual void printing_weapon(int i) const = 0;

  virtual void special_attack(std::unique_ptr<Monsters>& monster) = 0;

 protected:
  std::string name;
  const weapon_type type = type_empty;
  const weapon_order order = order_empty;
  const stat increase_at = nothing;

  int weapon_id;

  //The mod could be multiplication, addition, or nothing
  weapon_mod_type mod_type;
  int mod_amount;

  //Weapon could have special effect on target like stat down or apply status
  stat stat_to_enemy;
  status status_to_enemy;

};

#endif //PROJECT101_WEAPON_H
