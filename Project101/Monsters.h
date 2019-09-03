//
// Created by Raymond Chan on 3/26/18.
//

#ifndef PROJECT101_MONSTERS_H
#define PROJECT101_MONSTERS_H

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "enum_only.h"

class Player;

class Monsters {
 public:
  Monsters();
  explicit Monsters (const std::string &name, int hp_giving, monster_type tag, int monster_id, bool apply_status = false);

  void set_hp(int damage);
  void set_stat(stat down, int amount);
  void set_attacked(bool has_attacked);

  std::string get_name();
  monster_type get_tag();
  int get_hp();
  int get_stat(stat stat1);
  bool get_attacked();
  int get_hp_giving();
  int get_monster_id();
  bool get_apply_status();

  void print_hp();
  void print_attack();
  void print_defend();
  void print_speed();
  void print_name();
  void print_status();

  virtual void print_monster(int i, int position) = 0;


  void add_status(status status, int turn);
  void remove_status(std::pair<enum status, int>& status);

  std::vector<std::pair<status, int> >& get_status_list();
  status get_status(int pos);
  int get_afflicted_turn(int pos);

  virtual int special_attack(Player& player) = 0;

 protected:
  std::string name;
  monster_type tag;
  int max_hp;
  int hp;
  int attack;
  int defend;
  int speed;

  int hp_giving;
  int monster_id;

  bool attacked;
  bool apply_status;

  std::vector<std::pair<status, int>> status_list;
};

#endif //PROJECT101_MONSTERS_H
