#include <iostream>
#include <string>
#include "bot.hpp"

int main() {
	std::cout << "What do you want to call your robot?" << std::endl;
	std::string name;
	std::getline(std::cin, name);

	Bot player {name, 1};

	std::cout << "Your robot, " << name << ", drops into the root of a brave new world." << std::endl;
}
