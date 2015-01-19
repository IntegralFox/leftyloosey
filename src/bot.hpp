#ifndef BOT_HEADER
#define BOT_HEADER

#include <string>
#include "weapon.hpp"

class Bot {
	int damage;
	int damageLimit;
	int energy;
	int level;
	std::string name;
	Weapon* carryweapon;

public:
	Bot() {}
	Bot(std::string, int);
	Bot(std::string, int, int);
	bool hasEnergy();
	bool isDead();
	int attack(Bot&);
	int const atLevel();
	int const energyLeft();
	int const howDamaged();
	int wound(int);
	std::string const called() { return name; }
	std::string const carrying() { return carryweapon->name; }
	void charge(int);
	void drain(int);
	void heal(int);
	void levelUp();
	void takeWeapon(Bot&);
};

#endif
