#include "Map.h"



Map::Map()
{
}

Map::Map(string file)
{
	// setup
	std::ifstream infile(file);
	string sline;
	vector<char> vline;
	vector<vector<char> > vvMap;

	// import map
	while (std::getline(infile, sline))
	{
		vline.clear();
		for (unsigned int i = 0; i < sline.length(); i++) {
			vline.push_back(sline.at(i));
		}
		vvMap.push_back(vline);
	}


}


Map::~Map()
{
}
