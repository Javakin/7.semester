#pragma once

// includes
#include <string>
#include <vector>
#include <fstream>
#include "Point.h"
#include <iostream>

// defines 
#define WALL	'X'
#define FLOOR	'.'
#define JEWL	'J'
#define EMPTY	' '
#define GOAL	'G'
#define MAN		'M'


// namespaces
using namespace std;



class Map
{
public:
	//Map();
	Map(string file);
	unsigned int rows();
	unsigned int cols();
	vector<Point> jewls();
	void printMap(string message);
	bool isValid(Point pos);
	char at(Point pos);
	Point playerPos();
	bool playerMove(Point pos);

	~Map();

private:
	vector<vector<char>> vvMap;
	unsigned int uiRows;
	unsigned int uiCols;
	
};

