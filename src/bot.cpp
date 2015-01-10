#include "bot.hpp"

Bot::Bot(std::string name, int level) : name(name), level(level) {}

int Bot::attack(Bot& victim) {
	energy -= carriedWeapon->energy;
	return victim.damageWith(carriedWeapon);
}

int Bot::damageWith(Weapon* hitWith) {
	damage += hitWith->damage - carriedWeapon->block;
	return hitWith->damage - carriedWeapon->block;
}
