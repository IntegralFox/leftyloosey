#include "easyrandom.hpp"
#include "bot.hpp"
#include "weapontypes.hpp"

Bot::Bot(std::string name, int level) : name {name}, level {level}, damage {0}, energy {100} {
	PRNGNormal<double> weaponVariance {0, 1};
	int weaponChoice = level/4 + weaponVariance();
	if (weaponChoice < 0) weaponChoice = 0;
	if (weaponChoice >= numWeapons) weaponChoice = numWeapons - 1;
	carryweapon = weapons[weaponChoice];
}

int Bot::attack(Bot& victim) {
	int dealDamage = carryweapon->damage;
	if (energy >= carryweapon->energy) {
		energy -= carryweapon->energy;
		dealDamage += level / 5;
	} else {
		dealDamage /= 2;
	}
	energy -= carryweapon->energy;
	return victim.wound(dealDamage);
}

int Bot::wound(int amount) {
	std::default_random_engine re {};
	std::uniform_int_distribution<int> variedBlock {level/10, carryweapon->block};

	damage += amount - variedBlock(re);
	return amount - carryweapon->block;
}

void Bot::levelUp() {
	++level;
}

void Bot::heal(int amount) {
	damage -= amount;
	if (damage < 0) damage = 0;
}

int const Bot::energyLeft() {
	return energy;
}

int const Bot::howDamaged() {
	return damage;
}

int const Bot::atLevel() {
	return level;
}
