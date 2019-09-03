//
// Created by Raymond Chan on 3/26/18.
//

#include "Player.h"
#include "Unity.h"
#include <ctime>
#include <cmath>

Player::Player() = default;
Player::Player(std::string name)
    : organial_AP(1), action_point(organial_AP), attacked(false), monsters_slained(0){
  this->name = "You";

//  std::cout << "Please enter your name" << std::endl;
//  std::cin >> this.name;

  std::ostringstream foo;
  foo << this;
  std::string string = foo.str();
  for (char character : string) {
    seed_id += static_cast<int>(character);
  }

  seed_id = seed_id % 1000;

  srand(static_cast<unsigned int>(time(nullptr)));
  auto seed = static_cast<unsigned int>(rand());

  if(true_false_randomizer(seed)){
    hp = 50 + rand() % 5;
  } else {
    hp = 50 + (rand() % 5 * -1);
  }

  seed = static_cast<unsigned int>(rand());
  srand(seed);
  if(true_false_randomizer(seed)){
    attack = 25 + rand() % 5;
  } else {
    attack = 25 + (rand() % 5 * -1);
  }

  seed = static_cast<unsigned int>(rand());
  srand(seed);
  if(true_false_randomizer(seed)){
    defend = 5 + rand() % 5;
  } else {
    defend = 5 + (rand() % 5 * -1);
  }

  seed = static_cast<unsigned int>(rand());
  srand(seed);
  if(true_false_randomizer(seed)){
    speed = 10 + rand() % 5;
  } else {
    speed = 10 + (rand() % 5 * -1);
  }

  //TODO make the intial weapon list declares when the object was intialized
  weapon_list.push_back(std::move(std::make_unique<Chopping_Sword>()));
  weapon_list.push_back(std::move(std::make_unique<Empty_weapon>()));
}

void Player::print_info() {
  int line_number = 5;

  for (int line = 0; line < line_number; line++) {
    print_player_stat(line);
    weapon_list.at(0)->printing_weapon(line);
    print_basic_head(line);
    weapon_list.at(1)->printing_weapon(line);

    print_weapons(line);
    std::cout << std::endl;
  }

  std::cout << std::endl;
}

void Player::set_hp(int amount) {
  hp = hp + amount;
}
void Player::set_stat(stat statstic, int amount) {
  switch (statstic) {
    case stat::attack: attack += amount;
      return;
    case stat::defend: defend += amount;
      return;
    case stat::speed: speed += amount;
      return;
    default:return;
  }
}
void Player::set_attacked(bool has_attacked) {
  attacked = has_attacked;
}

std::vector<std::pair<status, int>> &Player::get_status_list() {
  return status_list;
}
void Player::add_status(status status, int turn) {
  //status_list.push_back(std::make_pair(status, turn));
  switch(status) {
    case bleed:
    std::cout << color_red << "Blood fountaining out" << color_normal << " from the wound!" << std::endl;
      break;
    case poison:
    std::cout << "You feel " << color_green << "sick " << color_normal << std::endl;
      break;
    default:
    std::cout << "Something's wrong with add_status(Player)" << std::endl;
      break;
  }

  status_list.emplace_back(status, turn);
}
void Player::remove_status(std::pair<enum status, int>& status) {
  auto pos = std::find(status_list.begin(), status_list.end(), status);
  status_list.erase(pos);
}

void Player::changing_AP(bool increase) {
  if(increase) {
    action_point++;
    organial_AP++;

    std::cout << "Your Action Point had increased" << std::endl;
  } else {
    action_point--;
    organial_AP--;

    std::cout << "Your Action Point had decreased" << std::endl;
  }
}
bool Player::using_AP() {

  action_point--;

  return action_point >= 0;
}

int Player::get_hp() {
  return hp;
}
int Player::get_stat(stat stat1) {
  switch (stat1) {
    case stat::attack:return attack;
    case stat::defend:return defend;
    case stat::speed:return speed;
    default:return 999999;
  }
}
int Player::get_ap() {
  return action_point;
}
status Player::get_status(int pos) {
  return status_list.at(static_cast<unsigned long>(pos)).first;
}
int Player::get_afflicted_turn(int pos) {
  return status_list.at(static_cast<unsigned long>(pos)).second;
}

bool Player::get_attacked() {
  return attacked;
}
void Player::reset_AP() {
  action_point = organial_AP;
}

