//
// Created by Raymond Chan on 3/26/18.
//

#include <iomanip>
#include "Spawn_group.h"
#include "Unity.h"

Spawn_group::Spawn_group() = default;
Spawn_group::Spawn_group(std::vector<std::unique_ptr<Monsters>> &&monsters_group) : monsters_group(std::move(monsters_group)){}

void Spawn_group::addMonsters(std::unique_ptr<Monsters> &&monster) {
  monsters_group.push_back(std::move(monster));
}
void Spawn_group::removeMonsters(std::unique_ptr<Monsters> &monster, int pos) {
  monster.release();
  monsters_group.erase(monsters_group.begin() + pos);
  replaceMonster(std::make_unique<void_monster>(), pos);
  group_size--;
}
void Spawn_group::removeMonsters(std::unique_ptr<Monsters> &monster) {
  auto pos = std::find(monsters_group.begin(), monsters_group.end(), monster);

  monster.release();
  monsters_group.erase(pos);
  monsters_group.insert(pos, std::make_unique<void_monster>());
  group_size--;
}

void Spawn_group::clearMonsters() {
  int total_group_size = group_size;

  for(unsigned int i = 0; i < total_group_size; i++) {
    removeMonsters(monsters_group.at(i), i);
  }
}
void Spawn_group::replaceMonster(std::unique_ptr<Monsters> &&monster, int pos) {
  monsters_group.insert(monsters_group.begin() + pos, std::move(monster));
}

int Spawn_group::get_group_size() const {
  return group_size;
}
std::unique_ptr<Monsters>& Spawn_group::get_monster(int index) {
  return monsters_group.at(static_cast<unsigned long>(index));
}
std::vector<std::unique_ptr<Monsters>> &Spawn_group::get_monsters_group() {
  return monsters_group;
}
