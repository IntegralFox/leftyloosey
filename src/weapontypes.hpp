#include "weapon.hpp"

Weapon PAPERCLIP {"unfolded paperclip", 1, 0, 0};
Weapon PLANK {"hardy 2x4 plank", 10, 15, 5};
Weapon PIPE {"long narrow steel pipe", 15, 10, 3};
Weapon CROWBAR {"versatile crowbar Dr. F. used to have", 20, 20, 10};

Weapon* weapons[] {&PAPERCLIP, &PLANK, &PIPE, &CROWBAR};
