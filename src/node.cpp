#include <random>
#include "node.hpp"
#include "bot.hpp"
#include "enemytypes.hpp"

Node::Node(int level) : level {level} {
	std::default_random_engine re {};
	std::uniform_int_distribution<int> random {0, 99};

	int enemyLevel = level - random(re) % 5;
	if (enemyLevel < 1) enemyLevel = 1;
	enemy = Bot {enemies[random(re) % numEnemies], enemyLevel};
	hasEnemy = random(re) < 50;

	scrap = (random(re) < 20) ? (random(re) % 20) : 0;
	cells = (random(re) < 50) ? (random(re) % 15) : 0;
}
