#pragma once
#include "Point.h"
#include <ostream>
#include <istream>
#include <math.h>

using namespace std;

class Rectangle
{
public:
	Rectangle();
	Rectangle(Point, unsigned int, unsigned int);
	Rectangle(unsigned int, unsigned int, unsigned int, unsigned int);
	Rectangle(Point, Point);

	Point getCoord();
	unsigned int getX();
	unsigned int getY();
	unsigned int getLen();
	unsigned int getWid();

	friend ostream& operator<<(ostream& os, Rectangle& pt);
	friend istream& operator>>(istream& is, Rectangle& pt);


	Rectangle operator+(unsigned int);
	Rectangle operator-(int);
	Rectangle operator&(Rectangle other);
	Rectangle operator|(Rectangle other);
	Rectangle& operator=(Rectangle other);

private:
	Point m_pt;
	unsigned int m_length, m_width;

};

