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
	

	// destructors
	~Point();


private:
	int x_val;
	int y_val;
};


class Box {
public:
	double getVolume(void) {
		return length * breadth * height;
	}
	void setLength(double len) {
		length = len;
	}
	void setBreadth(double bre) {
		breadth = bre;
	}
	void setHeight(double hei) {
		height = hei;
	}

	// Overload + operator to add two Box objects.
	Box operator+(const Box& b) {
		Box box;
		box.length = this->length + b.length;
		box.breadth = this->breadth + b.breadth;
		box.height = this->height + b.height;
		return box;
	}

private:
	double length;      // Length of a box
	double breadth;     // Breadth of a box
	double height;      // Height of a box
};

