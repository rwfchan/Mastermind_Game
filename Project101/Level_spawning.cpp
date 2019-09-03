//
// Created by Raymond Chan on 8/20/18.
//

#include "Spawn_group.h"
#include "Punisher_boss.h"

void Spawn_group::get_info(int level) const {
  switch(level) {
    case 1:print_level_1_group();
      std::cout << std::endl;
      break;
    default:
      std::cout << "Something's wrong with printing monster level";
      break;
  }
}

void Spawn_group::print_level_1_group() const{
  int line_number = 9;
  int position = 1;

  for(int i = 0; i < line_number; i++) {
    for (const auto &monster : monsters_group) {
      monster->print_monster(i, position);
      position++;
    }

    if(i == 6)
      std::cout << std::endl;
    std::cout << std::endl;
  }
}

void Spawn_group::level_1_put_in_normal_monster(int *worthless_count, int *i) {
  switch (rand() % amount_of_monsters) {      //Decide which monster to add in
    case 0:
      addMonsters(std::make_unique<Skeleton>());
      break;
    case 1:
      addMonsters(std::make_unique<Imp>());
      break;
    case 2:
      if (*worthless_count == group_size - 1) {   //if all but one monsters are worthless soul, than reroll
        (*i)--;
        return;
      } else {
        addMonsters(std::make_unique<worthless_soul>());
        (*worthless_count)++;
        break;
      }
    default:std::cout << ' ' << std::endl;
      std::cout << "Something's wrong with random monster generation" << std::endl;
      i--;
      break;
  }
}
void Spawn_group::Level_1_normal_spawn(int group_size) {
  //Each position have 50/50 chance to have either monster or nothing
  //There will always be 4 monsters in a monster group

  int max_group = 4;
  int worthless_count = 0;

  int void_needed = 4 - group_size;
  int monster_needed = 0;

  for(int i = 0; i < max_group; i++) {
    if(void_needed) {                               //only need to decide for void if we still need to add void
      if(rand() % 2) {                              //if true, add void
        addMonsters(std::make_unique<void_monster>());
        void_needed--;
      } else {                                      //If roll to add monster, check to see if monster_needed != group_size
        if(monster_needed != group_size) {
          level_1_put_in_normal_monster(&worthless_count, &i);
          monster_needed++;
        }
      }
    } else {                                          //If no more need for void, then we must need to add monster
      level_1_put_in_normal_monster(&worthless_count, &i);
    }
  }
}

void Spawn_group::level_1_punisher_formation() {
  //The spawn should have
  //  soul on spot 1, punisher on spot 2, soul on spot 3

  addMonsters(std::make_unique<worthless_soul>());
  addMonsters(std::make_unique<Punisher_boss>());
  addMonsters(std::make_unique<worthless_soul>());
}

void Spawn_group::level_1_wave_1() {
  //Each position have 50/50 chance to have either monster or nothing
  //There will always be 4 monsters in a monster group

  int max_group = 4;
  int worthless_count = 0;

  int void_needed = 4 - group_size;
  int monster_needed = 0;

  for(int i = 0; i < max_group; i++) {
    if(void_needed) {                               //only need to decide for void if we still need to add void
      if(rand() % 2) {                              //if true, add void
        addMonsters(std::make_unique<void_monster>());
        void_needed--;
      } else {                                      //If roll to add monster, check to see if monster_needed != group_size
        if(monster_needed != group_size) {
          if(!i) {
            level_1_put_in_normal_monster(&worthless_count, &i); //Decide which monster to add in
          } else {
            if(!worthless_count) {
              addMonsters(std::make_unique<worthless_soul>());
              worthless_count++;
            } else {
              amount_of_monsters--;
              level_1_put_in_normal_monster(&worthless_count, &i); //Decide which monster to add in
              amount_of_monsters++;
            }
          }
          monster_needed++;
        }
      }
    } else {                                          //If no more need for void, then we must need to add monster
      if(!i) {
        level_1_put_in_normal_monster(&worthless_count, &i); //Decide which monster to add in
      } else {
        if(!worthless_count) {
          addMonsters(std::make_unique<worthless_soul>());
          worthless_count++;
        } else {
          amount_of_monsters--;
          level_1_put_in_normal_monster(&worthless_count, &i); //Decide which monster to add in
          amount_of_monsters++;
        }
      }
    }
  }
}
void Spawn_group::level_1_wave_5() {
  //This will randomize which elite fight you will have

  int type_of_level_1_mid_boss = 1;

  //TODO add more different elite fight
  switch(rand() % type_of_level_1_mid_boss) {
    case 0:
    std::cout << "The Punisher is blocking your way!" << std::endl;
      level_1_punisher_formation();
      break;
    default:
    std::cout << "Something's wrong with mid_boss decision" << std::endl;
      break;
  }

}

void Spawn_group::level_1_make_group(int wave_number) {

  //TODO Rule for making group
  //on wave 1, there should only be 2 monsters
  //on wave 2 and after, there could be 2 - 4 monsters
  //Any waves have a chance to spawn worthless soul
  //  Except waves with factor of 5
  //  on the wave of factor of 5, there is 1 Greater monster
  //There will be at least one hostile monster on each spawned waves

  //randomize what monsters to put in
  //  The position will have 50/50 chance to have monster, or have nothing
  //For wave 1
  if(wave_number == 1) {
    group_size = 2;
    level_1_wave_1();
  } else if(wave_number == 5) {
    group_size = 3;
    level_1_wave_5();
  } else {
    //randomize the size of group
    group_size = rand() % 3 + 2;
    Level_1_normal_spawn(group_size);
  }
}
