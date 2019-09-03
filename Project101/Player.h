//
// Created by Raymond Chan on 3/26/18.
//

#include <iostream>
#include <string>
#include <vector>
#include "enum_only.h"
#include "Weapon_vault.h"

#ifndef PROJECT101_PLAYER_H
#define PROJECT101_PLAYER_H

class Player {
 public:
  Player();
  explicit Player(std::string name);

  void print_info();

  void set_hp(int amount);
  void set_stat(stat down, int amount);

  void set_attacked(bool has_attacked);
  void changing_AP(bool increase);
  bool using_AP();
  void reset_AP();

  int get_hp();
  int get_stat(stat statstic);
  int get_ap();

  void add_status(status status, int turn);
  void remove_status(std::pair<enum status, int>& status);

  std::vector<std::pair<status, int>>& get_status_list();
  status get_status(int pos);
  int get_afflicted_turn(int pos);

  bool get_attacked();

  std::vector<std::unique_ptr<Weapon>>& get_Weapon_list();
  void removeWeapon(unsigned long pos);
  void replaceWeapon(std::unique_ptr<Weapon> &&weapon, unsigned long pos = 1);

  void print_player_stat(int i);
  void print_player_affliction();
  void print_basic_head(int i);

  void print_weapons(int i);

  unsigned int seed_id;

 protected:
  std::string name;
  int hp;
  int attack;
  int defend;
  int speed;

  int organial_AP;
  int action_point;

  bool attacked;
  int monsters_slained;

  std::vector<std::pair<status, int>> status_list;
  std::vector<std::unique_ptr<Weapon>> weapon_list;
};

#endif //PROJECT101_PLAYER_H
