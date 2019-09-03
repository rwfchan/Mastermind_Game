//
// Created by Raymond Chan on 9/1/19.
//

#ifndef MASTERMIND_GAME_COLORS_H
#define MASTERMIND_GAME_COLORS_H
#include <iostream>
#include <vector>

// Add color to text
const static char color_red[] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
const static char color_green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
const static char color_tan[] = { 0x1b, '[', '1', ';', '3', '3', 'm', 0 };
const static char color_blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
const static char color_magenta[] = { 0x1b, '[', '1', ';', '3', '5', 'm', 0 };
const static char color_cyan[] = { 0x1b, '[', '1', ';', '3', '6', 'm', 0 };
const static char color_gray[] = { 0x1b, '[', '1', ';', '3', '7', 'm', 0 };
const static char color_black[] = { 0x1b, '[', '1', ';', '3', '8', 'm', 0 };
const static char color_normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };

class Color_code {
 public:

  // Use enum to make coding less confusing
  enum Colors { red = 0, cyan = 1, yellow = 2, green = 3, blue = 4, purple = 5 };

  // Shortcut printing out the code
  friend std::ostream &operator<<(std::ostream &os, const Color_code &code) {

    for (int color : code.color_code) {
      switch (color) {
        case red: std::cout << color_red<<"Red "<<color_normal;
          break;
        case cyan: std::cout << color_cyan<<"Cyan "<<color_normal;
          break;
        case yellow: std::cout << color_tan<<"Yellow "<<color_normal;
          break;
        case green: std::cout << color_green<<"Green "<<color_normal;
          break;
        case blue: std::cout << color_blue<<"Blue "<<color_normal;
          break;
        case purple: std::cout << color_magenta<<"Purple "<<color_normal;
          break;
        default:std::cout << "Color code value is not valid" << std::endl;
          exit(0);
      }
    }
    return os;
  }

  // Initialize code at random
  Color_code();

  // Get code from user
  explicit Color_code(const std::vector<char> &inputs);

  // Overload [] for easy comparison of two codes
  int operator [](short pos);

  // Getting the code's size
  unsigned short size();

  // Erasing an element from the code
  void erase(short pos);

 private:
  std::vector<int> color_code;
};


#endif //MASTERMIND_GAME_COLORS_H
