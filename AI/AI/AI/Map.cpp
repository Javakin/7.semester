#include "Map.h"


/*Map::Map()
{
}*/

Map::Map(string file)
{
	// setup
	std::ifstream infile(file);
	string sline;
	vector<char> vline;

	// import map
	int i = 1;
	while (std::getline(infile, sline))
	{
		// grab the first line in the text file and extract it
		if (i) {
			i = 0;
			
			// konvertet fra string til int see: http://www.cplusplus.com/reference/string/stoi/
			std::string::size_type sz;   // alias of size_t
			uiCols = std::stoi(sline.substr(0, 2), &sz);
			uiRows = std::stoi(sline.substr(3, 2), &sz);			
		}
		else {
			// add the remaining position values to the vvMap variable 
			vline.clear();
			for (unsigned int i = 0; i < sline.length(); i++) {
				vline.push_back(sline.at(i));
			}
			vvMap.push_back(vline);
		}		
	}
}

unsigned int Map::rows()
{
	return uiRows;
}

unsigned int Map::cols()
{
	return uiCols;
}

vector<Point> Map::jewls()
{
	// initial setup
	vector<Point> vpJewls;

	for (unsigned int i = 0; i < uiRows; i++) {
		for (unsigned int j = 0; j < uiCols; j++) {
			if (vvMap[i][j] == JEWL)
				vpJewls.push_back(Point(i, j));
		}
	}

	return vpJewls;
}

void Map::printMap(string message)
{
	cout << "\n----------------" << message << "----------------\n";
	for (unsigned int i = 0; i < uiRows; i++) {
		for (unsigned int j = 0; j < uiCols; j++) {
			cout << vvMap[i][j];
		}
		cout << endl;
	}
}

bool Map::isValid(Point pos)
{
	// is the field a floor peace 
	if (at(pos) == FLOOR)
		return true;
	return false;
}

char Map::at(Point pos)
{
	if (pos.x() <uiCols && pos.x() >=0 && pos.y() <uiRows && pos.y() >= 0)
		return vvMap[pos.x()][pos.y()];

	return EMPTY;
}

Point Map::playerPos()
{
	// setup
	Point pMan(-1,-1);

	// search for the man
	for (unsigned int i = 0; i < uiRows; i++) {
		for (unsigned int j = 0; j < uiCols; j++) {
			if (vvMap[i][j] == MAN) {
				pMan = Point(i, j);
			}
		}
	}

	return pMan;
}

bool Map::playerMove(Point pos)
{
	// if pos is of type floor, player will be moved
	if (isValid(pos)) {
		Point p = playerPos();
		vvMap[p.x()][p.y()] = FLOOR;
		vvMap[pos.x()][pos.y()] = MAN;
		return true;
	}

	return false;
}


Map::~Map()
{
}
