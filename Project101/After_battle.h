//
// Created by Raymond Chan on 3/30/18.
//

#ifndef PROJECT101_AFTER_BATTLE_H
#define PROJECT101_AFTER_BATTLE_H

#include "enum_only.h"

class Player;
class Spawn_group;

void random_gain(Player& player);
void check_reward(Player& player, int level, int wave);
void improve_after_slaining(Player &player, stat stat1);


#endif //PROJECT101_AFTER_BATTLE_H
