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
	if (room.hasEnemy && room.enemy.howDamaged() < 100) {
		std::cout << "In the node with you is a " << room.enemy.called() <<
			" carrying a " << room.enemy.carrying() << "." << std::endl;
		std::cout << "There are pointers to higher left and right nodes that "
			"you might be able to get to if you run fast enough." << std::endl;
	} else {
		std::cout << "There are two pointers to higher left and right nodes."
			<< std::endl;
	}
	if (!room.hasEnemy || room.enemy.howDamaged() > 99) {
		if (room.scrap && !room.cells) {
			std::cout << "There is some scrap lying on the floor." << std::endl;
		} else if (!room.scrap && room.cells) {
			std::cout << "There are some cells lying on the floor."
				<< std::endl;
		} else {
			std::cout << "There are some cells and scrap lying on the floor."
				<< std::endl;
		}
	}
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
		"It's power level is at " << actor.energyLeft() << "." << std::endl;
}

int main() {
	PRNGUniform<int> percent {};
	std::string name, line;
	Node room {1};
	std::cout << "What do you want to call your robot?" << std::endl;
	std::getline(std::cin, name);

	Bot player {name, 1};

	std::cout << "\n\nYour robot, " << name <<
		", drops into the root of a brave new world." << std::endl;

	if (percent() < 10) {
		std::cout << "   ...and dies on impact." << std::endl;
		return 0;
	}

	while (player.howDamaged() < 100 && getline(std::cin, line)) {
		std::istringstream sline {line};
		std::string word;
		if (sline >> word) {
			if (word == "look") {
				look(room);
			} else if (word == "attack") {
				if (room.hasEnemy && room.enemy.howDamaged() < 100)
					player.attack(room.enemy);
				else if (room.hasEnemy) {
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
					} else {
						sayWat();
					}
				} else {
					sayWat();
				}
			} else if (word == "go") {
				if (sline >> word) {
					if (word == "left" || word == "right") {
						if (!room.hasEnemy || room.enemy.howDamaged() > 99) {
							room = Node {player.atLevel()};
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
		}
	}
}
