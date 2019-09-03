//
// Created by Raymond Chan on 8/10/18.
//

#include <iostream>
#include <iomanip>
#include "Chopping_Sword.h"

Chopping_Sword::Chopping_Sword() : Weapon("Chopping Sword", Sword, Primary, 1){}

std::string Chopping_Sword::description() const {
  return "      Deal damage with the most Basic Attack";
}
void Chopping_Sword::printing_weapon(int i) const{
  switch (i) {
    case 0:
      std::cout << std::setw(20) << std::left;
      std::cout << "        / \\";
      break;
    case 1:
      std::cout << std::setw(20) << std::left;
      std::cout << "       /   |";
      break;
    case 2:
      std::cout << std::setw(20) << std::left;
      std::cout << "      /    |";
      break;
    case 3:
      std::cout << std::setw(20) << std::left;
      std::cout << "     /    /";
      break;
    case 4:
      std::cout << std::setw(20) << std::left;
      std::cout << "    /    /";
      break;
    default:
      std::cout << "Default for Chopping Sword" << std::endl;
      break;
  }

}

void Chopping_Sword::special_attack(std::unique_ptr<Monsters>& monster) {}
