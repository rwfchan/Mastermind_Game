//
// Created by Raymond Chan on 3/26/18.
//

#include <memory>
#include <vector>
#include "enum_only.h"
#include "Monsters.h"
#include "Monster_list.h"

#ifndef PROJECT101_SPAWN_GROUP_H
#define PROJECT101_SPAWN_GROUP_H

class Spawn_group {
 public:
  Spawn_group();
  explicit Spawn_group(std::vector<std::unique_ptr<Monsters>> && monsters_group);

  void addMonsters(std::unique_ptr<Monsters> && monster);
  void removeMonsters(std::unique_ptr<Monsters> & monster, int pos);
  void removeMonsters(std::unique_ptr<Monsters>& monster);
  void clearMonsters();
  void replaceMonster(std::unique_ptr<Monsters> && monster, int pos);

  void get_info(int level) const;
  int get_group_size() const;
  std::unique_ptr<Monsters>& get_monster(int index);
  std::vector<std::unique_ptr<Monsters>>& get_monsters_group();

  void level_1_make_group(int wave_number);

 private:
  std::vector<std::unique_ptr<Monsters>> monsters_group;
  int amount_of_monsters = 3;
  int group_size;

  void level_1_put_in_normal_monster(int *worthless_count, int *i);
  void Level_1_normal_spawn(int group_size);
  void level_1_wave_1();
  void print_level_1_group() const;

  void level_1_wave_5();
  void level_1_punisher_formation();

};

#endif //PROJECT101_SPAWN_GROUP_H
