//
// Created by Raymond Chan on 3/26/18.
//
//Imp --> 0
//Skeleton --> 1
//worthless_soul --> 2
//Punisher_boss --> 3


#include "Monsters.h"
#include "Unity.h"
#include <iomanip>
Monsters::Monsters() {}
Monsters::Monsters(const std::string &name, int hp_giving, const monster_type tag, const int monster_id, const bool apply_status)
    : name(name), hp_giving(hp_giving), tag(tag), monster_id(monster_id), attacked(false), apply_status(apply_status){}

void Monsters::set_hp(int damage) {
  hp = hp + damage;
}
void Monsters::set_stat(stat down, int amount) {
  switch (down) {
    case stat::attack: attack += amount;
      return;
    case stat::defend: defend += amount;
      return;
    case stat::speed: speed += amount;
      return;
    default:
    std::cout << "Something horrible happened with set_stat Monsters" << std::endl;
  }
}
void Monsters::set_attacked(bool has_attacked) {
  attacked = has_attacked;
}

bool Monsters::get_attacked() {
  return attacked;
}
int Monsters::get_stat(stat stat1) {
  switch (stat1) {
    case stat::attack:return attack;
    case stat::defend:return defend;
    case stat::speed:return speed;
    default:return 999999;
  }
}
std::string Monsters::get_name() {
  return name;
}
monster_type Monsters::get_tag() {
  return tag;
}
int Monsters::get_hp() {
  return hp;
}
int Monsters::get_hp_giving() {
  return hp_giving;
}
int Monsters::get_monster_id() {
  return monster_id;
}
bool Monsters::get_apply_status() {
  return apply_status;
}

void Monsters::print_hp() {
  monster_spacing();
  monster_tag_color(health_point);
  std::cout << std::right << std::setw(2) << hp << '\\' << std::setw(2) << max_hp << "      ";
  monster_spacing();
}
void Monsters::print_attack() {
  monster_spacing();
  monster_tag_color(stat::attack);
  std::cout << std::left << std::setw(2) << get_stat(stat::attack) << "     ";
  monster_spacing();
}
void Monsters::print_defend() {
  monster_spacing();
  monster_tag_color(stat::defend);
  std::cout << std::left << std::setw(2) << get_stat(stat::defend) << "     ";
  monster_spacing();
}
void Monsters::print_speed() {
  monster_spacing();
  monster_tag_color(stat::speed);
  std::cout << std::left << std::setw(2) << get_stat(stat::speed) << "     ";
  monster_spacing();
}
void Monsters::print_name() {
  if(attacked) {
    std::cout << color_tan << name << color_normal;
  } else {
    std::cout << name;
  }
}
void Monsters::print_status() {
  monster_spacing();
  for (std::pair<status, int> &stat_list : get_status_list()) {
    switch(stat_list.first) {
      case bleed:
        std::cout << color_red << " B" << color_normal;
        break;
      case poison:
        std::cout << color_green << " P" << color_normal;
        break;
      default:
        std::cout << "Error in status_list for Monsters" << std::endl;
        exit(0);
        break;
    }
  }
  std::cout << std::setw(static_cast<int>(24 - get_status_list().size() * 2)) << '|';
}

void Monsters::add_status(status status, int turn) {
  switch(status) {
    case bleed:
      std::cout << "You made " << name << color_red << " bleed" << color_normal << "!" << std::endl;
      break;
    case poison:
      std::cout << "You " << color_green << "poisoned " << color_normal << name << std::endl;
      break;
    default:
      std::cout << "Something's wrong with add_status(Monster)" << std::endl;
      break;
  }

  status_list.emplace_back(status, turn);
}
void Monsters::remove_status(std::pair<enum status, int>& status) {
  std::vector<std::pair<enum status, int>>::iterator pos = std::find(status_list.begin(), status_list.end(), status);
  status_list.erase(pos);
}

std::vector<std::pair<status, int>> &Monsters::get_status_list() {
  return status_list;
}
status Monsters::get_status(int pos) {
  return status_list.at(static_cast<unsigned long>(pos)).first;;
}
int Monsters::get_afflicted_turn(int pos) {
  return status_list.at(static_cast<unsigned long>(pos)).second;
}
