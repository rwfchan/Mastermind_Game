#include <memory>
#include "Monster_group.h"
#include "Monsters.h"
#include "Monster_A.h"
#include "Monster_B.h"

int main() {
  int player_input;

  Hero Player;

  Monster_group wave_1;

  //Syxtax : name, hp, attack, defend, speed
  wave_1.addMonsters(std::make_unique<Monster_A>("Skeleton A"));
  wave_1.addMonsters(std::make_unique<Monster_A>("Skeleton B"));
  wave_1.addMonsters(std::make_unique<Monster_A>("Skeleton C"));
  wave_1.addMonsters(std::make_unique<Monster_A1>("Tiny Sketeton A", 5, 10, 0, 30));

  while(true) {
    wave_1.get_info();

    std::cout << std::endl;

    std::cin >> player_input;

    switch (player_input){
      case 0:
        wave_1.hp_down("Skeleton A");
        break;
      case 1:
        wave_1.hp_down("Skeleton B");
        break;
      case 2:
        wave_1.hp_down("Skeleton C");
        break;
      case 3:
        wave_1.hp_down("Tiny Sketeton A");
        break;
      default:break;
      }
  }

  std::cout << std::endl;



  return 0;
}