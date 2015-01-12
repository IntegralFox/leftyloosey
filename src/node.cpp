#include <random>
#include "node.hpp"
#include "bot.hpp"
#include "enemytypes.hpp"

Node::Node(int level) {
	std::default_random_engine re {};
	std::uniform_int_distribution<int> random {0, 99};

	int enemyLevel = level - random(re) % 5;
	if (enemyLevel < 1) enemyLevel = 1;
	enemy = Bot {enemies[random(re) % numEnemies], enemyLevel};

	if (random(re) < 20) scrap = random(re) % 20;
	if (random(re) < 50) cells = random(re) % 15;
}
