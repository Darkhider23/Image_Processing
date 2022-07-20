#pragma once

#include <ostream>
#include <istream>

using namespace std;

class Point
{

public:
	/**
	empty constructor
	*/
	Point();
	/**
	default constructor
	*/
	Point(unsigned int, unsigned int);

	/**
	getters for x and y for a point
	*/
	unsigned int getX();
	unsigned int getY();

	/**
	asigment operator
	*/
	Point& operator=(Point);

	/**
	operator for << and >>
	*/
	friend ostream& operator<<(ostream& os, const Point& pt);
	friend istream& operator>>(istream& is, Point& pt);

private:
	unsigned int m_x, m_y;
};

