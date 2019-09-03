//
// Created by Raymond Chan on 8/10/18.
//


#include <iostream>
#include <iomanip>
#include "Empty_weapon.h"

Empty_weapon::Empty_weapon() : Weapon("None", type_empty, order_empty, 0){}

std::string Empty_weapon::description() const {
  return " ";
}

void Empty_weapon::printing_weapon(int i) const {
  switch (i) {
    case 0:
      std::cout << std::setw(20) << std::left;
      std::cout << ' ';
      break;
    case 1:
      std::cout << std::setw(20) << std::left;
      std::cout << ' ';
      break;
    case 2:
      std::cout << std::setw(20) << std::left;
      std::cout << ' ';
      break;
    case 3:
      std::cout << std::setw(20) << std::left;
      std::cout << ' ';
      break;
    case 4:
      std::cout << std::setw(20) << std::left;
      std::cout << ' ';
      break;
    default:
      std::cout << "Default for Empty_weapon" << std::endl;
      break;
  }
}

void Empty_weapon::special_attack(std::unique_ptr<Monsters>& monster) {}


