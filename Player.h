#pragma once

using namespace std;

class Player {
public:
	Player(int x, int y), health(100), attack(20), defense(10) {}

	int health;
	int attack;
	int defence;
	int gold = 0;
	int experirnce = 0;
};
