#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "Point.h"

using namespace std;



class Map
{
public:
	Map();
	Map(string file);
	unsigned int rows();
	unsigned int cols();
	vector<Point> jewls();
	void printMap();
	bool isValid(Point pos);
	int at(Point pos);

	~Map();

private:
	vector<vector<char>> vvMap;
	unsigned int rows;
	unsigned int cols;
	unsigned int jewls;
};

