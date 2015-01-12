#ifndef NODE_HEADER
#define NODE_HEADER

#include "bot.hpp"

class Node {
public:
	bool hasEnemy;
	Bot enemy;
	int scrap;
	int cells;

	Node(int);
};

#endif
