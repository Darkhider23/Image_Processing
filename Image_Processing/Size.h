#pragma once
#include <string>
#include <iostream>

using namespace std;

class Size
{
public:
	Size();
	Size(unsigned int height, unsigned int width);

	unsigned int getHeight() const;
	unsigned int getWidth() const;

	friend std::ostream& operator<<(std::ostream& os, const Size& size);

	bool operator!=(Size s2);
	bool operator==(Size s) const;
	Size& operator=(const Size s);

private:
	unsigned int m_width;
	unsigned int m_height;
};

