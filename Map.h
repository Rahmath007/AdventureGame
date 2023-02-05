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