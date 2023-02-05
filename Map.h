#pragma once

#include "Header.h"
using namespace std;


class Map
{
	// create map
public:
	Map(int width, int height) : width(width), height(height)
	{
		map = new char* [height];
		for (int i = 0; i < height; i++)
		{
			map[i] = new char[width];
			for (int j = 0; j < width; j++)
			{
				map[i][j] = '.';
			}
		}
	}

	// Add a destructor to free memory properly
	~Map()
	{
		for (int i = 0; i < height; i++)
		{
			delete[] map[i];
		}
		delete[] map;
	}

	void Draw(shared_ptr<Player> player, shared_ptr<Monster> monster)
	{
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				if (x == player->x && y == player->y)
				{
					cout << "P";
				}
				else if (x == monster->x && y == monster->y)
				{
					cout << "M";
				}
				else
				{
					cout << map[y][x];
				}
			}
			cout << endl;
		}
	}

	int width;
	int height;
	char** map;
};