/* Main file with logic and blah blah blah...

   Look! Includes! */

#include <iostream>
#include <string>
#include <sstream>
#include "bot.hpp"
#include "node.hpp"
#include "easyrandom.hpp"

void look(Node room) {
	std::cout << "You're in a level " << room.level << " node." << std::endl;
	if (room.hasEnemy && !room.enemy.isDead()) {
		std::cout << "In the node with you is a " << room.enemy.called() <<
			std::endl << " carrying a " << room.enemy.carrying() << "." << std::endl;
	} else if (room.hasEnemy && room.enemy.isDead()) {
		std::cout << "A " << room.enemy.called() << " lies dead on the floor with a " <<
			std::endl << room.enemy.carrying() << " by it's side." << std::endl;

	}
	if (!room.hasEnemy || room.enemy.isDead()) {
		if (room.scrap && room.cells) {
			std::cout << "There are some cells and scrap lying on the floor." << std::endl;
		} else if (room.cells) {
			std::cout << "There are some cells lying on the floor." << std::endl;
		} else if (room.scrap) {
			std::cout << "There is some scrap lying on the floor." << std::endl;
		}
	}
	std::cout << "There are two pointers to higher left and right nodes." << std::endl;
}

void sayWat() {
	PRNGUniform<int> one {0, 3};
	std::string what[] {"You'll have to run that by me again.",
		"Say what now?",
		"I don't know what you're saying.",
		"I don't think so."};
	std::cout << what[one()] << std::endl;
}

void check(Bot actor) {
	std::cout << actor.called() << " is at level " << actor.atLevel() << "." << std::endl <<
		"It has " << actor.howDamaged() << " damage." << std::endl <<
		"Its power level is at " << actor.energyLeft() << "." << std::endl;
}

void clear() {
	for (int i = 50; i --> 0;)
		std::cout << std::endl;
}

int main() {
	PRNGUniform<int> percent {};
	std::string name, line;
	Node room {1};
	int nodeLevel = 1;
	clear();
	std::cout << "What do you want to call your robot?" << std::endl << std::endl << "> ";
	std::getline(std::cin, name);

	Bot player {name, 1, 20};

	clear();
	std::cout << "Your robot, " << name <<
		", drops into the root of a brave new world." << std::endl << std::endl << "> ";

	if (percent() < 10) {
		std::cout << "   ...and dies on impact." << std::endl;
		return 0;
	}

	while (!player.isDead() && player.hasEnergy() && getline(std::cin, line)) {
		std::istringstream sline {line};
		std::string word;

		clear();

		if (sline >> word) {
			if (word == "look") {
				look(room);
			} else if (word == "attack") {
				if (room.hasEnemy && !room.enemy.isDead()) {
					player.attack(room.enemy);
					if (room.enemy.isDead()) {
						std::cout << "The " << room.enemy.called() << " keels over from the damage." << std::endl;
						player.levelUp();
						std::cout << player.called() << " leveled up to level " << player.atLevel() << "." << std::endl;
					} else {
						if (percent() < player.atLevel()) {
							std::cout << "The " << room.enemy.called() << " is staggered and does not retaliate." << std::endl;
						} else {
							room.enemy.attack(player);
						}
					}
				} else if (room.hasEnemy) {
					std::cout << "The " << room.enemy.called() << " is dead." << std::endl;
				} else {
					std::cout << "There is nothing to attack..." << std::endl;
				}
			} else if (word == "take") {
				if (sline >> word) {
					if (word == "cells") {
						if (room.cells) {
							std::cout << "You took " << room.cells << " cells." << std::endl;
							room.cells = 0;
						} else {
							sayWat();
						}
					} else if (word == "scrap") {
						if (room.scrap) {
							player.heal(room.scrap);
							std::cout << "You repaired yourself to " << player.howDamaged() << " damage with the scrap." << std::endl;
							room.scrap = 0;
						} else {
							sayWat();
						}
					} else if (word == "weapon" && room.hasEnemy) {
						if (room.enemy.isDead()) {
							player.takeWeapon(room.enemy);
						} else {
							std::cout << "That's probably not a good idea while it's still up and about." << std::endl;
						}
					} else {
						sayWat();
					}
				} else {
					sayWat();
				}
			} else if (word == "go") {
				if (sline >> word) {
					if (word == "left" || word == "right") {
						if (!room.hasEnemy || room.enemy.isDead()) {
							std::cout << "You followed the " << word << " pointer." << std::endl;
							room = Node {++nodeLevel};
							player.drain(3);
						} else {
							std::cout << "There's a " << room.enemy.called() << " in the way." << std::endl;
						}
					} else if (word == "up") {
						std::cout << "Gravity says no." << std::endl;
					} else if (word == "down") {
						std::cout << "No." << std::endl;
					} else {
						sayWat();
					}
				} else {
					sayWat();
				}
			} else if (word == "check") {
				if (sline >> word) {
					if (word == "yourself") {
						std::cout << "...before you wreck yourself" << std::endl;
					} else if (word == "enemy") {
						if (room.hasEnemy) {
							check(room.enemy);
						} else {
							sayWat();
						}
					} else {
						sayWat();
					}
				} else {
					check(player);
				}
			} else {
				sayWat();
			}
		} // end word extract
		std::cout << std::endl << "> ";
	} // end while

	if (player.hasEnergy()) {
		std::cout << player.called() << " has taken too much damage and keels over." << std::endl;
	} else {
		std::cout << player.called() << " ran out of energy and shut down." << std::endl;
	}

} // end main
