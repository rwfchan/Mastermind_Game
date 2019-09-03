//
// Created by Raymond Chan on 8/20/18.
//

#include "Meat_Tenderizer.h"
#include "Monsters.h"

Meat_Tenderizer::Meat_Tenderizer() : Weapon("Meat Tenderizer", Sword, Primary, 0, addition, attack, -10, nothing, bleed) {}

std::string Meat_Tenderizer::description() const {
  return "      Base Attack is not as destructive, but you can make APPROIATE TARGET bleed!";
}
void Meat_Tenderizer::printing_weapon(int i) const{
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
      std::cout << " <   <    >   >";
      break;
    case 3:
      std::cout << std::setw(20) << std::left;
      std::cout << " <___<____>___>";
      break;
    case 4:
      std::cout << std::setw(20) << std::left;
      std::cout << "       | |      ";
      break;
    default:
      std::cout << "Default for Meat_Tenderizer" << std::endl;
      break;
  }
}

void Meat_Tenderizer::special_attack(std::unique_ptr<Monsters>& monster) {
  if(monster->get_name() == "Skeleton") {
    return;
  }
  int turn = (rand() % 3) + 3;
  monster->add_status(bleed, turn);
}
