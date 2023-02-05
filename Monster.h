#pragma once


using namespace std;


class Monster : public Entity
{
public:
	Monster(int x, int y) : Entity(x, y), health(50), attack(15), defense(5) {}

	int health;
	int attack;
	int defense;
};

