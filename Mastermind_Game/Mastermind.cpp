#include <iostream>
#include "Gameplay.h"
#include <ctime>

int main() {

  srand(static_cast<unsigned int>(time(nullptr)));

  begin();

  // Start Game with an array of 4 "colors"
  // Player guesses the color and position of the array
  //    if the player guesses the position AND color correctly, they are rewarded a 1
  //    if the player guesses only the color correctly, they are rewarded a 0
  //    otherwise, the player get nothing

  // Generate a vector of color as master code for player to guess
  const Color_code master_code;
  std::cout << "Master Code generated" << std::endl;
  std::cout << std::endl;

  // Player have 10 guesses
  for (int i = 0; i < 10; i++) {

    // Initialize player's guess
    std::cout << "What are your 4 guesses? ("
              <<color_red<<"R"<<color_normal <<"/"
              <<color_cyan<<"C"<<color_normal<<"/"
              <<color_tan<<"Y"<<color_normal<<"/"
              <<color_green<<"G"<<color_normal<<"/"
              <<color_blue<<"B"<<color_normal<<"/"
              <<color_magenta<<"P"<<color_normal<<")"
              << std::endl;
    Color_code guess = user_input();

    std::cout << guess << std::endl;

    // Compare player's guess with master_code
    if (compare(guess, master_code) != "1111") std::cout << "Another guess? (" << 10 - i << " tries remaining)" <<  std::endl;
    else {
      std::cout << "You guessed it! The master code is " << master_code << std::endl;
      break;
    }
  }

  // Game Over
  std::cout << "All guesses have been used up" << std::endl;
  std::cout << "Pay closer attention next time!" << std::endl;
}