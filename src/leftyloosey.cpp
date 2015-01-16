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

int main() {
	PRNGUniform<int> percent {};
	std::string name, line;
	Node currentNode {1};
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
		std::ostringstream sline {line};
	}
}
