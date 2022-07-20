#include "Point.h"


Point::Point() {
	this->m_x = 0;
	this->m_y = 0;
}

Point::Point(unsigned int x, unsigned int y) {
	this->m_x = x;
	this->m_y = y;
}

Point& Point::operator=(Point other) {
	this->m_x = other.m_x;
	this->m_y = other.m_y;
	return *this;
}

unsigned int Point::getX() {
	return this->m_x;
}

unsigned int Point::getY() {
	return this->m_y;
}

ostream& operator<<(ostream& os, const Point& pt) {
	os << "X:" << pt.m_x << "\nY: " << pt.m_y;
	return os;
}

istream& operator>>(istream& is, Point& pt) {
	is >> pt.m_x >> pt.m_y;
	return is;
}


