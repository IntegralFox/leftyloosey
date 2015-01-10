#include <string>
#include "weapontypes.hpp"

class Bot {
	std::string name;
	int damage;
	int energy;
	int level;
	Weapon_Type carrying;

public:
	Bot(std::string, int);
	int Attack(Bot);
	int Block();
	int Damage();
};
