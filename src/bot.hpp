#ifndef BOT
#define BOT

#include <string>
#include "weapontypes.hpp"

class Bot {
	std::string name;
	int level;
	int damage;
	int energy;
	Weapon* carriedWeapon;

public:
	Bot(std::string, int);
	int attack(Bot&);
	int damageWith(Weapon*);
};

#endif
