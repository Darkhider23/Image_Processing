#pragma once
#include "Image.h"
#include "Size.h"

class ImageProcessing
{
public:
	/**
	empty constructor
	*/
	ImageProcessing();
	/**
	default constructor
	*/
	ImageProcessing(Image img);

	Image getImage() const;

	virtual void process(const Image& src, Image& dst) {};

protected:
	Image m_image;	
};

