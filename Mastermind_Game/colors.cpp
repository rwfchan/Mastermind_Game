//
// Created by Raymond Chan on 9/2/19.
//

#include "colors.h"

Color_code::Color_code() : color_code(4) {
  for (int& color : color_code) {
    color = rand()%6;
  }
}
Color_code::Color_code(const std::vector<char> &inputs) {
  for (char input : inputs) {
    switch (input) {
      case 'R': color_code.push_back(red); break;
      case 'C': color_code.push_back(cyan); break;
      case 'Y': color_code.push_back(yellow); break;
      case 'G': color_code.push_back(green); break;
      case 'B': color_code.push_back(blue); break;
      case 'P': color_code.push_back(purple); break;

      default:
        std::cout << "Color code value is not valid" << std::endl;
        exit(0);
    }
  }
}

int Color_code::operator[](short pos) {
  return color_code.at(static_cast<unsigned short>(pos));
};

unsigned short Color_code::size() {
  return static_cast<unsigned short>(color_code.size());
}

void Color_code::erase(short pos) {
  for (unsigned short i = static_cast<unsigned short>(pos); i < color_code.size() - 1; i++) {  // code needs to be replaced by the next code, except the last slot of the code
    color_code.at(i) = color_code.at(i + 1);
  }
  color_code.pop_back();  // the last slot should be pop_back
}

