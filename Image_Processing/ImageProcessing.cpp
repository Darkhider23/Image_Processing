#include "ImageProcessing.h"

ImageProcessing::ImageProcessing()
{
	 this->m_image = Image(Size{ 0,0 }); 
}

ImageProcessing::ImageProcessing(Image img)
{
	this->m_image = img;
}

Image ImageProcessing::getImage() const
{
	return this->m_image;
}
