//
// Created by Raymond Chan on 9/2/19.
//

#include <sstream>
#include "Gameplay.h"

Color_code user_input () {
  std::vector<char> inputs;
  char input;

  do {
    for (int i = 0; i < 4; i++) {  // Only needs to take 4 elements for the code
      std::cin >> input;

      if (check_input(input)) {  // Check if the input is valid
        inputs.push_back(static_cast<char &&>(toupper(input)));
      } else {  // If input is not valid, reject input and ask for another one
        std::cout << "Invaild command" << std::endl;
        std::cout << "Please enter a series of 4 colors ("
              <<color_red<<"R"<<color_normal <<"/"
              <<color_cyan<<"C"<<color_normal<<"/"
              <<color_tan<<"Y"<<color_normal<<"/"
              <<color_green<<"G"<<color_normal<<"/"
              <<color_blue<<"B"<<color_normal<<"/"
              <<color_magenta<<"P"<<color_normal<<")" 
	      << std::endl;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        inputs.clear();
        i = -1;
        continue;
      }
    }

    // If the user's input does not end, reject input
    // (even if the rest are all spaces)
    if (std::cin.get() != '\n') {
      std::cout << "Invaild command" << std::endl;
      std::cout << "Please enter a series of 4 colors ("
              <<color_red<<"R"<<color_normal <<"/"
              <<color_cyan<<"C"<<color_normal<<"/"
              <<color_tan<<"Y"<<color_normal<<"/"
              <<color_green<<"G"<<color_normal<<"/"
              <<color_blue<<"B"<<color_normal<<"/"
              <<color_magenta<<"P"<<color_normal<<")" 
	      << std::endl;
      std::cin.clear();
      std::cin.ignore(INT_MAX, '\n');
      inputs.clear();
      continue;
    }
    break;
  } while (true);

  Color_code output(inputs);
  return output;
};

std::string compare(Color_code player_code, Color_code master_code) {
  std::stringstream compare;

  // For checking '1's
  // If there are elements in code that have same color AND position, give players a '1' and pop that code out
  for (short i = 3; i >= 0; i--) {  // Looping through the code in reverse make deleting elements easier
    if (player_code[i] == master_code[i]) {
      compare << '1';
      player_code.erase(i);
      master_code.erase(i);
    }
  }

  // For checking '0's
  // We should now get a code with no position matched colors, thus we are only checking for same colors, not position
  // If the colors are the same, give player a '0', and only needs to pop the master_code
  for (short i = static_cast<unsigned short>(player_code.size() - 1); i >= 0; i--) {  // For player_code, it doesn't matter which way to loop through first
    for (short j = static_cast<unsigned short>(master_code.size() - 1); j >= 0; j--) {  // However, it does matter for master_code
      if (player_code[i] == master_code[j]) {
        compare << '0';
        master_code.erase(j);
        break;  // If matched color is found, move on to the next code
      }
    }
  }

  // Print out appropiate clue base on player's answer
  if (compare.str().empty()) { std::cout << "No guesses are correct" << std::endl; }
  else { std::cout << "Here is your clue: " << compare.str() << std::endl; }

  return compare.str();
};

