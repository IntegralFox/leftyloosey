#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include "bot.hpp"
#include "node.hpp"

int main() {
	std::string name, line;
	Node currentNode {1};
	std::cout << "What do you want to call your robot?" << std::endl;
	std::getline(std::cin, name);

	Bot player {name, 1};

	std::cout << "Your robot, " << name << ", drops into the root of a brave new world." << std::endl;

	while (player.howDamaged() < 100 && getline(std::cin, line)) {
		std::ostringstream sline {line};
	}
}
