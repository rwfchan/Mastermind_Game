//
// Created by Raymond Chan on 3/26/18.
//

#include "Unity.h"
#include <ctime>
#include <cstdlib>
#include <memory>

bool true_false_randomizer(unsigned int seed) {
  srand(seed);
  return rand() % 2 == 0;
};
bool input_incorrect(int user_input, std::vector<int> vaild_inputs) {
  if(std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "Invaild command" << std::endl;

    return true;
  }
  if(user_input == 99999 && vaild_inputs.at(0) == 99999) {
    return false;
  }
  for(auto vaild_input : vaild_inputs) {
    if(vaild_input == user_input) {
      return false;
    }
  }

  std::cout << "Invaild command" << std::endl;
  return true;
}
void press_enter() {
  std::cout << std::right << std::setw(100) << "Press Enter to continute" << std::endl;

  if(std::cin.get() != '\n') {
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "How hard it is to press Enter?" << std::endl;
  }
}
void monster_spacing() {
  std::cout << std::right << std::setfill(' ') << std::setw(7)  << '|';
}
void pre_scene_next_scene() {
  for(int i = 0; i < 30; i++) {
    std::cout << std::endl;
  }
}

void print_beginning() {
  //To change color, use system("color *background**foreground*")
  //  For example: system("color A1");

  //However, this compiler doesn't seems to like keyword system (deprecated? Don't use it anymore?)

  //So we will use ANSI escape code, from http://www.cplusplus.com/forum/beginner/1640/
  //Therefore, we will change color with strings
  //  In this case:
    //  change the 5th character
      //  '1' is red
      //  '2' is green
      //  '3' is tan
      //  '4' is blue
      //  '5' is magenta
      //  '6' is cyan
      //  '7' is gray
      //  any other numbers is black
      //  This is using 3/4 bit color
    //  change the 2nd character
      //  '0' is normal font
      //  '1' is bond
      //  '2' is faint
      //  '3' is italic
      //  '4' is underline
      //  (given 4th character is '3') '7' is highlight color, white word
      //  (given 4th character is '4') '7' is highlight black, color word
      // more can see SGR (Select Graphic Rendition) parameters on wiki

//  char red[] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
//  char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
//  char tan[] = { 0x1b, '[', '1', ';', '3', '3', 'm', 0 };
//  char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
//  char magenta[] = { 0x1b, '[', '1', ';', '3', '5', 'm', 0 };
//  char cyan[] = { 0x1b, '[', '1', ';', '3', '6', 'm', 0 };
//  char gray[] = { 0x1b, '[', '1', ';', '3', '7', 'm', 0 };
//  char black[] = { 0x1b, '[', '1', ';', '3', '8', 'm', 0 };
//
//
//  char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };
//
//  std::cout << black  << "color " << color1 << "color " << color2 << "color "
//            << color3 << "color " << color4 << "color " << color5 << "color "
//            << color6 << "color " << color7 << "color " << normal << std::endl;

  std::cout << "------------" << "From the Below" << "------------" << std::endl;
  std::cout << std::endl;
  std::cout << "--------" << "Press [Enter] to begin" << "--------" << std::endl;

  if(std::cin.get() != '\n') {
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "How hard it is to press Enter?" << std::endl;
  }
}
void print_Level_1() {
  std::cout << "LEVEL 1" << std::endl;
  std::cout << std::endl;
}

void monster_tag_color(stat stat, int position) {
  switch(stat) {
    case health_point:
    std::cout <<  color_magenta << " HP " << color_normal << ": ";
      break;
    case attack:
    std::cout << color_red << " Attack" << color_normal << " : ";
      break;
    case defend:
    std::cout << color_blue << " Defend" << color_normal << " : ";
      break;
    case speed:
    std::cout << color_green << " Speed" << color_normal << "  : ";
      break;
    default:
    std::cout << color_tan << position << "." << color_normal;
      break;

  }
}
