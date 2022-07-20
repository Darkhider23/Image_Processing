#pragma once
#include "Size.h"
#include <string>
#include "Point.h"
#include "Rectangle.h"

class Image
{
public:
	/**
	*empty constructor
	*/
	Image();

	/**
	*default constructor
	*/
	Image(Size size);

	/**
	copy constructor
	*/
	Image(const Image& other);

	/**
	destructor
	*/
	~Image();

	Size getSize() const { return this->m_size; }

	/**
	read and save image
	imagePath is a string representing the path to the image folder
	*/
	bool load(std::string imagePath); 
	bool save(std::string imagePath); 

	/**
	assignment operator
	*/
	Image& operator=(const Image& other); 

	/**
	+ operator from image to image
	*/
	Image operator+(const Image& i);

	/**
	- operator from image to image
	*/
	Image operator-(const Image& i); 

	/**
	* operator from image to image
	*/
	Image operator*(const Image& i); 

	/**
	+ operator
	*/
	Image operator+(const int val); 
	/**
	- operator
	*/
	Image operator-(const float val); 
	/**
	* operator
	*/
	Image operator*(const float val); 

	bool operator==(const Image& other); 

	bool operator!=(const Image& other); 

	/**, a region of interest (ROI) is a portion of 
	the image that you want to apply to filter or apply
	some operation on
	*/
	bool getROI(Image& roiImg, Rectangle roiRect);
	bool getROI(Image& roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height);
	
	/**
	check if m_data is empty
	*/
	bool isEmpty() const; 
	
	/**
	getter for width of the image
	*/
	unsigned int width() const { return this->m_size.getWidth(); }

	/**
	getter for height of the image
	*/
	unsigned int height() const { return this->m_size.getHeight(); }
	
	/**
	a refference to a point in the image
	*/
	unsigned char& at(unsigned int x, unsigned int y);
	unsigned char& at(Point pt);
	
	/**
	refference to a row from the image
	*/
	unsigned char* row(int y);
	
	/**
	procedure to release the memory used
	*/
	void release();
	
	/**
	overload for the stream insertion operator: operator<<
	*/
	friend std::ostream& operator<<(std::ostream& os, const Image& dt);

	/**
	generate a image full of zeros
	*/
	static Image zeros(unsigned int width, unsigned int height) {
		Image img(Size(height, width));
		return img;
	}

	/**
	generate a image full of ones
	*/
	static Image ones(unsigned int width, unsigned int height) {
		Image img(Size(height, width));
		img = img + 1;
		return img;
	}

private:
	unsigned char** m_data;
	Size m_size;
};

