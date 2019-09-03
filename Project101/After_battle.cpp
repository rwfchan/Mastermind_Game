//
// Created by Raymond Chan on 3/30/18.
//

#include "After_battle.h"
#include "Spawn_group.h"
#include "Player.h"
#include "Unity.h"

void improve_after_slaining(Player &player, stat stat1) {
  auto improvement = static_cast<int>(player.get_stat(stat1) * 0.1);

  if(improvement <= 0) {
    improvement = 1;
  }

  player.set_stat(stat1, improvement);
}

void random_gain(Player& player) {

  srand(static_cast<unsigned int>(time(nullptr)));

  int gain_stat = rand() % (amount * 2);

  switch (gain_stat) {
    case 0:
      //player.set_hp(static_cast<int>(player.get_hp() * 0.1));
    //std::cout << "You seems to heal extra hp" << std::endl;
      break;
    case 1:
      improve_after_slaining(player, attack);
      std::cout << "You seems to have some improvement on your " << color_red << "attack" << color_normal << std::endl;
      break;
    case 2:
      improve_after_slaining(player, defend);
      std::cout << "You seems to have some improvement on your " << color_blue << "defend" << color_normal << std::endl;
      break;
    case 3:
      improve_after_slaining(player, speed);
      std::cout << "You seems to have some improvement on your " << color_green << "speed" << color_normal << std::endl;
      break;
    default:
      break;
  }
}

void weapon_randomizer() {
  int weapon_to_choose = 1;

  int weapon_id = rand() % weapon_to_choose + 2;

}

void check_reward(Player& player, int level, int wave) {
  //For the level 1 :
  //  After wave 1, Player get shield and can defend
  //  Wave 5 have a champion
  //    After each fight with champion player can get better weapon

  //TODO add more level
  switch (level) {
    case 1:
      switch (wave) {
        case 1:
          player.replaceWeapon(std::make_unique<Bashing_Shield>());
          std::cout << "You found a weapon : " << player.get_Weapon_list().at(1)->get_name() << std::endl;
          player.changing_AP(true);
          std::cout << std::endl;
          std::cout << "Now you can choose to " << color_blue << " defend to block " << color_normal << " some of the damage from incoming attack!" << std::endl;
          std::cout << std::endl;

          std::cout << std::setw(100) << std::setfill('-') << ' ' << std::endl;
          std::cout << "How defend works: " << std::endl;
          std::cout << "  You can only block damage from monsters after your turn" << std::endl;
          std::cout << "  Once all monsters had been attacked or slained, incoming damage afterward will come at you in full force!" << std::endl;
          std::cout << "  Oh! And blocking twice can blocks even more incoming damage" << std::endl;
          std::cout << std::setw(100) << std::setfill('-') << ' ' << std::endl;
          std::cout << std::endl;
          break;
        case 5:
        std::cout << "You found a weapon : ";
        default:
          std::cout << "Nothing dropped from the monsters";
          break;
      }
      break;
    default:
      std::cout << "Check Reward Default" << std::endl;
      break;
  }
}