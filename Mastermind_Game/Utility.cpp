//
// Created by Raymond Chan on 9/1/19.
//

#include <iomanip>
#include "Utility.h"

void rules() {
  std::cout << "===Rule===" << std::endl;
  std::cout << "-- Starts --" << std::endl;
  std::cout << "Game starts with a randomized Master Code" << std::endl;
  std::cout << "The Master Code is consist of 4 "<<color_black<<"colors"<<color_normal<<" ["
            <<color_red<<"Red" <<color_normal<<", "
            <<color_cyan<<"Cyan"<<color_normal<<", "
            <<color_tan<<"Yellow"<<color_normal<<", "
            <<color_green<<"Green"<<color_normal<<", "
            <<color_blue<<"Blue"<<color_normal<<", "
            <<color_magenta<<"Purple"<<color_normal<<"]"
            << std::endl;
  std::cout << std::endl;
  std::cout << "-- Players --" << std::endl;
  std::cout << "Players are to guess the "
            <<color_black<<"color"<<color_normal
            <<" combination of the Master Code" << std::endl;
  std::cout << "  by entering their guesses when prompted [R/O/Y/G/B/P]" << std::endl;
  std::cout << "Players will get a clue to the correctness of their guesses in the from of a bit string" << std::endl;
  std::cout << "    If Players guesses both the "
            <<color_black<<"color"<<color_normal
            <<" AND the "
            <<color_gray<<"position"<<color_normal
            <<" of ONE of the "
            <<color_black<<"color"<<color_normal
            <<" in Master Code, " << std::endl;
  std::cout << "      the bit string will present ONE 1 (If player get two right, bit string will have two 1s and so on" << std::endl;
  std::cout << "    If Players guesses only ONE of the "
            <<color_black<<"color"<<color_normal
            << " correctly" << std::endl;
  std::cout << "      the bit string will present ONE 0 (If player get two right, bit string will have two 0s and so on" << std::endl;
  std::cout << "    If Players guesses nothing correctly, the phrase 'No guesses are correct' will be prompted" << std::endl;
  std::cout << "Players will be given 10 chances to guess" << std::endl;
  std::cout << "Players lose the game if they are unable to guess the Master Code by the 10th try" << std::endl;
  std::cout << std::endl;
  std::cout << "-- Example --" << std::endl;
  std::cout << "Let's say Master Code = ["
            <<color_red<<"Red" <<color_normal<<", "
            <<color_red<<"Red"<<color_normal<<", "
            <<color_blue<<"Blue"<<color_normal<<", "
            <<color_magenta<<"Purple"<<color_normal<<"]"
            << std::endl;
  std::cout << "If Player guesses = ["
            <<color_tan<<"Yellow" <<color_normal<<", "
            <<color_tan<<"Yellow"<<color_normal<<", "
            <<color_green<<"Green"<<color_normal<<", "
            <<color_cyan<<"Cyan"<<color_normal<<"], bit string will be empty"
            << std::endl;
  std::cout << "If Player guesses = ["
            <<color_tan<<"Yellow" <<color_normal<<", "
            <<color_tan<<"Yellow"<<color_normal<<", "
            <<color_red<<"Red"<<color_normal<<", "
            <<color_cyan<<"Cyan"<<color_normal<<"], bit string will be = '0' "
            << std::endl;
  std::cout << "  because Red is in Master Code but not guessed in the correctly "
            <<color_gray<<"position"<<color_normal
            << std::endl;
  std::cout << "If Player guesses = ["
            <<color_red<<"Red" <<color_normal<<", "
            <<color_tan<<"Yellow"<<color_normal<<", "
            <<color_red<<"Red"<<color_normal<<", "
            <<color_cyan<<"Cyan"<<color_normal<<"], bit string will be = '10'"
            << std::endl;
  std::cout << "  because one of the Red was guessed correctly in "
            <<color_gray<<"position"<<color_normal
            <<", but the other red is only in Master Code and not in the correct "
            <<color_gray<<"position"<<color_normal
            << std::endl;
  std::cout << "Players should soon realize that bit string like '1110' does not exist, " << std::endl;
  std::cout << "  since if three "
            <<color_black<<"colors"<<color_normal
            <<" are guessed correctly in both "
            <<color_gray<<"position"<<color_normal
            <<" and existence, " << std::endl;
  std::cout << "  then the fourth "
            <<color_black<<"color"<<color_normal
            <<" must be in the correct "
            <<color_gray<<"position"<<color_normal
            <<" also" << std::endl;
  std::cout << "The key to this game is deduction. Good Luck!" << std::endl;
  for (int i = 0; i < 8; i++) {std::cout << std::endl;}
  std::cout << "Press [Enter] to Start Game" << std::endl;
  press_enter();
}

void begin() {
  std::cout << "Welcome to Mastermind!" << std::endl;
  std::cout << "Do you know how to play Mastermind? (y/n)" << std::endl;

  char input;
  std::cin >> input;

  if (std::cin.fail() || std::cin.get() != '\n') {  // if user did not input exactly ONE character, prompt the rule
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "I assume this is your first time, so let's go over the rule" << std::endl;
    rules();
    return;
  }

  if (toupper(input) == 'Y') {
    std::cout << "Then let's start the game!" << std::endl;
  } else if (toupper(input) == 'N') {
    rules();
  } else {
    std::cin.clear();
    std::cout << "I assume this is your first time, so let's go over the rule" << std::endl;
    rules();
  }
}


bool check_not_valid (char user_input) {
  std::vector<char> vaild_inputs = {'R', 'C', 'Y', 'G', 'B', 'P'/*,
                                    'r', 'c', 'y', 'g', 'b', 'p'*/};

  for (char inputs : vaild_inputs) {
    if (toupper(user_input) == inputs) {
      return false;
    }
  }

  return true;
}
bool check_input(char user_input) {
  return !(isnumber(user_input) || check_not_valid(user_input));
}

void press_enter() {
  if(std::cin.get() != '\n') {
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "How hard it is to press Enter?" << std::endl;
  }
}

