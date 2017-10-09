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





Point Point::operator+(Point p2)
{
	Point res;
	res.x() = x_val + p2.x();
	res.y() = y_val + p2.y();
	return res;
}

Point Point::operator-(Point p2)
{
	Point res;
	res.x() = x_val - p2.x();
	res.y() = y_val - p2.y();
	return res;
}

Point Point::operator+=(int i)
{
	Point res;
	res.x() = x_val + i;
	res.y() = y_val + i;
	return res;
}

Point Point::operator-=(int i)
{
	Point res;
	res.x() = x_val - i;
	res.y() = y_val - i;
	return res;
}

Point::~Point()
{
}
