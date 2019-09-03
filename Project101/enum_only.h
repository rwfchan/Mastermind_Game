//
// Created by Raymond Chan on 3/29/18.
//

#ifndef PROJECT101_ENUM_ONLY_H
#define PROJECT101_ENUM_ONLY_H

enum stat {health_point, attack, defend, speed, amount = 3, nothing};

enum status {bleed, poison, none};

enum monster_type {hostile, nonhostile, tag_empty, elite, boss};

enum weapon_type {Sword, Shield, type_empty};
enum weapon_order {Primary, Secondary, order_empty};
enum weapon_mod_type {addition, multiplication, null};


#endif //PROJECT101_ENUM_ONLY_H
