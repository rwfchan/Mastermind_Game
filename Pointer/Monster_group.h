//
// Created by Raymond Chan on 2/23/18.
//

#ifndef POINTER_TRAVEL_GROUP_H
#define POINTER_TRAVEL_GROUP_H

#include <memory>
#include <vector>
#include "Monsters.h"
#include "Monster_A.h"
#include "Monster_B.h"

class Monster_group {
 public:
  Monster_group();

  //This is to "cast" a vector of unique_pointers to Characters into a Travel_group
  //The double reference is for:
  //  1.the unique pointer since unique pointer can only be pass by reference
  //  2.Reference for the vector so it is not just a copy
  Monster_group(std::vector<std::unique_ptr<Monsters>> && monsters);


  void addMonsters(std::unique_ptr<Monsters> && monster);
/*
  std::vector<Warrior_class*> getWarrior_class();
  std::vector<Wizard_class*> getWizard_class();
*/


  void get_info() const;
  void hp_down(const std::string& name) const;

 protected:

  //Travel_group is in fact a vector of unique_pointers to the class Character
  std::vector<std::unique_ptr<Monsters>> monsters;
};


#endif //POINTER_TRAVEL_GROUP_H
