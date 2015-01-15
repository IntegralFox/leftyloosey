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
	int energyLeft();
	int howDamaged();
	int atLevel();
	std::string called() { return name;	}
	std::string carrying() { return carryweapon->name; }
};

#endif
