#include "Point.h"



Point::Point()
{
}

Point::Point(int x, int y)
{
	x_val = x;
	y_val = y;
}

int& Point::x()
{
	return x_val;
}


int& Point::y()
{
	return y_val;
}





Point::~Point()
{
}
