#include "Size.h"
#include <iostream>

using namespace std;

std::ostream& operator<<(std::ostream& os, const Size& size) {
	os << "Heigth: " << size.m_height << "\n" << "Width: " << size.m_width << "\n";

	return os;
}

Size::Size()
{
	m_height = 0, m_width = 0;
}

Size::Size(unsigned int height, unsigned int width)
{
	m_height = height, m_width = width;
}

unsigned int Size::getHeight() const
{
	return m_height;
}

unsigned int Size::getWidth() const
{
	return m_width;
}

bool Size::operator!=(Size s) {
	if (this->m_height == s.m_height)
		if (this->m_width == s.m_width)
			return false;
	return true;
}

bool Size::operator==(Size s) const {
	if (this->m_height == s.m_height)
		if (this->m_width == s.m_width)
			return true;
	return false;
}

Size& Size::operator=(const Size s) {
	this->m_height = s.m_height;
	this->m_width = s.m_width;
	return *this;
}