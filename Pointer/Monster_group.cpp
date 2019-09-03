//
// Created by Raymond Chan on 2/23/18.
//

#include "Monster_group.h"

//When created a instance of travel_group, a vector of Characters pointers also created
Monster_group::Monster_group(){}

//The move here change the pointers from the independent vector to a vector of pointers that belong to Travel group
//This is basically how the content of the independent vector get "casted" into Travel_group
Monster_group::Monster_group(std::vector<std::unique_ptr<Monsters>> &&monsters) : monsters(std::move(monsters)){}

//Motify the reference of vector of Characters
void Monster_group::addMonsters(std::unique_ptr<Monsters> &&monster){

  //The std::move change the unique pointer that's pointing at some space into other pointer that's pointing to same space
  monsters.push_back(std::move(monster));
}

/*
std::vector<Warrior_class*> Travel_group::getWarrior_class() {
  std::vector<Warrior_class*> warriors;
  for(const auto& character : characters) {
    Warrior_class* warrior = dynamic_cast<Warrior_class*>(character.get());
    if(warrior) {
      warriors.push_back(warrior);
    }
  }

  return warriors;
}

std::vector<Wizard_class*> Travel_group::getWizard_class() {
  std::vector<Wizard_class*> wizards;
  for(const auto& character : characters) {
    Wizard_class* wizard = dynamic_cast<Wizard_class*>(character.get());
    if(wizard) {
      wizards.push_back(wizard);
    }
  }

  return wizards;
}*/

//The Travel_group get to get_info for each individual characters
//This function will pick which get_info to run depends on what class pointer was called in main.cpp

//Because Character class contain get_info, keyword character can be passed and name can be set via pointer
//Basically, calliing get_info in Travel_group can call get_info from respective class that inherite that function
void Monster_group::get_info() const {
  for(const auto &monster : monsters) {
    monster->get_info();
  }
}

void Monster_group::hp_down(const std::string &name) const {
  for(auto &monster : monsters) {
    if(monster->getName() == name) {
      monster->hp_down();
    }
  }
}

