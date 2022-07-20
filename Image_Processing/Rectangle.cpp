#include "Rectangle.h"
//#include "Point.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle() {
	this->m_length = 0;
	this->m_width = 0;
	this->m_pt = Point(0, 0);
}

Rectangle::Rectangle(Point pt, unsigned int len, unsigned int wid) {
	this->m_length = len;
	this->m_width = wid;
	this->m_pt = pt;
}

Rectangle::Rectangle(unsigned int x, unsigned int y, unsigned int len, unsigned int wid) {
	this->m_length = len;
	this->m_width = wid;
	this->m_pt = Point(x,y);
}

Rectangle::Rectangle(Point p1, Point p2) {
	this->m_pt = Point( min(p1.getX(), p2.getX()), max(p1.getY(), p2.getY()) );
	this->m_length = max(p1.getY(), p2.getY()) - min(p1.getY(), p2.getY());
	this->m_width = max(p1.getX(), p2.getX()) - min(p1.getX(), p2.getX());
}

Point Rectangle::getCoord() {
	return this->m_pt;
}

unsigned int Rectangle::getX() {
	return this->m_pt.getX();
}
unsigned int Rectangle::getY() {
	return this->m_pt.getY();
}
unsigned int Rectangle::getLen() {
	return this->m_length;
}
unsigned int Rectangle::getWid() {
	return this->m_width;
}

ostream& operator<<(ostream& os, Rectangle& rect) {
	os << "Rectangle with length " << rect.m_length << ", width " << rect.m_width << " and left corner coordinates: " << "\n\tX: " << rect.m_pt.getX() << "\n\tY: " << rect.m_pt.getY();
	return os;
}

istream& operator>>(istream& is, Rectangle& rect) {
	is >> rect.m_pt >> rect.m_length >> rect.m_width;
	return is;
}

Rectangle Rectangle::operator+(unsigned int v) {
	Point resultPoint = Point(this->m_pt.getX() + v, this->m_pt.getY() + v);
	Rectangle result(resultPoint, this->m_length, this->m_width);
	return result;
}

Rectangle Rectangle::operator-(int v) {
	int x = this->m_pt.getX();
	int y = this->m_pt.getY();
	if (x - v < 0 || y - v < 0) {
		throw "The coordinates must be positive";
	}
	else {
		Point resultPoint = Point(this->m_pt.getX() - v, this->m_pt.getY() - v);
		Rectangle result(resultPoint, this->m_length, this->m_width);
		return result;
	}
}

Rectangle& Rectangle::operator=(Rectangle other) {
	this->m_pt = other.m_pt;
	this->m_length = other.m_length;
	this->m_width = other.m_width;
	return *this;
}

Rectangle Rectangle::operator&(Rectangle other) {
	Rectangle result;
	int resultX, resultY;
	if (this->m_pt.getX() < other.m_pt.getX())
		if (this->m_pt.getX() + this->m_width >= other.m_pt.getX())
			resultX = other.m_pt.getX();
		else
			resultX = 0;
	else
		if (other.m_pt.getX() + other.m_width >= this->m_pt.getX())
			resultX = this->m_pt.getX();
		else
			resultX = 0;

	if (this->m_pt.getY() < other.m_pt.getY())
		if (this->m_pt.getY() + this->m_width >= other.m_pt.getY())
			resultY = other.m_pt.getY();
		else
			resultY = 0;
	else
		if (other.m_pt.getY() + other.m_width >= this->m_pt.getY())
			resultY = this->m_pt.getY();
		else
			resultY = 0;

	if (resultX == 0 || resultY == 0) {
		result.m_width = 0, result.m_length = 0;
		resultX = 0, resultY = 0;
	}
	else {
		result.m_width = min(this->m_pt.getX() + this->m_width, other.getX() + other.m_width) - resultX;
		result.m_length = min(this->m_pt.getY() + this->m_length, other.getY() + other.m_length) - resultY;
	}
	result.m_pt = Point(resultX, resultY);
	return result;
}

Rectangle Rectangle::operator|(Rectangle other) {
	Rectangle result;
	result.m_pt = Point(min(this->getX(), other.getX()), min(this->getY(), other.getY()));
	Point bl(max(this->getX() + this->m_width, other.getX() + other.m_width), max(this->getY() + this->m_length, other.getY() + other.m_length));
	result.m_length = bl.getY() - result.getY();
	result.m_width = bl.getX() - result.getX();
	return result;
}