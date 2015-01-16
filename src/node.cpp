#include "node.hpp"
#include "bot.hpp"
#include "enemytypes.hpp"
#include "easyrandom.hpp"

Node::Node(int level) : level {level} {
	PRNGUniform<int> percent {};
	int enemyLevel = level - percent() % 5;
	if (enemyLevel < 1) enemyLevel = 1;
	enemy = Bot {enemies[percent() % numEnemies], enemyLevel};
	hasEnemy = percent() < 50;

	scrap = (percent() < 20) ? (percent() % 20) : 0;
	cells = (percent() < 50) ? (percent() % 15) : 0;
}
