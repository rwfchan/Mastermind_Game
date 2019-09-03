//
// Created by Raymond Chan on 8/10/18.
//

#include "Weapon.h"
Weapon::Weapon(Weapon& weapon) {}
Weapon::Weapon(const std::string name, const weapon_type type, const weapon_order order, int weapon_id,
               const weapon_mod_type mod_type, const stat increase_at, const int mod_amount,
               stat stat_to_enemy, status status_to_enemy)
    : name(name), type(type), order(order), weapon_id(weapon_id),
      mod_type(mod_type), increase_at(increase_at), mod_amount(mod_amount),
      stat_to_enemy(stat_to_enemy), status_to_enemy(status_to_enemy){}

std::string Weapon::get_name() {
  return name;
}
weapon_type Weapon::get_weapon_type() {
  return type;
}
weapon_order Weapon::get_weapon_order() {
  return order;
}

weapon_mod_type Weapon::get_mod_type() {
  return mod_type;
}
stat Weapon::get_increase_at() {
  return increase_at;
}
int Weapon::get_mod_amount() {
  return mod_amount;
}

stat Weapon::get_stat_to_enemy() {
  return stat_to_enemy;
}
status Weapon::get_status_to_enemy() {
  return status_to_enemy;
}

