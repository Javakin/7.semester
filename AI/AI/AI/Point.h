#pragma once


class Point
{
public:
	Point();
	Point(int x, int y);

	// get functions
	int& x();
	int& y();
	

	// operator overloads +, -, +=, -=
	Point operator+  (Point p2);
	Point operator-  (Point p2);
	Point operator+= (int i);
	Point operator-= (int i);

	// destructors
	~Point();


private:
	int x_val;
	int y_val;
};



