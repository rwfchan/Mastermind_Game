//
// Created by Raymond Chan on 3/26/18.
//
#ifndef UNITY_H_
#define UNITY_H_

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "enum_only.h"

bool true_false_randomizer(unsigned int seed);
bool input_incorrect(int user_input = 99999, std::vector<int> vaild_inputs = {99999});
void press_enter();
void pre_scene_next_scene();

void print_beginning();
void print_Level_1();
void monster_spacing();

void monster_tag_color(stat stat, int position = 0);

const static char color_red[] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
const static char color_green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
const static char color_tan[] = { 0x1b, '[', '1', ';', '3', '3', 'm', 0 };
const static char color_blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
const static char color_magenta[] = { 0x1b, '[', '1', ';', '3', '5', 'm', 0 };
const static char color_cyan[] = { 0x1b, '[', '1', ';', '3', '6', 'm', 0 };
const static char color_gray[] = { 0x1b, '[', '1', ';', '3', '7', 'm', 0 };
const static char color_black[] = { 0x1b, '[', '1', ';', '3', '8', 'm', 0 };
const static char color_normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };

#endif  // UNITY_H_