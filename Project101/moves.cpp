//
// Created by Raymond Chan on 3/29/18.
//

#include "moves.h"
#include "Unity.h"
#include "Player.h"
#include "Spawn_group.h"
#include "After_battle.h"

bool defend_too_high(Player& player, std::unique_ptr<Monsters>& monsters);
void nonhostile_count (Player& player, Spawn_group& waves);
void check_status_player(Player &player);
void check_status_monster(std::unique_ptr<Monsters>& monster);

void attack_target(int user_input, Player& player, Spawn_group& waves);
void attack_reset(Player& player, Spawn_group& waves);

std::vector<int> speed_calculation(Player& player, Spawn_group& waves);

void player_move(Player& player, Spawn_group& waves, int level);
void enemy_move(Player& player, std::unique_ptr<Monsters>& monster);


bool defend_too_high(Player& player, std::unique_ptr<Monsters>& monsters) {
  return player.get_stat(attack) <= monsters->get_stat(defend);
}
void nonhostile_count (Player& player, Spawn_group& waves) {
  int nonhostile_count = 0;
  for(const auto& monsters : waves.get_monsters_group()) {
    if(monsters->get_tag() == nonhostile) {
      nonhostile_count++;
    }
  }
  if(nonhostile_count == waves.get_group_size()) {
    attack_reset(player, waves);
    waves.clearMonsters();
  }
}
void check_status_player(Player &player) {
  auto &status_list = player.get_status_list();

  for(auto& status : status_list) {
    int turn = status.second;
    switch(status.first) {
      case bleed:
        if(turn) {
          status = std::make_pair(status.first, turn - 1);
          player.set_hp(-3);
          std::cout << "You " << color_red << "bleeded" << color_normal << " out " << color_magenta << "3 hp" << color_normal << std::endl;
            if(player.get_hp() <= 0) {
              std::cout << "You don't have enough blood to " << color_red << "bleed " << color_normal << " ..." << std::endl;
              std::cout << "You died" << std::endl;
              std::exit(0);
            }
        } else {
          player.remove_status(status);
          std::cout << "Your " << color_red << "bleeding " << color_normal << "stopped" << std::endl;
        }
        break;
      case poison:
        //TODO Add affect of poison
        std::cout << "You lose ?? health point due to the poison" << std::endl;
        break;
      default:
        std::cout << "Something's wrong with check_status_player switch function" << std::endl;
        break;
    }
  }
}
void check_status_monster(std::unique_ptr<Monsters>& monster) {
  auto status_list = monster->get_status_list();

  for(auto& status : status_list) {
    int turn = status.second;
    switch(status.first) {
      case bleed:
        if(turn) {
          status = std::make_pair(status.first, turn - 1);
          monster->set_hp(-5);
          std::cout << monster->get_name() << color_red << " bleeded" << color_normal << " out " << color_magenta << "5 hp" << color_normal << std::endl;
          if(monster->get_hp() <= 0) {
            std::cout << monster->get_name() << " bleed too much blood and died" << std::endl;
          }
        } else {
          monster->remove_status(status);
          std::cout << monster->get_name() << "stops "<< color_red << "bleeding " << color_normal << std::endl;
        }
        break;
      case poison:
        //TODO Add affect of poison
        std::cout << "You lose ?? health point due to the poison" << std::endl;
        break;
      default:
        std::cout << "Something's wrong with check_status_player switch function" << std::endl;
        break;
    }
  }

}

void attack_target(int user_input, Player& player, Spawn_group& waves) {
  for(int i = 0; i < 4; i++){
    if(i + 1 == user_input) {
      if(waves.get_monster(user_input - 1)->get_monster_id() == 99) {
        std::cout << "You missed your " << color_red << "attack" << color_normal << "!" << std::endl;
        std::cin.ignore(INT_MAX, '\n');
        return;
      }

      int damage_taking;

      //Check to see if monster have too high defend
      if(defend_too_high(player, waves.get_monster(i))) {
        damage_taking = 0;
      } else {
        damage_taking = player.get_stat(attack) - waves.get_monster(i)->get_stat(defend);
      }
      waves.get_monster(i)->set_hp(-1 * damage_taking);
      std::cout << "You dealt " << color_red << damage_taking << " damage" << color_normal
                << " to " << waves.get_monster(i)->get_name() << std::endl;

      //Check to see if player had slain the monster
      if(waves.get_monster(i)->get_hp() <= 0) {
        std::cout << "You slained " << waves.get_monster(i)->get_name() << std::endl;
        std::cout << "Because you slained " << waves.get_monster(i)->get_name()
                  << ", you healed "<< color_magenta << waves.get_monster(i)->get_hp_giving()
                  << " hp" << color_normal << std::endl;
        player.set_hp(waves.get_monster(i)->get_hp_giving());
        random_gain(player);

        waves.removeMonsters(waves.get_monster(i), i);
      }
    }
  }

  std::cin.ignore(INT_MAX, '\n');
}
void attack_reset(Player& player, Spawn_group& waves) {
  player.set_attacked(false);
  player.reset_AP();
  for(auto& monsters : waves.get_monsters_group()) {
    monsters->set_attacked(false);
  }
}

void defend_move(Player& player, int& defend_putted_up) {
  for(const auto& weapons : player.get_Weapon_list()) {
    if(weapons->get_weapon_type() == Shield) {
      std::cout << "You've decided to " << color_blue << "block" << color_normal << " some of the damage from incoming attack" << std::endl;
      defend_putted_up++;
      break;
    }
  }
  if(defend_putted_up == 0) {
    std::cout << "You don't have anything to " << color_blue << "block" << color_normal <<" with!" << std::endl;
  }
}

