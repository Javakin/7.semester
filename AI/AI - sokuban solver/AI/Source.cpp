/*
// this file is to solve the sokuban problem for artificial intellicgence
// created: 09-Oct-17
*/


#include <iostream>
#include "Map.h"
#include "Point.h"

#include <string>

using namespace std;


int main() {
	// for detection of memory leaks 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// Import map
	Map map("map.txt");
	map.printMap("Initial Map");
	
	map.playerMove(Point(2, 1));
	map.printMap("Moved Player");



	// perform dijkstra


	// hold program before finishing
	system("pause");
	return 0;
}