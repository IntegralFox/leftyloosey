#include <string>
#include "weapontypes.hpp"

class Bot {
	std::string name;
	int damage;
	int energy;
	int level;
	Weapon* carriedWeapon;

public:
	Bot(std::string, int);
	int attack(Bot&);
	int damageWith(Weapon*);
};