std::vector<int> speed_calculation(Player& player, Spawn_group& waves) {
  //determine speed. Make a list of monsters order by their speed
  //  First, compare each of the Monsters' speed to Player
  //  If Player's speed is then faster, Do player's move, else, do monster's move
  //  Speed should still be relative after player's move

  std::vector<int> speed_list;

  for(const auto &monsters_ptr : waves.get_monsters_group()) {
    speed_list.push_back(monsters_ptr->get_stat(speed));
  }
  speed_list.push_back(player.get_stat(speed));

  //Order the list of monsters by speed
  unsigned int j = 0;
  while(j != speed_list.size() - 1) {
    j = 0;
    for(unsigned int i = 0; i < speed_list.size() - 1; i++) {
      if (speed_list.at(i) < speed_list.at(i + 1)) {
        //swap
        int temp_speed = speed_list.at(i);
        speed_list.at(i) = speed_list.at(i + 1);
        speed_list.at(i + 1) = temp_speed;
      } else {
        j++;
      }
    }
  }

  return speed_list;
}

void player_move(Player& player, Spawn_group& waves, int level, int &defend_putted_up){
  int user_input;
  std::cout << "Your choice: " << std::endl;
  std::cout << color_red << "1. Attack" << color_normal << std::endl;
  std::cout << color_blue << "2. Defend" << color_normal << std::endl;

  //TODO Player can also do things other than attack (choice 1)
  std::vector<int> vaild_input = {1, 2};

  //check user input
  do{
    std::cin >> user_input;
  }while(input_incorrect(user_input, vaild_input));

  if (user_input == 1) {
    std::cout << "Enter the " << color_tan << "monster number" << color_normal << " next to the enemy you target" << std::endl;
    std::cout << "Enter '0' to go back" << std::endl;

    //check user input
    vaild_input.clear();

    vaild_input = {0, 1, 2, 3, 4};

    do {
      std::cin >> user_input;
    } while (input_incorrect(user_input, vaild_input));

    if(user_input == 0){
      player_move(player, waves, level, defend_putted_up);
      return;
    }

    attack_target(user_input, player, waves);

    vaild_input.clear();
  } else if (user_input == 2) {
    defend_move(player, defend_putted_up);

    vaild_input.clear();
  }

  press_enter();
  return;
}
void enemy_move(Player& player, std::unique_ptr<Monsters>& monster, int defend_putted_up){

  //Check to see if the monster is able to attack
  if(monster->get_tag() == nonhostile || monster->get_tag() == tag_empty) {
    monster->set_attacked(true);
    return;
  }

  int damage_dealt = 0;

  if(monster->get_apply_status()) {
    damage_dealt = monster->special_attack(player) - player.get_stat(defend) * defend_putted_up;
  } else {
    damage_dealt = monster->get_stat(attack) - player.get_stat(defend) * defend_putted_up;
  }

  if(damage_dealt < 0) {
    damage_dealt = 0;
    std::cout << "You "<< color_blue << "blocked " << color_normal << monster->get_name() << "'s attack!" << std::endl;
  } else {
    std::cout << monster->get_name() << " deals " << color_red << damage_dealt << " damage" << color_normal << " to you!" << std::endl;
  }

  player.set_hp(-1 * damage_dealt);
  monster->set_attacked(true);

  if(player.get_hp() <= 0) {
    std::cout << "You had been slain by " << monster->get_name() << std::endl;
    std::cout << "You died" << std::endl;
    std::exit(0);
  }
  return;
}

void print_moves(Player& player, Spawn_group& waves, int level) {
  waves.get_info(level);

  std::cout << std::endl;

  player.print_info();

  std::vector<int> speed_list = speed_calculation(player, waves);
  int defend_putted_up = 0;

  //Compare player's speed with speed_list
  //  if player is faster, player moves
  //  else, compare list with monsters group. All monsters with same speed will act;

  for(const auto& cur_speed : speed_list) {
    for(auto& monsters : waves.get_monsters_group()) {
      if(monsters->get_stat(speed) == cur_speed && !monsters->get_attacked()) {

        //Check to see if the monster have any status
        if(!monsters->get_status_list().empty()) {
          check_status_monster(monsters);
          if(monsters->get_hp() <= 0) {
            waves.removeMonsters(monsters);
            continue;
          }
        }

        enemy_move(player, monsters, defend_putted_up);
      }
    }
    if(player.get_stat(speed) == cur_speed && !player.get_attacked()) {
      std::cout << ' ' << std::endl;
      std::cout << "IT IS YOUR TURN" << std::endl;
      press_enter();
      pre_scene_next_scene();
      while(player.using_AP()) {

        std::cout << std::endl;
        waves.get_info(level);
        std::cout << std::endl;
        player.print_info();

        std::cout << "You have " << color_cyan << player.get_ap() + 1 << " action points" << color_normal << " remaining" << std::endl;

        player_move(player, waves, level, defend_putted_up);

        nonhostile_count(player, waves);

        if(!waves.get_group_size()) {
          attack_reset(player, waves);
          std::cout << "ALL MONSTERS IN THIS WAVE HAS BEEN SLAINED" << std::endl;
          pre_scene_next_scene();
          return;
        }
        pre_scene_next_scene();
      }
      player.set_attacked(true);
    }
  }

  attack_reset(player, waves);

  std::cout << "ALL MONSTERS HAD ATTACKED" << std::endl;

  if(!player.get_status_list().empty()) {
    std::cout << std::endl;
    check_status_player(player);
  }

  press_enter();
  pre_scene_next_scene();
}