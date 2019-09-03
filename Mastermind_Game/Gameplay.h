//
// Created by Raymond Chan on 9/2/19.
//

#ifndef MASTERMIND_GAME_GAMEPLAY_H
#define MASTERMIND_GAME_GAMEPLAY_H
#include "Utility.h"

// Take input
  Color_code user_input();

// Check player input vs master_code
  std::string compare(Color_code player_code, Color_code master_code);

#endif //MASTERMIND_GAME_GAMEPLAY_H
