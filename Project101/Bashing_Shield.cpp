//
// Created by Raymond Chan on 8/10/18.
//

#include <iostream>
#include <iomanip>
#include "Bashing_Shield.h"

Bashing_Shield::Bashing_Shield() : Weapon("Bashing_Shield", Shield, Secondary, 0, addition, defend, 15) {}

std::string Bashing_Shield::description() const {
  return "      Reduce damage equals to Base Defend, or bash the target with your Base Attack!";
}

void Bashing_Shield::printing_weapon(int i) const{
  switch (i) {
    case 0:
      std::cout << std::setw(20) << std::left;
      std::cout << ' ';
      break;
    case 1:
      std::cout << std::setw(20) << std::left;
      std::cout << "  ____________";
      break;
    case 2:
      std::cout << std::setw(20) << std::left;
      std::cout << " / __________ \\";
      break;
    case 3:
      std::cout << std::setw(20) << std::left;
      std::cout << "| |----------| |";
      break;
    case 4:
      std::cout << std::setw(20) << std::left;
      std::cout << "| |----------| |";
      break;
    default:
      std::cout << "Default for Bashing Shield" << std::endl;
      break;
  }
}

void Bashing_Shield::special_attack(std::unique_ptr<Monsters>& monster) {}

