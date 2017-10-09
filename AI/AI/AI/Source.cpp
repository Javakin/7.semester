/*
// this file is to solve the sokuban problem for artificial intellicgence
// created: 09-Oct-17
*/


#include <iostream>

#include <vector>
#include <fstream>
#include <string>

using namespace std;
int main() {
	// for detection of memory leaks 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// Import map
	std::ifstream infile("map.txt");
	string sline;
	vector< char > vline; 
	vector<vector< char > > vvMap;

	// import map
	while (std::getline(infile, sline))
	{
		vline.clear();
		for (unsigned int i = 0; i < sline.length(); i++) {
			vline.push_back(sline.at(i));
		}
		vvMap.push_back(vline);
	}


	



	// perform dijkstra


	// hold program before finishing
	system("pause");
	return 0;
}