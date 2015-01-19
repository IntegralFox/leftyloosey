#include <iostream>
#include "easyrandom.hpp"
#include "bot.hpp"
#include "weapontypes.hpp"

Bot::Bot(std::string name, int level, int damageLimit) : damage {0}, energy {100}, level {level}, name {name} {
	PRNGNormal<double> weaponVariance {0, 1};
	PRNGUniform<int> damageVariance {1, level};
	int weaponChoice = level/4 + weaponVariance();
	if (weaponChoice < 0) weaponChoice = 0;
	if (weaponChoice >= numWeapons) weaponChoice = numWeapons - 1;
	carryweapon = weapons[weaponChoice];
	this->damageLimit = damageLimit + damageVariance();
}

Bot::Bot(std::string name, int level) : Bot(name, level, level + 1) {}

int Bot::attack(Bot& victim) {
	int dealDamage = carryweapon->damage;
	if (energy >= carryweapon->energy) {
		energy -= carryweapon->energy;
		dealDamage += level / 5;
	} else {
		dealDamage /= 2;
	}
	std::cout << called() << " deals " << dealDamage << " damage to " << victim.called() <<
		std::endl << "using its " << carrying() << "." << std::endl;
	energy -= carryweapon->energy;
	return victim.wound(dealDamage);
}

int Bot::wound(int amount) {
	std::default_random_engine re {};
	std::uniform_int_distribution<int> variedBlock {level/10, carryweapon->block};
	int mitigation = variedBlock(re);

	std::cout << mitigation << " damage is blocked by its " << carrying() << "." << std::endl;
	damage += amount  - mitigation;
	return amount - mitigation;
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

bool Bot::isDead() {
	return damage >= damageLimit;
}

void Bot::takeWeapon(Bot& victim) {
	carryweapon = victim.carryweapon;
	std::cout << "You took the " << victim.called() << "'s " << victim.carrying() << "." << std::endl;
}

bool Bot::hasEnergy() {
	return energy > 0;
}

void Bot::drain(int amount) {
	energy -= amount;
	if (energy < 0) energy = 0;
}

void Bot::charge(int amount) {
	energy += amount;
	if (energy > 100) energy = 100;
}

// If find the lack of comments...   disturbing...
