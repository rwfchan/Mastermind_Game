#include <iostream>
#include "Unity.h"
#include "Spawn_group.h"
#include "After_battle.h"
#include "moves.h"
#include "Player.h"

int main() {
  print_beginning();
  pre_scene_next_scene();

  Player player("");

  srand(static_cast<unsigned int>(time(nullptr)));

  print_Level_1();

  for(int i = 1; i <= 10; i++) {

    std::cout << std::endl;
    std::cout << "------------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "wave " << i << std::endl;

    Spawn_group waves;
    waves.level_1_make_group(i);


    do {
      print_moves(player, waves, 1);
    } while (waves.get_group_size() > 0);

    //TODO add more rules for finishing a wave
    //After the end of a wave, the player might get reward
    //Rules: Player will always get random stat gain after each battle
    //  Level 1:
    //    Wave 1: giving a shield, and give the player option to defend
    //    Wave 5: Fight a champion, get a better weapon
    //      In fact, after every battle with champion, player can get a chance to switch weapon

    //TODO add in level systems; there is only one level now
    check_reward(player, 1, i);
  }


  std::cout << "Congratration! You cleared all waves" << std::endl;

  return 0;
}
