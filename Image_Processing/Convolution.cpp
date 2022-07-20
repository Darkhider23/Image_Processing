#include "Convolution.h"
#include "Image.h"
ImageConvolution::ImageConvolution()
{
	Image a;
	this->Kernel = a;
}

ImageConvolution::ImageConvolution(Image img)
{
	this->Kernel = img;
}

void ImageConvolution::process(Image& src, Image& dst)
{
	
	for (unsigned int i = 0; i < src.height() - Kernel.height(); i++) {
		for (unsigned int j = 0; j < src.width() - Kernel.width(); j++) {
			for (int ii = 0; ii < Kernel.height(); ii++)
				for (int jj = 0; j < Kernel.width(); jj++)
					dst.at(i, j) = (unsigned char)((int)src.at(ii + i, jj + j) * Kernel.at(ii, jj));
		}
	}
}
