#ifndef WEAPON_TYPES_HEADER
#define WEAPON_TYPES_HEADER

#include "weapon.hpp"

Weapon PAPERCLIP {"thin, unfolded paperclip", 1, 0, 0};
Weapon PLANK {"hardy 2x4 plank", 3, 15, 5};
Weapon PIPE {"long narrow steel pipe", 5, 10, 3};
Weapon CROWBAR {"versatile crowbar Dr. F. used to have", 7, 20, 10};

const int numWeapons = 4;

Weapon* weapons[numWeapons] {&PAPERCLIP, &PLANK, &PIPE, &CROWBAR};

#endif
