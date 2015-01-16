#ifndef BOT_HEADER
#define BOT_HEADER

#include <string>
#include "weapon.hpp"

class Bot {
	std::string name;
	int level;
	int damage;
	int energy;
	Weapon* carryweapon;

public:
	Bot() {}
	Bot(std::string, int);
	int attack(Bot&);
	int wound(int);
	void heal(int);
	void levelUp();
	int const energyLeft();
	int const howDamaged();
	int const atLevel();
	std::string const called() { return name;	}
	std::string const carrying() { return carryweapon->name; }
};

#endif