std::vector<std::unique_ptr<Weapon>>& Player::get_Weapon_list() {
  return weapon_list;
}
//FIXME if there are any problem with weapon management, this is the problem
void Player::removeWeapon(unsigned long pos){
  auto & weapon = weapon_list.at(pos);
  stat stat_to_mod = weapon->get_increase_at();

  if(weapon->get_mod_type() == multiplication) {
    set_stat(stat_to_mod, (get_stat(stat_to_mod) * (weapon->get_mod_amount())) * -1);
  } else {
    set_stat(stat_to_mod, weapon->get_mod_amount() * -1);
  }

  weapon.release();
  weapon_list.erase(weapon_list.begin() + pos);
}

void modify (Player &player, std::unique_ptr<Weapon> &weapon) {
  stat stat_to_mod = weapon->get_increase_at();
  int mod_amount = weapon->get_mod_amount();

  switch(weapon->get_mod_type()) {
    case multiplication :
      player.set_stat(stat_to_mod, player.get_stat(stat_to_mod) * mod_amount);
      break;
    default:
      player.set_stat(stat_to_mod, mod_amount);
      break;
  }
};
void Player::replaceWeapon(std::unique_ptr<Weapon> &&weapon, unsigned long pos){

  switch (weapon->get_weapon_order()) {
    case Primary:
      removeWeapon(0);
      modify(*this, weapon);
      weapon_list.insert(weapon_list.begin() + 0, std::move(weapon));
      break;
    case Secondary:
      removeWeapon(1);
      modify(*this, weapon);
      weapon_list.insert(weapon_list.begin() + 1, std::move(weapon));
      break;
    default:
      removeWeapon(pos);
      weapon_list.insert(weapon_list.begin() + pos, std::move(weapon));
      break;
  }
}

void Player::print_player_stat(int i) {
  switch (i) {
    case 0:
      std::cout << "Player    ";
      print_player_affliction();
      break;
    case 1:
      std::cout << "Current " << color_magenta << "Hit Point" << color_normal << ": ";
      std::cout << std::setw(16) << std::left;
      std::cout << hp;
      break;
    case 2:
      std::cout << color_red << "Base Attack" << color_normal << ": ";
      std::cout << std::setw(22) << std::left;
      std::cout << attack;
      break;
    case 3:
      std::cout << color_blue << "Base Defend" << color_normal << ": ";
      std::cout << std::setw(22) << std::left;
      std::cout << defend;
      break;
    case 4:
      std::cout << color_green << "Base Speed" << color_normal << ":  ";
      std::cout << std::setw(22) << std::left;
      std::cout << speed;
      break;
    default:
      std::cout << "Default for Player Stat" << std::endl;
      break;
  }
}
void Player::print_player_affliction() {
  for (std::pair<status, int> &stat_list : get_status_list()) {
    switch (stat_list.first) {
      case bleed:
        std::cout << color_red << 'B' << stat_list.second << ' ' << color_normal;
        break;
      case poison:
        std::cout << color_green << 'P' << stat_list.second << ' ' << color_normal;
        break;
      default:
        std::cout << "Error in status_list for Player" << std::endl;
        exit(0);
        break;
    }
  }
  std::cout << std::setw(static_cast<int>(25 - get_status_list().size() * 3)) << '|';
}
void Player::print_basic_head(int i) {
  switch (i) {
    case 0:
      std::cout << std::setw(23) << std::left;
      std::cout << "      ~ ~ ~ ~ ~ ";
      break;
    case 1:
      std::cout << std::setw(23) << std::left;
      std::cout << "    /           \\";
      break;
    case 2:
      std::cout << std::setw(23) << std::left;
      std::cout << "  /               \\";
      break;
    case 3:
      std::cout << std::setw(23) << std::left;
      std::cout << " |                 |";
      break;
    case 4:
      std::cout << std::setw(23) << std::left;
      std::cout << "(|                 |)";
      break;
    default:
      std::cout << "Default for basic head" << std::endl;
      break;
  }
}

void Player::print_weapons(int i) {
  switch (i) {
    case 0:
      std::cout << "Primary Weapon  : ";
      std::cout << weapon_list.at(0)->get_name();
      break;
    case 1:
      std::cout << weapon_list.at(0)->description();
      break;
    case 2:
      break;
    case 3:
      std::cout << "Secondary Weapon: ";
      std::cout << weapon_list.at(1)->get_name();
      break;
    case 4:
      std::cout << weapon_list.at(1)->description();
      break;
    default:
      std::cout << "Default for weapons" << std::endl;
      break;
  }
}
