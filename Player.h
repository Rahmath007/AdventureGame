#pragma once

#include "Header.h"
using namespace std;

class Player : public Entity
{
public:
	Player(int x, int y) : Entity(x, y), health(100), attack(20), defense(10) {}

	int health;
	int attack;
	int defense;
	int gold = 0;
	int experience = 0;
};
